#include <DFRobot_QMC5883.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

DFRobot_QMC5883 compass(&Wire, /*I2C addr*/QMC5883_ADDRESS);
float yaw;
ros::NodeHandle nh;
void anteenaCallBack(const geometry_msgs::Twist& anteena_yaw)
{
  float vx = anteena_yaw.linear.x ;
  float vy = anteena_yaw.linear.y ;
  float ay = anteena_yaw.linear.z;
  
}
std_msgs::Float32 str_msg;
geometry_msgs::Twist msg;
ros::Publisher chatter("yaw_anteena", &str_msg);
ros::Subscriber <geometry_msgs::Twist> sub("/anteena_stepper", anteenaCallBack);
void setup() {
  compass.begin();
  nh.initNode();
  nh.subscribe(sub);
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
