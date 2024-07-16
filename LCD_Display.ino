#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("S");
  lcd.print("N");
  lcd.print("E");
  lcd.print("H");
  lcd.print(" ");
  lcd.print("S");
  lcd.print("H");
  lcd.print("A");
  lcd.print("H");

}

void loop() {
  // put your main code here, to run repeatedly:
}
