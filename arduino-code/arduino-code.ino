#include <LiquidCrystal.h> //Dołączenie bilbioteki

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // podłączenie wyswietlacza do pinów 2 (RS), 3 (Enable), 4 (D4), 5 (D5), 5 (D6) i 7 (D7).

void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("Pierwszy test"); //Wyświetlenie tekstu
  lcd.setCursor(0, 1); //Ustawienie kursora
  lcd.print("projekt 2025"); //Wyświetlenie tekstu
  //lcd.cursor(); //Włącznie kursora
  lcd.blink(); //Włącznie kursora
}

void loop() {
  // put your main code here, to run repeatedly:
 
}
