#include <math.h>
#include <LiquidCrystal.h>

const int rs = 8, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float x = 0, y = 0, modulo = 0, tita = 0, aux;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ingrese modulo:");
  lcd.setCursor(0, 1);
  lcd.print("Ingrese angulo:");
}
void loop() {
  while (Serial.available() == 0) {}
  modulo = Serial.parseFloat();
  Serial.println(modulo);
  aux = Serial.parseFloat();

  while (Serial.available() == 0) {}
  tita = Serial.parseFloat();
  Serial.println(tita);
  aux = Serial.parseFloat();

  x = (modulo) * cos(tita);
  y = (modulo) * sin(tita);
  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("x: ");
  lcd.print(x);
  lcd.setCursor(0, 1);
    lcd.print("y: ");
  lcd.print(y);

}
