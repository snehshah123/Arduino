int PlusPin=7;
int SgnPin=A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PlusPin,OUTPUT);
  digitalWrite(PlusPin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PlusPin,HIGH);
  delay(10);
  int val=analogRead(SgnPin);
  Serial.print("Sensor Value :- ");
  Serial.println(val);
}
