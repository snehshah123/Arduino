byte myByte=B00000000; 
int dt=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(myByte,DEC);
  Serial.print("   ");
  Serial.print(myByte,BIN);
  Serial.print("   ");
  Serial.println(myByte,HEX);
  myByte=myByte+1;
  delay(dt);
}
