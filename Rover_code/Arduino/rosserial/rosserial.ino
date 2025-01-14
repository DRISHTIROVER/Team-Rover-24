#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <HCSR04.h>
#define dir1 2
#define pwm1 3
#define dir2 4
# define pwm2 5
ros::NodeHandle  nh;
geometry_msgs::Twist msg;
void forward(float spwm1,int spwm2,int sdir1,int sdir2) {
  digitalWrite(2, sdir1);
  analogWrite(3, spwm1);
  digitalWrite(4, sdir2);
  analogWrite(5, spwm2);
}
void message(const geometry_msgs::Twist& vel){ 
  forward( vel.linear.x,vel.linear.y,vel.linear.z,vel.angular.x);  
}

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel",message);
void setup(){
  Serial.begin(9600);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}

  
