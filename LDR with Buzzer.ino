int resPin=A2;
int buzzPin=8;
int resVal;
int delayT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  pinMode(resPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  resVal=analogRead(resPin);
  delayT=(9./550.)*resVal-(9.*200./550.)+1.;
  Serial.println(resVal);
  digitalWrite(buzzPin,HIGH);
  delay(delayT);
  digitalWrite(buzzPin,LOW);
  delay(delayT);
}
