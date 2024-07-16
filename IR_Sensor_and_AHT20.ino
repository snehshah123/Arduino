#include <AHT20.h>
#include <Wire.h>
const int irPin=9;
int irVal;
float humidity;
float tempC;
float tempF;

AHT20 sensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(irPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  irVal=digitalRead(irPin);
  Serial.print("IR Value :- ");
  Serial.println(irVal);
  if (irVal==1)
  {
    Serial.println("No Data Received !!");
  }
  if (irVal==0)
  {
    sensor.begin();
    humidity=sensor.getHumidity();
    tempC=sensor.getTemperature();
    tempF=(tempC*(9/5))+32;
    Serial.print("Humidity :- ");
    Serial.print(humidity);  
    Serial.println(" rH");
    Serial.print("Temperature :- ");
    Serial.print(tempC);
    Serial.println(" *C");
    Serial.print("Temperature :- ");
    Serial.print(tempF);
    Serial.println(" *F");
    delay(1000);
  }
}
