#include <SoftwareSerial.h>
SoftwareSerial xbeeSerial(3, 2);//RX, TX
int xbeeBaudRate= 9600;

void setup() {
  Serial.begin(115200); 
  Serial.println();
  xbeeSerial.begin(xbeeBaudRate);
  
}

void loop() {
  Serial.println("Hi Sneh ");
  xbeeSerial.println("Hi Sneh !!");
}