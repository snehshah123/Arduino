int soundPin=A2;
int LEDPin=9;
int threshold=300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soundPin,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ss=analogRead(soundPin);
  Serial.println(ss);
  if (ss>=threshold)
  {
    digitalWrite(LEDPin,HIGH);
    tone(LEDPin,600);
    delay(1000);
  }
  else
  {
    digitalWrite(LEDPin,LOW);
    noTone(LEDPin);
  }
}
