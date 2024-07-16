#include <SoftwareSerial.h>


SoftwareSerial Serial1(8, 9);

void setup() {
  Serial1.begin(115200);
  pinMode(A6, OUTPUT);

  while (!(Serial1.read() == '3'))
    ;

  Serial1.println("BURN");
  digitalWrite(A6, HIGH);
  delay(2000);
  digitalWrite(A6, LOW);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}