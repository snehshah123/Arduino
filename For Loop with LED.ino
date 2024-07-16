int greenPin=6;
int redPin=9;
int redblink=5;
int greenblink=3;
int greentime=500;
int redtime=500;
int j;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (j=1;j<=greenblink;j++)
  {
    digitalWrite(greenPin,HIGH);
    delay(greentime);
    digitalWrite(greenPin,LOW);
    delay(greentime);
  }
  for (j=1;j<=redblink;j++)
  {
    digitalWrite(redPin,HIGH);
    delay(redtime);
    digitalWrite(redPin,LOW);
    delay(redtime);
  }
}
