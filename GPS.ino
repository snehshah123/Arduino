#include <TinyGPS++.h> 

TinyGPSPlus gps;
int hr,minute,sec;
int ReadCount=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial1.available())
  {
    if (gps.encode(Serial1.read()))
    {
      //CALLING OF UDF
      smartDelay(1000);
      
      Serial.print("# READING NO:- ");
      Serial.println(ReadCount);
      Serial.print("SATS :- ");
      Serial.println(gps.satellites.value());
      Serial.print("LAT :- ");
      Serial.println(gps.location.lat(),6);
      Serial.print("LONG :- ");
      Serial.println(gps.location.lng(),6);
      Serial.print("ALT :- ");
      Serial.println(gps.altitude.meters());
      Serial.print("SPEED :- ");
      Serial.println(gps.speed.mps());
      if (gps.date.isValid())
      {
        Serial.print("DATE :- ");
        Serial.print(gps.date.day());
        Serial.print("-");
        Serial.print(gps.date.month());
        Serial.print("-");
        Serial.println(gps.date.year());
      }
      Serial.print("DEGREES :- ");
      Serial.println(gps.course.deg());
      Serial.print("HDOP :- ");
      Serial.println(gps.hdop.value());
      if (gps.time.isValid())
      {
        hr=gps.time.hour();
        minute=gps.time.minute();
        sec=gps.time.second();
        hr=hr+5;
        minute=minute+30;
        if (minute>=60)
        {
          hr=hr+1;
          minute=minute-30;     
        }  
        Serial.print("HOURS :- ");
        Serial.println(hr);
        Serial.print("MINUTES :- ");
        Serial.println(minute);
        Serial.print("SECONDS :- ");
        Serial.println(sec);                             
      }
      Serial.println("-----------------------------------");
      ReadCount++;
    }
  }
  if (Serial1.available()==0)
  {
    Serial.print("") ;   
  } 
}

//DECLARATION OF UDF:-

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while(Serial1.available())
    {
      gps.encode(Serial1.read());     
    }
  }
  while(millis() - start < ms);
}
