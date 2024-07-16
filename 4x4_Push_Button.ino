int C4=2;
int C3=3;
int C2=4;
int C1=5;
int R1=6;
int R2=7;
int R3=8;
int R4=9;

int LEDPin=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(C4,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(C1,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(C4)==HIGH && digitalRead(R4)==HIGH)
  {
    digitalWrite(LEDPin,HIGH);
    delay(1000);
  }
}
