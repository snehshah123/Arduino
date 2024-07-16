int PotVal;
int BuzzPin=8;
int PotPin=A3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BuzzPin,OUTPUT);
  pinMode(PotPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  PotVal=analogRead(PotPin);
  if (PotVal>900)
  {
    digitalWrite(BuzzPin,HIGH);
    delay(100);
    digitalWrite(BuzzPin,LOW);
  }
}
