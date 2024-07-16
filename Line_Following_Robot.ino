# include <Servo.h>

int servoPin=6;
int IR1Pin=8;
int IR2Pin=9;
int IR3Pin=10;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR1Pin,INPUT);
  pinMode(IR2Pin,INPUT);
  pinMode(IR3Pin,INPUT);
  pinMode(servoPin,OUTPUT);
  servo.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:

  IR1Data=digitalRead(IR1Pin);
  IR2Data=digitalRead(IR2Pin);
  IR3Data=digitalRead(IR3Pin);
  
}
