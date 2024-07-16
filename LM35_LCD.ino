#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int sensPin = A0;
float temp;
float voltage;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensvalue = analogRead(A0);
  float voltage = sensvalue * (5.0/1023.0);
  //lcd.print(voltage);
  //delay(1000);
  float temp = voltage*100;
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(temp);
  lcd.print(" ");
  delay(1000);
}
