int redLED=13;
float pi=3.14;
int dit=100;
int dah=500;
int longW=1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED,HIGH);
  delay(dit);
  digitalWrite(redLED,LOW);
  delay(dit);

  digitalWrite(redLED,HIGH);
  delay(dit);
  digitalWrite(redLED,LOW);
  delay(dit);

  digitalWrite(redLED,HIGH);
  delay(dit);
  digitalWrite(redLED,LOW);
  delay(dit);

  digitalWrite(redLED,HIGH);
  delay(dah);
  digitalWrite(redLED,LOW);
  delay(dah);

  digitalWrite(redLED,HIGH);
  delay(dah);
  digitalWrite(redLED,LOW);
  delay(dah);

  digitalWrite(redLED,HIGH);
  delay(dah);
  digitalWrite(redLED,LOW);
  delay(dah);

  digitalWrite(redLED,HIGH);
  delay(dit);
  digitalWrite(redLED,LOW);
  delay(dit);

  digitalWrite(redLED,HIGH);
  delay(dit);
  digitalWrite(redLED,LOW);
  delay(dit);

  digitalWrite(redLED,HIGH);
  delay(dit);
  digitalWrite(redLED,LOW);
  delay(dit);

  delay(longW);



}
