String lName;
String msg="What colour LED to be turned on ";
int rled=9;
int yled=11;
int gled=7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rled,OUTPUT);
  pinMode(yled,OUTPUT);
  pinMode(gled,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(msg);
  while(Serial.available()==0)
  {

  }
  
  lName=Serial.readString();
  if (lName=="red")
  {
    digitalWrite(rled,HIGH);
    delay(1000);
    digitalWrite(rled,LOW);
  }
  else if (lName=="yellow")
  {
    digitalWrite(yled,HIGH);
    delay(1000);
    digitalWrite(yled,LOW);  
  }
  else 
  {
    digitalWrite(gled,HIGH);
    delay(1000);
    digitalWrite(gled,LOW);
  }
}
