#include <SoftwareSerial.h>
SoftwareSerial xbeeSerial(8, 9);//RX, TX
int xbeeBaudRate= 115200;
void setup() {
  pinMode(A6,OUTPUT);
  xbeeSerial.begin(xbeeBaudRate);
  if (xbeeSerial.available()>0)
  {
    if (xbeeSerial.read() == 'T')
    {
      digitalWrite(A6,HIGH);
      delay(3000);
      digitalWrite(A6,LOW);      
    }
  } 
}
void loop() {

}
