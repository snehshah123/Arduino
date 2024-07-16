#include <AHT20.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include <RTClib.h>

#include <Wire.h>

#include <SPI.h>
#include <MPU9250.h>
#define SPI_CLOCK 8000000
#define SS_PIN   10 
#define INT_PIN  3
#define LED      13

float bmp280temp,bmp390temp,ahttemp,rtctemp,mputemp;

Adafruit_BMP280 bmp280;
Adafruit_BMP3XX bmp390;
RTC_DS3231 rtc;
MPU9250 mpu(SPI_CLOCK, SS_PIN);
AHT20 aht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(INT_PIN, INPUT);
  SPI.begin();
  mpu.init(true);

  while(!Serial) delay(10);
  
  if (!rtc.begin()) 
  {
    Serial.println("RTC Module not Present ");
    while (1);
  }
  if (!aht.begin())
  {
    Serial.println("AHT20 Not Present ");
    while (1);
  }
  if (!bmp280.begin()) {
     Serial.println("Could not find a valid BMP280 sensor, check wiring!");
     while (1);
  } 
  if (!bmp390.begin_I2C()) {
     Serial.println("Could not find a valid BMP280 sensor, check wiring!");
     while (1);
  }
}

void loop() {

  Serial.println("1");
  // put your main code here, to run repeatedly:
  mpu.read_all();

  rtctemp=rtc.getTemperature();
  Serial.print("RTC Temperature :- ");
  Serial.print(rtctemp);
  Serial.println(" degC");
  mputemp=mpu.temperature;
  Serial.print("MPU 6050 Temperature:- ");
	Serial.print(mputemp);
	Serial.println(" degC");
  ahttemp=aht.getTemperature();
  Serial.print("AHT 20 Temperature:- ");
	Serial.print(ahttemp);
	Serial.println(" degC");
  bmp280temp=bmp280.readTemperature();
  Serial.print("BMP 280 Temperature:- ");
	Serial.print(bmp280temp);
	Serial.println(" degC");
  bmp390temp=bmp390.readTemperature();
  Serial.print("BMP 390 Temperature:- ");
	Serial.print(bmp390temp);
	Serial.println(" degC");

  Serial.println();
  Serial.println();

}
