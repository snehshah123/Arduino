int lightPen=A0;
int lightVal;
int dv=250;
int greenPin=11;
int redPin=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightPen);
  Serial.println(lightVal);
  delay(dv);
  if (lightVal>350)
  {
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }
  if (lightVal<=350)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  if (lightVal>900)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,HIGH);
    delay(200);
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    delay(200);
  }
}
