#include <ros.h>
#include <HCSR04.h>
#include <MPU9250_asukiaaa.h>
#include <geometry_msgs/Twist.h>
UltraSonicDistanceSensor right_sensor(38, 40);
UltraSonicDistanceSensor centre_sensor(34, 36);
UltraSonicDistanceSensor left_sensor(30, 32);
UltraSonicDistanceSensor ext_left_sensor(24, 26);
UltraSonicDistanceSensor ext_right_sensor(42, 44);
ros::NodeHandle nh;
geometry_msgs::Twist msg;
ros::Publisher chatter("/bot", &msg);

MPU9250_asukiaaa mySensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

void setup() {
  Wire.begin();
  nh.initNode();
  nh.advertise(chatter);
  mySensor.setWire(&Wire);
  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();
  //mySensor.magXOffset = -155.14;
  //mySensor.magYOffset = 259.77;
  //mySensor.magZOffset = 78.28;
}

void loop() {
  if (mySensor.accelUpdate() == 0) {
    aX = mySensor.accelX();
    aY = mySensor.accelY();
    aZ = mySensor.accelZ();
    aSqrt = mySensor.accelSqrt();
  }
  if (mySensor.magUpdate() == 0) {
    mDirection = mySensor.magHorizDirection();
    Serial.println("horizontal direction: " + String(mDirection));
  }
  msg.linear.x = ext_left_sensor.measureDistanceCm();
  msg.linear.y = left_sensor.measureDistanceCm();
  msg.linear.z = centre_sensor.measureDistanceCm();
  msg.angular.x = right_sensor.measureDistanceCm();
  msg.angular.y = ext_right_sensor.measureDistanceCm();
  msg.angular.z = mDirection;
  chatter.publish(&msg);
  nh.spinOnce();
  delay(1);
}
