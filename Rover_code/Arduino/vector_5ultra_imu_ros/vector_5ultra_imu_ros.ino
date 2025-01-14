#include <ros.h>
#include <HCSR04.h>
#include "Complex.h"
#include <DFRobot_QMC5883.h>
#include <geometry_msgs/Twist.h>
UltraSonicDistanceSensor ext_left(45, 47);
UltraSonicDistanceSensor left(41, 43);
UltraSonicDistanceSensor centre_left(39, 37);
UltraSonicDistanceSensor centre_right(31, 33);
UltraSonicDistanceSensor right(29, 27);
UltraSonicDistanceSensor ext_right(25, 23);
ros::NodeHandle nh;
geometry_msgs::Twist msg;
ros::Publisher chatter("/bot", &msg);
int r1, r2, r3, r4, r5, r6, r0 = 0;
DFRobot_QMC5883 compass(&Wire, 0x0D);

void setup() {
  nh.initNode();
  nh.advertise(chatter);
  compass.begin();
  compass.isQMC();
}

void loop() {
  r0 = ext_left.measureDistanceCm();
  r1 = left.measureDistanceCm();
  r3 = right.measureDistanceCm();
  r4 = ext_right.measureDistanceCm();
  r5 = centre_left.measureDistanceCm();
  r6 = centre_right.measureDistanceCm();
  Complex c0(0, r0);
  Complex c1(r1 * 0.707, r1 * 0.707);
  //Complex c2(r2*0, r2*0); this not needed since it is always zero
  Complex c3(r3 * 0.707, -r3 * 0.707);
  Complex c4(0, -r4);
  Complex c = c0 + c1 + c3 + c4;
  int thetha = round((atan(c.imag() / c.real())) * 180.0) / 3.1416; //285 for range between 0 to 180 degrees
  float declinationAngle = (-77 + (0.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
  float yaw  = mag.HeadingDegress;
  Serial.println(yaw);
  float error = 0.000475821 * yaw * yaw - 0.357439 * yaw + 38.7651;
  yaw  = yaw - (error);
  msg.angular.z = round(yaw);
  Serial.print(error);
  Serial.print("  ");
  Serial.println(yaw);
  //  msg.linear.y = c.imag();
  if (r5 < r6)
    msg.angular.y = r5;
  else if (r6 < r5)
    msg.angular.y = -r6;
  else {
    msg.angular.y = 200;
  }
  msg.angular.x = thetha;
  //Serial.println(r3);
  chatter.publish(&msg);
  nh.spinOnce();
  delay(10);
}
