int ledPin=8;
int buttonPin=12;
int buttonRead;
int dt=250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead=digitalRead(buttonPin);
  Serial.println(buttonRead);
  //delay(dt);
  if (buttonRead==1)
  {
    digitalWrite(ledPin,LOW);
  }
  if (buttonRead==0)
  {
    digitalWrite(ledPin,HIGH);
  }
}
