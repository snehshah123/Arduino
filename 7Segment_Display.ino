int A=2;
int B=3;
int C=4;
int D=5;
int E=6;
int F=7;
int G=8;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop()
{
  int ctr=0;
  while (ctr<=9)
  {
    if (ctr==0)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
    }
    if (ctr==1)
    {
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
    }
    if (ctr==2)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
    }
    if (ctr==3)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
    }
	if (ctr==4)
    {
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
    }
    if (ctr==5)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
    }
    if (ctr==6)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
    }
    if (ctr==7)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
    }
    if (ctr==8)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
    }
    if (ctr==9)
    {
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
    }
    ctr++;
    if (ctr==10)
    {
      ctr=0;
    }
    delay(2000);
  }
}
  