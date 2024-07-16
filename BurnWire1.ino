const int mosPin=8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mosPin,OUTPUT);

  for (int i=1;i<=121;i++)
  {
    if (i==120)
    {
      digitalWrite(mosPin,HIGH);
      delay(3000);
      digitalWrite(mosPin,LOW);
    }
    delay(1000);
    Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
