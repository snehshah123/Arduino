#include <Servo.h>

Servo myservo1 ;
Servo myservo2 ;

float X ; 
float Y ;

int caltime =10 ;

int servo1Pin = 9 ;
int servo2Pin = 10 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

 // pinMode(servo1Pin,OUTPUT);
 // pinMode(servo2Pin,OUTPUT);

  myservo1.attach(servo1Pin);
  myservo2.attach(servo2Pin);

  myservo1.write(90);
  myservo2.write(90);

  delay(caltime);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int theta = 0 ; theta <= 45 ; theta++)
  {
    X = 90 - 1.75*theta ;
    Y = 90 + theta ;

    Serial.println(X);
    Serial.println(Y);
    
    myservo1.write(X);
    myservo2.write(Y);

    delay(caltime);

  }
   for (int theta =  45 ;theta >= 0 ; theta--)
  {
    X = 90 - 1.75*theta ;
    Y = 90 + theta ;

    Serial.println(X);
    Serial.println(Y);
    
    myservo1.write(X);
    myservo2.write(Y);

    delay(caltime);

  }
 
}