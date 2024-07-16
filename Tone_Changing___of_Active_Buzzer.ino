int BuzzPin=8;
int PotVal;
int toneVal;
int PotPin=A1;


void setup() {
  // put your setup code here, to run once:
  pinMode(BuzzPin,OUTPUT);
  pinMode(PotPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PotVal=analogRead(PotPin);
  toneVal=(((9940./1023.)*PotVal)+60);
  digitalWrite(BuzzPin,HIGH);
  delayMicroseconds(toneVal);
  digitalWrite(BuzzPin,LOW);
  delayMicroseconds(toneVal);

}
