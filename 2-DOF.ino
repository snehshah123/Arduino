#include <Servo.h>

Servo myservo1 ;
Servo myservo2 ;

float X ; 
float Y ;

int caltime = 100 ;

int servo1Pin = 9 ;
int servo2Pin = 10 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(servo1Pin,OUTPUT);
  pinMode(servo2Pin,OUTPUT);

  myservo1.attach(servo1Pin);
  myservo2.attach(servo2Pin);

  delay(caltime);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (float i=0 ; i<180 ; i+=2.5)
  {
    X = 80 * sin(radians(i)) + 90; 
    Y = 80 * cos(radians(i)) + 90; 

    Serial.println(X);
    Serial.println(Y);
    
    myservo1.write(X);
    myservo2.write(Y);
    delay(caltime);
  }
}


