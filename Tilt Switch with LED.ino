int tiltPin=8;
int tiltVal;
int greenPin=2;
int redPin=11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tiltPin,INPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  digitalWrite(tiltPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal=digitalRead(tiltPin);
  Serial.print("Switch Value is :- ");
  Serial.println(tiltVal);
  if (tiltVal==1)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  if (tiltVal==0)
  {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
  }
}
