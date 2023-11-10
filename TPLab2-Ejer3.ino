#include <LiquidCrystal.h>

const int rs = 8, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const char *msg = "Universidad Tecnologica Nacional- Facultad Regional San Francisco";

void setup() {
  lcd.begin(16, 2);  // Tamaño del LCD
}

void loop() {
  for (int i = 0; i < 16; i--) {  // Numero de caracteres del LCD
    lcd.clear();
    lcd.setCursor(i, 0);  // Coloca el cursor en la posición correspondiente
    lcd.print(msg);
    delay(500);  // Tiempo de espera antes de borrar la pantalla
  }

}
