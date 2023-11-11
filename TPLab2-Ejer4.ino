#include <math.h>
#include <LiquidCrystal.h>

const int rs = 8, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
double x = 0, y = 0, modulo = 0, tita = 0, aux;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ingrese X:");
  lcd.setCursor(0, 1);
  lcd.print("Ingrese Y:");
}
void loop() {
  while (Serial.available() == 0) {}
  x = Serial.parseFloat();
  Serial.println(x);
  aux = Serial.parseFloat();

  while (Serial.available() == 0) {}
  y = Serial.parseFloat();
  Serial.println(y);
  aux = Serial.parseFloat();

  modulo = sqrt(pow(x, 2) + pow(y, 2));
  tita = atan(y / (x));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(modulo);
  lcd.setCursor(0, 1);
  lcd.print(tita);
  lcd.print(" rad");
}
