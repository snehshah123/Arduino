int myPin=A2;
int readVal;
float V2;
int dt=500;
int redPin=9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(myPin,INPUT);
  pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(myPin);
  V2=(5./1023.)*readVal;
  Serial.print("Potentiometer Voltage is :- ");
  Serial.println(V2);
  if (V2>=4.00)
  {
    digitalWrite(redPin,HIGH);
  }
  if (V2<4.00)
  {
    digitalWrite(redPin,LOW);  
  }
  delay(dt);
}
