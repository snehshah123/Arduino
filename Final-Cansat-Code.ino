#include <Arduino_HS300x.h>
#include <Arduino_LPS22HB.h>
#include <Arduino_BMI270_BMM150.h>
#include <TinyGPS++.h>
#include <SPI.h>
#include <SD.h>
#include <RTClib.h>
#include <math.h>
#include <SoftwareSerial.h>

//motor driver

String data;
File newFile;
TinyGPSPlus gps;
RTC_DS3231 rtc;

int buzzPIN=7;
int paraPin=A6;
String team_id="050";
int packCount=0;
const int chipSelect=2;
float temperature,humidity,pressure,vel;

//altitude and velocity

void setup() {
  BARO.begin();
  IMU.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  HS300x.begin(); 
  Serial.begin(9600); 
  Serial1.begin(57600);
  pinMode(buzzPIN,OUTPUT);
  pinMode(paraPin,OUTPUT);
  UART Serial2(digitalPinToPinName(8), digitalPinToPinName(9), NC, NC);
  Serial2.begin(115200);
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

void readRTC()
{
  DateTime now = rtc.now();
  int rhr,rmin,rsec;
  String rtime;
  rhr=now.hour();
  rmin=now.minute();
  rsec=now.second();
  rtime=String(rhr)+"/"+String(rmin)+"/"+String(rsec); 
}

void voltage()
{
  #define ANALOG_IN_PIN A0
  float R1 = 30000.0;
  float R2 = 7500.0;
  voltage = analogRead(ANALOG_IN_PIN);  
}

void buzz()
{
  const int buzzPIN=7;
  tone(buzzPIN,330);  
}

void gps()
{
  float lat,lng,alt;
  int hr,minute,sec,sats;
  int month,year,day;
  while (Serial1.available())
  {
    if (gps.encode(Serial1.read()))
    {
      sats=gps.satellites.value();
      lng=gps.location.lng();
      lat=gps.location.lat();
      alt=gps.altitude.meters();
      vel=gps.speed.mps();
      if (gps.date.isValid())
      {
        day=gps.date.day();
        month=gps.date.month();
        year=gps.date.year();
      }
      if (gps.time.isValid())
      {
        hr=gps.time.hour();
        minute=gps.time.minute();
        sec=gps.time.second();
        hr=hr+5;
        minute=minute+30;
        if (minute>=60)
        {
          hr+=1;
          minute-=30;     
        } 
        if (hr>=24) 
        {
          hr-=24;       
        }                             
      }
    }
  }
}

void SDStorage()
{
    while(1){
    newFile = SD.open("CanSat_050_Data.csv", FILE_WRITE);
    if (newFile)
    {
      newFile.println(data);
      newFile.close();
    }
  }
}

void ATHP()
{
  temperature=HS300x.readTemperature();
  humidity=HS300x.readHumidity();
  pressure=BARO.readPressure();
  const float t0=32.0;
  const float h0=5.0;
  const float p0=pow(e,(-34.16297*h0)/t0);
  altitude=((t0*log(pressure/p0))-(34.16297*h0))/(-34.16297)
}

void IMU()
{
  
}

void FSW()
{

}

void PID()
{

}

void burn()
{
  int ctr=0;
  const int paraPin=A6;
  while (altitude>=500 and altitude<=550 )
  {
    digitalWrite(paraPin,HIGH);
    delay(2000);
    digitalWrite(paraPin,LOW);    
    ctr+=1;
    if (ctr==1)
    {
      break
    }
  }
}
void loop() {
  packCount++;
  float xAcc, yAcc, zAcc;
  float roll, pitch, heading;
  float xG,yG,zG;
  int16_t accel_x_cal, accel_y_cal, accel_z_cal;
  int16_t gyro_x_cal, gyro_y_cal, gyro_z_cal;
  float accel_x_filt, accel_y_filt, accel_z_filt;
  float gyro_x_filt, gyro_y_filt, gyro_z_filt; 
  if(IMU.accelerationAvailable()){
    IMU.readAcceleration(xAcc, yAcc, zAcc);
    IMU.readGyroscope(xG,yG,zG);
  }
  pitch = 180 * atan (x/sqrt(y*y + z*z))/M_PI;
  roll = 180 * atan (y/sqrt(x*x + z*z))/M_PI;
  heading = 180 * atan (z/sqrt(x*x + y*y))/M_PI;
 
  data=String(team_id)+","+String(rtime)+","+String(packCount)+","+String()+","+String(pressure)+","+String(temperature)+","+"3.3"+","+String(hr)+","+String(minute)+","+String(sec)+","+String(lat)+","+String(lng)+","+String(alt)+","+String(sats)+","+String(xAcc)+","+String(yAcc)+",",String(zAcc)+","+String(roll)+","+String(pitch)+","+String(heading)+","+String()+","+String()+","+String(humidity)+","+String();

  Serial2.println(data);
}