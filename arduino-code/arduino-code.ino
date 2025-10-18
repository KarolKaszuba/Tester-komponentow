#include <LiquidCrystal.h>
#include <OneButton.h>

//def pinów dla przyciskow 
#define P1_RESISTOR   8
#define P2_DIODE      9
#define P3_TRANSISTOR 10

// def trybów dla lepszej czytelnosci kodu
#define MODE_MENU       0
#define MODE_RESISTOR   1
#define MODE_DIODE      2
#define MODE_TRANSISTOR 3

// def potrzebne do obliczania rezystancji
#define PIN_RES     A0      // Pin pomiarowy
#define R1          10000.0 // Rezystancja R1
#define U           5.0     // Napiecie U

// do testowania diody
#define TEST_DIODE_5V   11 //pin podający napięcie 
#define PIN_DIODE       A1 //pin pomiarowy do diody
 
//deklaracja funkcji
void startInfo();
void startInfo();
void handleClick();
void handleDoubleClick();
void handleButtons();
void getResistanceStr();
void testDiode();

//time delay
unsigned long prevTime{0};
//const unsigned long interval{200}; //1000 milisekund

OneButton P1_res = OneButton(P1_RESISTOR, true); // true bo aktuwuje gdy LOW
int lastState2 = HIGH; // bo pullup | chce łapać zbocze rosnące
int lastState3 = HIGH; // bo pullup | chce łapać zbocze rosnące

int currentMode = MODE_MENU;
bool inResMode = false;


LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // podłączenie wyswietlacza do pinów 2 (RS), 3 (Enable), 4 (D4), 5 (D5), 5 (D6) i 7 (D7).

void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2); //Deklaracja typu
  startInfo();

  pinMode(P1_RESISTOR , INPUT_PULLUP); //Przycisk jako wejście
  pinMode(P2_DIODE , INPUT_PULLUP);
  pinMode(P3_TRANSISTOR , INPUT_PULLUP);

  pinMode(TEST_DIODE_5V, OUTPUT); //pin podający napięcie do testu diody
  digitalWrite(TEST_DIODE_5V, LOW); //LOW zeby mieć pewność ze nie ma napiecia

  P1_res.attachClick(handleClick);
  P1_res.attachDoubleClick(handleDoubleClick);
}

void loop() {
  unsigned long now = millis();

  P1_res.tick();
  handleButtons();


  switch(currentMode){
    case MODE_MENU:
      break;

    case MODE_RESISTOR:
      if ( now - prevTime >= 300){
        prevTime = now;

        getResistanceStr();
      }
      break;

    case MODE_DIODE:
      if ( now - prevTime >= 300){
        prevTime = now;

        testDiode();
        
      }
      break;
    case MODE_TRANSISTOR:

      if ( now - prevTime >= 300){
        prevTime = now;

        digitalWrite ( TEST_DIODE_5V, LOW);
        lcd.clear();
        lcd.print("zaraz zmierze T");
        
      }
      
      break;


  }
  delay(50);
}

void testDiode(){
  digitalWrite( TEST_DIODE_5V, HIGH);
  delay(20); // dla stabilizacji

  double voltageD = (analogRead(PIN_DIODE) * 5.0) / 1023.0; 

  // Serial.println(analogRead(PIN_DIODE));
  // //digitalWrite ( TEST_DIODE_5V, LOW);
  // Serial.println(voltageD);

  lcd.clear();
  
  if ( voltageD > 0.2 and voltageD < 0.3 ){
    lcd.print(" German Diode");
  }
  else if ( voltageD > 0.5 and voltageD < 0.8 ){
    lcd.print(" Silicon Diode");
  }
  else if (voltageD > 1.6 and voltageD < 3.3){

    lcd.print(" LED Diode");
  }
  else if (voltageD > 4.5){

    lcd.print("  OL ");
  }
  else{
    lcd.print(" damaged or ");
    lcd.setCursor(1,1);
    lcd.print("no diode ");
  }

  lcd.setCursor(10,1);
  lcd.print("V "+ String(voltageD));

}


void getResistanceStr(){



    int iterations = 10; // będzie liczyć średnią z 10 pomiarów 
    double sumOfR2{0.0};


    for (int k = 0; k < iterations; k++){

        // Serial.print(": Odczyt ADC = ");
        Serial.println(analogRead(PIN_RES));

        if( analogRead(PIN_RES) == 0){
          continue;
        }
          double u1 = U * (analogRead(PIN_RES)/1023.0);
          sumOfR2 += (U*R1/u1) - R1;
          //sumOfR2 += R1 * ((U - u1) / u1);
  }

  double R2 = sumOfR2 / iterations;
  String resultS;

  if (analogRead(PIN_RES) >= 1021){
    resultS = " OL ";   //nic nie podpiete
  }
  if (R2 < 1000.0 and R2 >= 0.0){
    resultS = String(R2) + " Ohm";
  }
  else if(R2 < 1000000.0 and R2 >= 1000.0){
    resultS = String(R2 / 1000.0) + " kOhm";
  }
  else if(R2 < 1000000000.0 and R2 >= 1000000.0){
    resultS = String(R2 / 1000000.0) + " MOhm";
  }
  else resultS = ">1Gohm or OL";

  lcd.setCursor(3,1);
  lcd.print( resultS );

}

void handleButtons(){

  int currentState2 = digitalRead(P2_DIODE);
  int currentState3 = digitalRead(P3_TRANSISTOR);


  
  if(lastState2 == LOW and currentState2 == HIGH){
    inResMode = false;

    lcd.clear();
    lcd.print("DIODE MODE");
    currentMode = MODE_DIODE;
    delay(500);
  }
  
  if(lastState3 == LOW and currentState3 == HIGH){
    inResMode = false;

    lcd.clear();
    lcd.print("TRANSISTOR MODE");
    currentMode = MODE_TRANSISTOR;
    delay(500);
  }

  lastState2 = currentState2;
  lastState3 = currentState3;
}

void startInfo(){
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("test a component"); //Wyświetlenie tekstu
  lcd.setCursor(0, 1); //Ustawienie kursora
  lcd.print("choose 1r-2d-3t"); //Wyświetlenie tekstu
  //delay(50);

  //lcd.cursor(); //Włącznie kursora
  //lcd.blink(); //Włącznie kursora
  //lcd.clear();
}

void handleClick(){

  digitalWrite ( TEST_DIODE_5V, LOW);
  currentMode = MODE_RESISTOR;

// gdy program jest juz w trybie to nie wyswietla ciagle inf o trybie
  if ( !inResMode ){ 
    lcd.clear();
    lcd.print("RESISTOR MODE");
    delay(500);
    inResMode = true;
  }
  
  lcd.clear();
  lcd.print("Estiamted Ohms:");
  lcd.setCursor(0,1);
  lcd.print("-> ");

}

void handleDoubleClick(){
  digitalWrite ( TEST_DIODE_5V, LOW);    
  currentMode = MODE_MENU;
  inResMode = false;
  startInfo();
}
