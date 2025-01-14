#include <DFRobot_QMC5883.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

DFRobot_QMC5883 compass(&Wire, /*I2C addr*/QMC5883_ADDRESS);
float yaw;
geometry_msgs::Twist str_msg;
ros::Publisher chatter("bot", &str_msg);
ros::NodeHandle nh;
void setup() {
  compass.begin();
  nh.initNode();
  nh.advertise(chatter);
}

void loop() {
  float declinationAngle = (-77 + (0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
  float yaw  = mag.HeadingDegress;
  Serial.println(yaw);
  if (yaw < 10 || yaw > 350)
  {
    str_msg.angular.z = round(yaw);
  }
  else
  {
    float error = 0.000910536 * (yaw * yaw) - 0.292766 * yaw - 2.95928;
    yaw  = yaw + (error);
    str_msg.angular.z = round(yaw);
  }
  Serial.println(yaw);
  str_msg.angular.x = 0;
  str_msg.angular.y = 125;
  chatter.publish( &str_msg );
  delay(10);
  nh.spinOnce();
}
