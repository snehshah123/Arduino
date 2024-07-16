int buttonPin1=12;
int buttonPin2=11;
int buttonVal1;
int buttonVal2;
int delayt=250;
int ledPin=6;
int buzzPin=13;
int b=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal1=digitalRead(buttonPin1);
  buttonVal2=digitalRead(buttonPin2);
  Serial.print("Button 1 :- ");
  Serial.println(buttonVal1);
  Serial.print("Button 2 :- ");
  Serial.println(buttonVal2);
  delay(delayt);
  if (buttonVal1==0)
  {
    b=b+5;
    Serial.println(b);
  }
  if (buttonVal2==0)
  {
    b=b-5;
    Serial.println(b);
  }
  if (b>255)
  {
    b=255;
    digitalWrite(buzzPin,HIGH);
    delay(delayt);
    digitalWrite(buzzPin,LOW);
    Serial.println("BUZZ HIGH !!");
  }
  if (b<0)
  {
    b=0;
    digitalWrite(buzzPin,HIGH);
    delay(delayt);
    digitalWrite(buzzPin,LOW);
    Serial.println("BUZZ LOW !!");
  }  
  
  Serial.print("Brightness :- ");
  Serial.println(b);

  analogWrite(ledPin,b);
}
