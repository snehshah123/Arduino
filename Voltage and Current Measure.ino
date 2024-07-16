int readPin=A3;
float V2=0.0;
float current=0.0;
int resistance=220;
int readVal;
int delaytime=500; 
void setup() {
  // put your setup code here, to run once:
  pinMode(readPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(readPin);
  V2=(5./1023.)*readVal;
  current=(V2/resistance)*1000;
  Serial.println(V2);
  Serial.println(current);
  delay(delaytime);
}
