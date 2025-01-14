/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/UInt64.h>
#include <std_msgs/Float64.h>
#include <string.h>
ros::NodeHandle  nh;

std_msgs::UInt64 distance;
std_msgs::Float64 duration;
ros::Publisher chatter("chatter", &distance);
void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  digitalWrite(3,LOW);
  delay(0.002);
  digitalWrite(3,HIGH);
  delay(0.01);
  duration.data = pulseIn(2,HIGH); 
  nh.spinOnce();
  distance.data = (0.034*((duration.data)))/2;
  chatter.publish( &distance );
  nh.spinOnce();
}
