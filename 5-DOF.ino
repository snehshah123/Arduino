#include <Servo.h>
#include <math.h>

//servo define
Servo s1 ;//80kg-cm
Servo s2 ;//650kg-cm
Servo s3 ;//150kg-cm
Servo s4 ;//35kg-cm(1)
Servo s5 ;//35kg-cm(2)

//pwmPins
int s1Pin = 1 ;
int s2Pin = 2 ;
int s3Pin = 3 ;
int s4Pin = 4 ;
int s5Pin = 5 ;

//angles
float theta1;
float theta2;
float theta3;
float theta4;
float theta5;

//position vectors
float px = -0.11;
float py = -0.02;
float pz = -1.21;

//normal vectors
float nx = 1;
float ny = 0;
float nz = 0;

//approach vectors
float ax = 0;
float ay = -1;
float az = 0;

//s vectors
float sx = 0;
float sy = 0;
float sz = -1;

//distances
float d1 = 10.5 ;
float a2 = 45 ;
float a3 = 50 ;
float a4 = 21 ;
float d5 = 10 ;

void setup() {
  // put your setup code here, to run once:
  //attaching pins
  s1.attach(s1Pin);
  s2.attach(s2Pin);
  s3.attach(s3Pin);
  s4.attach(s4Pin);
  s5.attach(s5Pin);

  //Serial start
  Serial.begin(9600);

  //defining pin modes
  pinMode(s1Pin,OUTPUT);
  pinMode(s2Pin,OUTPUT);
  pinMode(s3Pin,OUTPUT);
  pinMode(s4Pin,OUTPUT);
  pinMode(s5Pin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  px = cos(theta1) * (a2 * cos(theta2) + a3 * cos(theta2 + theta3) + a4 * cos(theta2 + theta3 + theta4) - d5 * sin(theta2 + theta3 + theta4));
  py = sin(theta1) * (a2 * cos(theta2) + a3 * cos(theta2 + theta3) + a4 * cos(theta2 + theta3 + theta4) - d5 * sin(theta2 + theta3 + theta4));
  pz = d1 - a2 * sin(theta2) - a3 * sin(theta2 + theta3) - a4 * sin(theta2 + theta3 + theta4) - d5 * cos(theta2 + theta3 + theta4);

  theta1 = atan2(py,px);

  float s234 = - (ax * cos(theta1) + ay * sin(theta1));
  float c234 = - az ;

  float theta234 = atan2(s234,c234);

  float b = a2 * cos(theta2) + a3 * cos(theta2 + theta3);
  float c = a2 * sin(theta2) + a3 * sin(theta2 + theta3);
  float c3 = ((pow(b,2) + pow(c,2) - pow(a3,2) - pow(a2,2) / (2 * a3 * a2)));
  float s3 = sqrt(1 - pow(c3,2));

  theta3 = atan2(s3,c3);

  float r = a3 * c3 + a2 ; 
  float s = a3 * s3 ;

  theta2 = atan2(r*c - s*b , r*b + s*c);

  theta4 = theta234 - theta3 - theta2 ;

  float s5 = nx * sin(theta1) - ny * cos(theta1) ;
  float c5 = sx * sin(theta1) - sy * cos(theta1);
  sx = - cos(theta1)*cos(theta2 + theta3 + theta4)*s5 + sin(theta1)*c5;
  sy = - sin(theta1)*cos(theta2 + theta3 + theta4)*s5 - cos(theta1)*c5;

  theta5 = atan2(s5,c5);

  //printing theta1,2,3,4,5
  Serial.println(theta1);
  Serial.println(theta2);
  Serial.println(theta3);
  Serial.println(theta4);
  Serial.println(theta5);
  delay(5000);
}
