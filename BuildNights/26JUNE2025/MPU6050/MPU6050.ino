
// #include <Arduino.h>
// #include <Wire.h>
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_Sensor.h>

// Adafruit_MPU6050 mpu;

// void setup() {
//     Serial.begin(115200);
//     while (!Serial) delay(10); // for native USB boards

//     if (!mpu.begin()) {
//         Serial.println("Failed to find MPU6050 chip");
//         while (1) { delay(10); }
//     }

//     Serial.println("MPU6050 Found!");

//     mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
//     mpu.setGyroRange(MPU6050_RANGE_500_DEG);
//     mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

//     delay(100);
// }

// void loop() {
//     sensors_event_t a, g, temp;
//     mpu.getEvent(&g, &a, &temp);

//     // Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" m/s^2, ");
//     // Serial.print("Y: "); Serial.print(a.acceleration.y); Serial.print(", ");
//     // Serial.print("Z: "); Serial.println(a.acceleration.z);

//     // Serial.print("Gyro X: "); Serial.print(g.gyro.x); Serial.print(" rad/s, ");
//     // Serial.print("Y: "); Serial.print(g.gyro.y); Serial.print(", ");
//     // Serial.print("Z: "); Serial.println(g.gyro.z);

//     // Serial.print("Temp: "); Serial.print(temp.temperature); Serial.println(" °C");
//     Serial.print(g.gyro.x); Serial.print(",");
//     Serial.print(g.gyro.y); Serial.print(",");
//     Serial.print(g.gyro.z); Serial.print("\n");
//     delay(100);
// }

// #include <Wire.h>
// #include "MPU6050_6Axis_MotionApps20.h"

// MPU6050 mpu;
// float ypr[3];

// void setup() {
//   Serial.begin(115200);
//   Wire.begin();
//   mpu.initialize();
//   mpu.dmpInitialize();
//   mpu.setDMPEnabled(true);
// }

// void loop() {
//   if (mpu.dmpGetCurrentFIFOPacket(mpu.dmpPacketBuffer)) {
//     Quaternion q;
//     VectorFloat gravity;
//     mpu.dmpGetQuaternion(&q, mpu.dmpPacketBuffer);
//     mpu.dmpGetGravity(&gravity, &q);
//     mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

//     // Convert radians to degrees
//     float yaw = ypr[0] * 180/M_PI;
//     float pitch = ypr[1] * 180/M_PI;
//     float roll = ypr[2] * 180/M_PI;

//     Serial.print(yaw); Serial.print(",");
//     Serial.print(pitch); Serial.print(",");
//     Serial.println(roll);
//   }
// }

#include <Wire.h>
#include <MPU6050_tockn.h>

// Create the sensor object; default filter coeffs accel=0.02, gyro=0.98
MPU6050 mpu6050(Wire, /*accelCoeff=*/0.02, /*gyroCoeff=*/0.98);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Initialize MPU6050 and auto-calibrate gyro offsets
  mpu6050.begin();
  delay(100);
  mpu6050.calcGyroOffsets();
  Serial.println("✔️ MPU6050 ready");
}

void loop() {
  // Read raw accel/gyro, apply complementary filter
  mpu6050.update();

  // Get fused angles in degrees
  float roll  = mpu6050.getAngleX();
  float pitch = mpu6050.getAngleY();
  float yaw   = mpu6050.getAngleZ();

  Serial.print(yaw); Serial.print(",");
  Serial.print(pitch); Serial.print(",");
  Serial.println(roll);

  delay(100);
}

