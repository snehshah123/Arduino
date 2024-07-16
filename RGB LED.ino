int redPin=9;
int greenPin=10;
int bluePin=11;
String mycolor;
String msg="What color do you want ??";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available()==0)
  {

  }
  mycolor=Serial.readString();
  if (mycolor=="red")
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
  }
  if (mycolor=="green")
  {
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
    digitalWrite(bluePin,LOW);
  }
  if (mycolor=="blue")
  {
    digitalWrite(bluePin,HIGH);
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
  }
  if (mycolor=="aqua")
  {
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
    analogWrite(greenPin,255);
  }
  if (mycolor=="yellow")
  {
    analogWrite(bluePin,0);
    analogWrite(redPin,255);
    analogWrite(greenPin,255);
  }
  if (mycolor=="purple")
  {
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
  }
  if (mycolor=="white")
  {
    analogWrite(redPin,255);
    analogWrite(bluePin,255);
    analogWrite(greenPin,255);
  }
  if (mycolor=="teal")
  {
    analogWrite(redPin,0);
    analogWrite(bluePin,153);
    analogWrite(greenPin,153); 
  }
}
