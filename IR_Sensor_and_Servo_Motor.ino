# include <Servo.h>

int servoPin=9;
int IRPin=4;
int IRData;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IRPin,INPUT);
  pinMode(servoPin,OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  IRData=digitalRead(IRPin);
  Serial.print("IR Value :- ");
  Serial.println(IRData);
  
  if (IRData==1)
  {
    myServo.write(90);
  }
  if (IRData==0)
  {
    myServo.write(-90);
  }
}
