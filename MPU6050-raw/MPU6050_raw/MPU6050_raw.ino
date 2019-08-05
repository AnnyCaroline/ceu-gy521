#include "I2Cdev.h"
#include "MPU6050.h"

#include "Wire.h"

MPU6050 accelgyro(0x68);

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t tmp;

void setup() {
    Wire.begin();

    Serial.begin(9600);

    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    //accelgyro.setSleepEnabled(true);

    Serial.println("Testing device connections...");
    //Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    // use the code below to change accel/gyro offset values
    /*
    Serial.println("Updating internal sensor offsets...");
    // -76	-2359	1688	0	0	0
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    accelgyro.setXGyroOffset(220);
    accelgyro.setYGyroOffset(76);
    accelgyro.setZGyroOffset(-85);
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    */
}

void loop() {
    delay(1000);
    accelgyro.getAcceleration(&ax, &ay, &az);
    Serial.println("\n-ACC-----------------");
    Serial.println(ax);
    Serial.println(ay);
    Serial.println(az);

    tmp = accelgyro.getTemperature();
    Serial.println("\n-TMP-----------------");
    Serial.println(tmp);
    Serial.println(tmp/340.00+36.53);

    accelgyro.getRotation(&gx, &gy, &gz);
    Serial.println("\n-ROT-----------------");
    Serial.println(gx);
    Serial.println(gy);
    Serial.println(gz);

    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.println("\n-M6------------------");
    Serial.println(ax);
    Serial.println(ay);
    Serial.println(az);
    Serial.println(gx);
    Serial.println(gy);
    Serial.println(gz);

    while(1);
}
