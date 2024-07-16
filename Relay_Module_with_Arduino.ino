int relayPin=6;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relayPin,LOW);
  delay(500);
  //delay(2000);
  digitalWrite(relayPin,HIGH);
  //delay(2000);
  delay(500);

}
