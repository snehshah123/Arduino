#include<Servo.h>
#include<math.h>
Servo myservo;
Servo axis0_servo;
Servo axis1_servo;
int pos=0;
int pot_val;
double c=0;
double hp;
double i=0;
double theta3,theta4,alpha;
#define theta1 30
#define theta2 30
void setup()
{
  Serial.begin(300);
  myservo.attach(9);
  pinMode(A0,INPUT);
  axis0_servo.attach(5);
  axis1_servo.attach(6);

}
void loop()
{
  int potvalue=analogRead(A0);
  if (pot_val<500)
  {
    axis0_servo.write(theta1);
    axis1_servo.write(theta2);
  }
  if(pot_val>500)
  {
    int coordinate(6,6+c);
    c=c+0.1;
    if(c>1)
    {
      while(1)
      {

      }
    }
  }
}
void coordinate(double x,double y)
  {
    hp=sqrt(pow(x,2)+pow(y,2));
    alpha=asin(hp/20);
    theta3=2*alpha*180/PI;
    theta4=atan2(y,x)*180/PI + ((180-theta3)/2);
    axis0_servo.write(theta3);
    axis1_servo.write(theta4);
  }
