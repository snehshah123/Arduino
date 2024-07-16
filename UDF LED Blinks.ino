int redPin=9;
int numBlinks; 
String msg="How many blinks do you want :- ";
int j;
int bt=500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available()==0)
  {

  }
  numBlinks=Serial.parseInt();
  for(j=1;j<=numBlinks;j=j+1)
  {
    digitalWrite(redPin,HIGH);
    delay(bt);
    digitalWrite(redPin,LOW);
    delay(bt); 
  }
  
}
