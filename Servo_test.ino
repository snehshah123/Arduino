#include <Servo.h>

int angle1;
int angle2;
int servoPin=9;
Servo myServo;
int dt=1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servoPin,OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(dt);
  angle1=180;
  myServo.write(angle1);
  delay(dt);
  angle2=-180;
  myServo.write(angle2);
  delay(dt);
}
