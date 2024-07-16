#include "Arduino_BMI270_BMM150.h"
#include <Kalman.h>
#define pi 3.14;

Kalman kalmanX;
Kalman kalmanY;
Kalman kalmanZ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("SAMPLE RATE ");
  Serial.print("Acceleration Rate :- ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.print("Gyroscopre Rate :- ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz"); 
  Serial.print("Magnetometer Rate :- ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  
  if (!IMU.begin())
  {
   Serial.println("Failed to initialize IMU !!");
   while (1);
  }
  Serial.print("SAMPLE RATE ");
  Serial.print("Acceleration Rate :- ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.print("Gyroscopre Rate :- ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz"); 
  Serial.print("Magnetometer Rate :- ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");

}

void loop() {
  // put your main code here, to run repeatedly:
  float x1,y1,z1;
  float x2,y2,z2;
  float x3,y3,z3;
  float roll1,pitch1 ,yaw1;
  float roll2,pitch2,yaw2;
  float roll3,pitch3,yaw3;
  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x1,y1,z1);
    Serial.print("Accelerometer Data X Y Z :- ");
    Serial.print(x1);
    Serial.print("\t");
    Serial.print(y1);
    Serial.print("\t");
    Serial.println(z1);
  }
  if (IMU.gyroscopeAvailable()) 
  {
    IMU.readGyroscope(x2, y2, z2);
    Serial.print("GyroScope Data X Y Z :- ");
    Serial.print(x2);
    Serial.print("\t");
    Serial.print(y2);
    Serial.print("\t");
    Serial.println(z2);
  }
  if (IMU.magneticFieldAvailable()) 
  {
    IMU.readMagneticField(x3, y3, z3);
    Serial.print("Magnetometer Data X Y Z :- ");
    Serial.print(x3);
    Serial.print("\t");
    Serial.print(y3);
    Serial.print("\t");
    Serial.println(z3);
  }  

  pitch2 = 180 * atan (x2/sqrt(y2*y2 + z2*z2))/pi;
  roll2 = 180 * atan (y2/sqrt(x2*x2 + z2*z2))/pi;
  yaw2 = 180 * atan (z2/sqrt(x2*x2 + y2*y2))/pi;

  Serial.println("Gyroscope :- ");
  Serial.print("ROLL PITCH YAW :- ");
  Serial.print(roll2);
  Serial.print("\t");
  Serial.print(pitch2);
  Serial.print("\t");
  Serial.println(yaw2);

  kalmanX.setAngle(roll2);
  kalmanY.setAngle(pitch2);
  gyroXangle = roll2;
  gyroYangle = pitch2;
  compAngleX = roll2;
  compAngleY = pitch2;

  double gyroXrate = gyroX / 131.0; // Convert to deg/s
  double gyroYrate = gyroY / 131.0;
  double dt = (double)(micros() - timer) / 1000000;

  if ((roll2 < -90 && kalAngleX > 90) || (roll2 > 90 && kalAngleX < -90)) {
    kalmanX.setAngle(roll2);
    compAngleX = roll2;
    kalAngleX = roll2;
    gyroXangle = roll2;
  } else
    kalAngleX = kalmanX.getAngle(roll2, gyroXrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleX) > 90)
    gyroYrate = -gyroYrate; // Invert rate, so it fits the restriced accelerometer reading
  kalAngleY = kalmanY.getAngle(pitch2, gyroYrate, dt);

  if ((pitch2 < -90 && kalAngleY > 90) || (pitch2 > 90 && kalAngleY < -90)) {
    kalmanY.setAngle(pitch2);
    compAngleY = pitch2;
    kalAngleY = pitch2;
    gyroYangle = pitch2;
  } else
    kalAngleY = kalmanY.getAngle(pitch2, gyroYrate, dt); // Calculate the angle using a Kalman filter

  if (abs(kalAngleY) > 90)
    gyroXrate = -gyroXrate; // Invert rate, so it fits the restriced accelerometer reading
  kalAngleX = kalmanX.getAngle(roll2, gyroXrate, dt);

  gyroXangle += gyroXrate * dt; // Calculate gyro angle without any filter
  gyroYangle += gyroYrate * dt;

  compAngleX = 0.93 * (compAngleX + gyroXrate * dt) + 0.07 * roll2; // Calculate the angle using a Complimentary filter
  compAngleY = 0.93 * (compAngleY + gyroYrate * dt) + 0.07 * pitch2;

  // Reset the gyro angle when it has drifted too much
  if (gyroXangle < -180 || gyroXangle > 180)
    gyroXangle = kalAngleX;
  if (gyroYangle < -180 || gyroYangle > 180)
    gyroYangle = kalAngleY;

  Serial.print(roll2); 
  Serial.print("\t");
  Serial.print(gyroXangle); 
  Serial.print("\t");
  Serial.print(compAngleX); 
  Serial.print("\t");
  Serial.print(kalAngleX); 
  Serial.print("\t");

  Serial.print("\t");

  Serial.print(pitch2); 
  Serial.print("\t");
  Serial.print(gyroYangle); 
  Serial.print("\t");
  Serial.print(compAngleY); 
  Serial.print("\t");
  Serial.print(kalAngleY); 
  Serial.print("\t");    
  
























}

