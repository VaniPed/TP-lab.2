#include <LiquidCrystal.h>
#define p1 9
#define p2 10

const int rs = 8, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float reloj;
float contador;
int min;
int hora;
bool iniciar = 0;
void setup() {
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  lcd.begin(16, 2);
  
}

void loop() {
  if (digitalRead(p1)) {
    delay(400);
    iniciar = 1;
    reloj = millis();
  }
  if (digitalRead(p2)) {
    delay(400);
    iniciar = 0;
  }
  if (iniciar == 1) {
    contador = (millis() - reloj) / 1000;
  }
  if (contador >= 60) {
    reloj = millis();    
    min++;
    contador = 0;
  }
  if (min >= 60) {
    hora++;
    min = 0;
  }
  lcd.setCursor(1, 0);
  lcd.print(hora);
  lcd.print(":");
  lcd.print(min);
  lcd.print(":");
  lcd.print(contador);
  lcd.print("     ");  
  delay(10);
}