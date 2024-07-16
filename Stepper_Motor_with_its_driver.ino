int inPin1=9;
int inPin2=10;
int inPin3=11;
int inPin4=12;
int stepNum=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inPin1,OUTPUT);
  pinMode(inPin2,OUTPUT);
  pinMode(inPin3,OUTPUT);
  pinMode(inPin4,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0 ; i < 1000 ; i++)
  {
    OneStep(false);
    delay(2);
  }
  for (int i = 0 ; i < 1000 ; i++)
  {
    OneStep(true);
    delay(2);
  }
}
void OneStep(bool dir)
{
  if (dir)
  {
    switch(stepNum)
    {
      case 0:      
      digitalWrite(inPin1,HIGH);
      digitalWrite(inPin2,LOW);
      digitalWrite(inPin3,LOW);
      digitalWrite(inPin4,LOW);
      break;
      case 1:      
      digitalWrite(inPin1,LOW);
      digitalWrite(inPin2,HIGH);
      digitalWrite(inPin3,LOW);
      digitalWrite(inPin4,LOW);
      break;
      case 2:      
      digitalWrite(inPin1,LOW);
      digitalWrite(inPin2,LOW);
      digitalWrite(inPin3,HIGH);
      digitalWrite(inPin4,LOW);
      break;
      case 3:      
      digitalWrite(inPin1,LOW);
      digitalWrite(inPin2,LOW);
      digitalWrite(inPin3,LOW);
      digitalWrite(inPin4,HIGH);
      break;
    }
  }
  else
  {
    switch(stepNum)
    {
      case 0:      
      digitalWrite(inPin1,LOW);
      digitalWrite(inPin2,LOW);
      digitalWrite(inPin3,LOW);
      digitalWrite(inPin4,HIGH);
      break;
      case 1:      
      digitalWrite(inPin1,LOW);
      digitalWrite(inPin2,LOW);
      digitalWrite(inPin3,HIGH);
      digitalWrite(inPin4,LOW);
      break;
      case 2:      
      digitalWrite(inPin1,LOW);
      digitalWrite(inPin2,HIGH);
      digitalWrite(inPin3,LOW);
      digitalWrite(inPin4,LOW);
      break;
      case 3:      
      digitalWrite(inPin1,HIGH);
      digitalWrite(inPin2,LOW);
      digitalWrite(inPin3,LOW);
      digitalWrite(inPin4,LOW);
      break;
    }
  }
  stepNum++;
  if (stepNum>3)
  {
    stepNum=0;
  }    
}
