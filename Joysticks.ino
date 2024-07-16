int Xpin=A0;
int Ypin=A2;
int Spin=6;
int Xval;
int Yval;
int Sval;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Spin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Xval=analogRead(Xpin);
  Yval=analogRead(Ypin);
  Sval=digitalRead(Spin);
  delay(500);
  Serial.print("X Value = ");
  Serial.println(Xval);
  Serial.print("Y Value = ");
  Serial.println(Yval);
  Serial.print("S Value = ");
  Serial.println(Sval);
}
