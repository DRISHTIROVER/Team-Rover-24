#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mySensor;
float yaw;

void setup() {
  Serial.begin(115200);
  mySensor.beginMag();

  // You can set your own offset for mag values
  mySensor.magXOffset = -6;
  mySensor.magYOffset = -80;
  mySensor.magZOffset = 83;
}

void loop() {
  uint8_t sensorId;
  if (mySensor.readId(&sensorId) != 0) {
    Serial.println("Cannot read sensorId");
  }
  if (mySensor.magUpdate() == 0) {
    yaw = mySensor.magHorizDirection()+20;
    Serial.println("horizontal direction: " + String(yaw));
  } else {
    Serial.println("Cannot read mag values");
  }
  delay(100);
}
