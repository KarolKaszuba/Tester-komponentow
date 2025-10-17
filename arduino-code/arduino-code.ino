#include <LiquidCrystal.h>
#include <OneButton.h>

#define P1_RESISTOR 8
#define P2_DIODE 9
#define P3_TRANSISTOR 10


void startInfo();
void cleanAndSetDisp();
void startInfo();
void handleClick();
void handleDoubleClick();

OneButton P1_res = OneButton(P1_RESISTOR, true); // true bo aktuwuje gdy LOW
int lastState2 = HIGH; // bo pullup | chce łapać zbocze rosnące
int lastState3 = HIGH; // bo pullup | chce łapać zbocze rosnące


LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // podłączenie wyswietlacza do pinów 2 (RS), 3 (Enable), 4 (D4), 5 (D5), 5 (D6) i 7 (D7).

void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  startInfo();
  pinMode(P1_RESISTOR , INPUT_PULLUP); //Przycisk jako wejście
  pinMode(P2_DIODE , INPUT_PULLUP);
  pinMode(P3_TRANSISTOR , INPUT_PULLUP);

  P1_res.attachClick(handleClick);
  P1_res.attachDoubleClick(handleDoubleClick);
}

void loop() {

  P1_res.tick();

  int currentState2 = digitalRead(P2_DIODE);
  int currentState3 = digitalRead(P3_TRANSISTOR);


  
  if(lastState2 == LOW and currentState2 == HIGH){
    cleanAndSetDisp();
    lcd.print("DIODE MODE");
    delay(500);
  }
  
  if(lastState3 == LOW and currentState3 == HIGH){
    cleanAndSetDisp();
    lcd.print("TRANSISTOR MODE");
    delay(500);
  }

  lastState2 = currentState2;
  lastState3 = currentState3;
  delay(50);
}






void cleanAndSetDisp(){
  lcd.clear();
  lcd.setCursor(0,0);
}

void startInfo(){
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("test a component"); //Wyświetlenie tekstu
  lcd.setCursor(0, 1); //Ustawienie kursora
  lcd.print("choose 1r-2d-3t"); //Wyświetlenie tekstu
  delay(1000);

  //lcd.cursor(); //Włącznie kursora
  //lcd.blink(); //Włącznie kursora
  //lcd.clear();
}

void handleClick(){
  cleanAndSetDisp();
  lcd.print("RESISTOR MODE");
  delay(500);
}

void handleDoubleClick(){
  startInfo();
  delay(500);
}
