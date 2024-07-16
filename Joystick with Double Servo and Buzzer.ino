#include <Servo.h>
Servo XServo;
Servo YServo;

int Xpin=A0;
int Ypin=A2;
int Spin=6;
int XSpin=10;
int YSpin=9;
int buzzPin=7;
int WVx;
int WVy;
int Xval;
int Yval;
int Sval;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Spin,INPUT);
  pinMode(XSpin,OUTPUT);
  pinMode(YSpin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  XServo.attach(XSpin);
  YServo.attach(YSpin);
  digitalWrite(Spin,HIGH);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Xval=analogRead(Xpin);
  WVx=(180./1023.)*Xval;
  Yval=analogRead(Ypin);
  WVy=(180./1023.)*Yval;
  Sval=digitalRead(Spin);
  if (Sval==0)
  {
    digitalWrite(buzzPin,HIGH);
  }
  else
  {
    digitalWrite(buzzPin,LOW); 
  }
  
  XServo.write(WVx);
  YServo.write(WVy);

  delay(200);
  Serial.print("X Value = ");
  Serial.println(Xval);
  Serial.print("Y Value = ");
  Serial.println(Yval);
  Serial.print("S Value = ");
  Serial.println(Sval);
}
