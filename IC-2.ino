int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=1000;

//byte LEDs=0x88;
byte LED1s=0b00000000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,LED1s);
  digitalWrite(latchPin,HIGH);
  delay(dt);
  Serial.println(LED1s);
  LED1s=LED1s+1;
}
