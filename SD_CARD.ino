#include"SPI.h"
#include"SD.h"

File newFile;

const int chipSelect=4;
//int potPinA=A0,potPinB=A1;
//int potValA,potValB,dt=500,i;

void setup()
{
  Serial.begin(9600);
  while(!Serial);

  Serial.println("INITIALIZING MicroSD Card Module");

  if(!SD.begin(chipSelect))
  {
    Serial.println("CHECK CS PIN WIRING OR ELSE CHECK FOR THE SD CARD INSERTED OR NOT?");
    while(1);
  }
  Serial.print("THE INITIALIZING PROCESS IS DONE SUCCESFULLY");
  newFile = SD.open("CSVTEST1.csv", FILE_WRITE);
    if(newFile)
    { 
      newFile.print("potValA");
      newFile.print("\t");
      newFile.println("potValB");    
      newFile.close();
    }
}

void loop()
{
  for(i=0;i<=50;i++)
  {
    newFile = SD.open("CSVTEST1.csv", FILE_WRITE);
    if(newFile)
    { 
      potValA=analogRead(A0);
      potValB=analogRead(A1);
      Serial.println(potValA);
      Serial.println(potValB);
      delay(dt);           
      
      newFile.print(potValA);
      newFile.print(",");
      newFile.println(potValB);    
      newFile.close();
    }
    else
    {
      Serial.println("UNABLE TO OPEN THE FILE!!!!");
    }
  }

  Serial.println("WAIT FOR 10 SECONDS, AFTER THAT WHATEVER IS STORED IN SD CARD WILL BE DISPLAYED");
  delay(10000);
  
  newFile = SD.open("CSVTEST1.csv");
  if (newFile) 
  {
    Serial.println("CSVTEST1.csv:");
    while (newFile.available())
    {
      Serial.write(newFile.read());
    }
    newFile.close();   
  }

}