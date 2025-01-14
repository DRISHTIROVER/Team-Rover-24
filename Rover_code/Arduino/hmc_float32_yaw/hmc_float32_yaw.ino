#include <DFRobot_QMC5883.h>
#include <ros.h>
#include <std_msgs/Float32.h>

DFRobot_QMC5883 compass(&Wire, /*I2C addr*/QMC5883_ADDRESS);
float yaw;
ros::NodeHandle nh;
std_msgs::Float32 str_msg;
ros::Publisher chatter("yaw_anteena", &str_msg);

void setup() {
  compass.begin();
  nh.initNode();
  nh.advertise(chatter);
}

void loop() {
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
  str_msg.data = mag.HeadingDegress; // - 28;
  chatter.publish(&str_msg);
  delay(10);
  nh.spinOnce();
}
