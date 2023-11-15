#include <LiquidCrystal.h>
#include <math.h>
#define sensor A0
const int rs = 8, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int c_a = 0, c_b = 0, c_c = 0;
float raiz = 0, x1 = 0, x2 = 0, aux = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Ingrese a: ");
  while (Serial.available() == 0);
  c_a = Serial.parseInt();
  Serial.println(c_a);
  aux = Serial.parseFloat();

  lcd.setCursor(0, 0);
  lcd.print("Ingrese b: ");
  while (Serial.available() == 0);
  c_b = Serial.parseInt();
  Serial.println(c_b);
  aux = Serial.parseFloat();

  lcd.setCursor(0, 0);
  lcd.print("Ingrese c: ");
  while (Serial.available() == 0);
  c_c = Serial.parseInt();
  Serial.println(c_c);
  while (Serial.available() == 0);
  aux = Serial.parseFloat();


  raiz = c_b * c_b - 4 * c_a * c_c;
  if (raiz >= 0) {  //si es mayor igual que 0, haga la operacoion de x1 y x2
    x1 = ((-1 * c_b) + sqrt(raiz)) / (2 * c_a);
    x2 = ((-1 * c_b) - sqrt(raiz)) / (2 * c_a);

    Serial.println("Las raices son:");
    Serial.print("x1:");
    Serial.println(x1);
    Serial.print("x2:");
    Serial.println(x2);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("x1: ");
    lcd.print(x1);
    lcd.setCursor(0, 1);
    lcd.print("x2: ");
    lcd.print(x2);

  } else if (raiz < 0) {  //si es menor, diga error
    lcd.setCursor(0, 0);
    lcd.print("Error");
  }
  while (true) {}
}
