#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
Adafruit_BMP3XX bmp;

const int sea=1013.25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  if (!bmp.begin_I2C()) { 
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedl
if (! bmp.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;  }

  Serial.print("Temperature :- ");
  Serial.println(bmp.temperature);
  Serial.print("Pressure :- ");
  Serial.println(bmp.pressure);
  
}
