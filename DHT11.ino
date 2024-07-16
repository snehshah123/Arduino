#include <DHT.h>
int dhtPin=2;
#define Type DHT11
DHT sensor(dhtPin,Type);
float humidity;
float tempC;
float tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor.begin();
  delay(500);
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
}
