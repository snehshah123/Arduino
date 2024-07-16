#include <math.h>

float d1 = 15;  
float d2 = 45;  
float d3 = 50;  
float d4 = 21;  
float d5 = 6;  
 
float nx = 1;
float ny = 0;
float nz = 0;

float sx = 0;
float sy = -1;
float sz = 0;

float ax = 0;
float ay = 0;
float az = -1;

float x = 10;  
float y = 70;
float z = 30;

void setup() { 
  Serial.begin(9600);
}

void loop() {
  float q1 = atan2(y, x);

  float eq1 = -(ax * cos(q1) + ay * sin(q1));
  float eq2 = (-az);

  float q5 = atan2((nx*sin(q1)-ny*cos(q1)),(sx*sin(q1)-sy*cos(q1)));

  float c = (x/cos(q1))+(d5*eq1)-(d4*eq2);
  float d = (d1-(d4*eq1)-(d5*eq2)-z);

  float R = (c*c + d*d - d3*d3 - d2*d2) / (2*(d3*d2));
  float t = sqrt(1 - R*R);

  float q3 = atan2(t, R);

  float r = d3*cos(q3) + d2;
  float s = d3*sin(q3);

  float q2 = atan2((r*d) - (s*c), (r*c) + (s*d));

  float eq3 = atan2(-(ax*cos(q1)+ay*sin(q1)),-az);
  float q4 = eq3 - (q2 + q3);


  int angle1 = q1 * (180/M_PI);
  int angle2 = q2 * (180/M_PI);
  int angle3 = q3 * (180/M_PI);
  int angle4 = q4 * (180/M_PI);
  int angle5 = q5 * (180/M_PI);

  // Serial.println(angle1);
  // Serial.println(angle2);
  // Serial.println(angle3);
  // Serial.println(angle4);
  // Serial.println(angle5);


  angle1 = angleconstraint(angle1);
  angle2 = angleconstraint(angle2);
  angle3 = angleconstraint(angle3) + 30;
  angle4 = angleconstraint(angle4);
  angle5 = angleconstraint(angle5);

  Serial.print("Theta1 = ");
  Serial.println(angle1);

  Serial.print("Theta2 = ");
  Serial.println(angle2);

  Serial.print("Theta3 = ");
  Serial.println(angle3);

  Serial.print("Theta4 = ");
  Serial.println(angle4);

  Serial.print("Theta5 = ");
  Serial.println(angle5);
  delay(5000);  
}

int angleconstraint(float angle)
{

  if (angle < 0 and angle > -90)
  {
    angle = angle + 90 ;    
  }
  if (angle < 0 and angle < -90)
  {
    angle = abs(angle) + 90 ;
  }
  if (angle > 90 and angle < 180)
  {
    angle = angle - 90 ;
  }
  if ( angle > 90 and angle > 180)
  {
    angle = angle - 180 ;//or 270 - angle1;
  }
  return angle;
}