int dt1=3;
int dt2=5;
int BuzzPin=8;
int j;

void setup() {
  // put your setup code here, to run once:
  pinMode(BuzzPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (j=1;j<=100;j++)
  {
    digitalWrite(BuzzPin,HIGH);
    delay(dt1);
    digitalWrite(BuzzPin,LOW);
    delay(dt1);
  }
  for (j=1;j<=100;j++)
  {
    digitalWrite(BuzzPin,HIGH);
    delay(dt2);
    digitalWrite(BuzzPin,LOW);
    delay(dt2);    
  }
}
