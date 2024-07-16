#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <DHT.h>
int dhtPin=2;
#define Type DHT11
DHT sensor(dhtPin,Type);
float humidity;
float tempC;
float tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sensor.begin();
  delay(500);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity=sensor.readHumidity();
  tempC=sensor.readTemperature();
  tempF=sensor.readTemperature(true);
  Serial.print("Humidity :- ");
  Serial.print(humidity);
  Serial.println(" g/m^3");
  Serial.print("Temperature :- ");
  Serial.print(tempC);
  Serial.println(" C");
  Serial.print("Temperature :- ");
  Serial.print(tempF);
  Serial.println(" F");
  delay(500);
  lcd.setCursor(0,0);
  lcd.printstr("Humidity");
  lcd.setCursor(0,1);
  lcd.print(humidity);
  lcd.print(" g/cm^3");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.printstr("Temperature in C");
  lcd.setCursor(0,1);
  lcd.print(tempC);
  lcd.printstr(" *C");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.printstr("Temperature in F");
  lcd.setCursor(0,1);
  lcd.print(tempF);
  lcd.printstr(" *F");
  delay(2000);
  lcd.clear();
  
}
