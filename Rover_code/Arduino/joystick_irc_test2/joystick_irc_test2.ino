#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;
bool dir1 = 0;
bool dir2 = 0;
bool dir3 = 0;
bool dir4 = 0;
float pwm1 = 0;
float pwm2 = 0;
float pwm3 = 0;
float pwm4 = 0;
void messageCb( const geometry_msgs::Twist& joy_msg) {
  if (joy_msg.angular.z == 1)
  {
    pwm1 = pwm2 = abs(joy_msg.angular.x);
    pwm3 = pwm4 = abs(joy_msg.angular.y);
    if (joy_msg.angular.x >= 0)
    {
      dir1 = 0;
      dir2 = 1;
    }
    else if (joy_msg.angular.x < 0)
    {
      dir1 = 1;
      dir2 = 0;
    }
    if (joy_msg.angular.y >= 0)
    {
      dir3 = 1;
      dir4 = 0;
    }
    else if (joy_msg.angular.y < 0)
    {
      dir3 = 0;
      dir4 = 1;
    }
    analogWrite(12, pwm1);
    analogWrite(9, pwm2);
    analogWrite(6, pwm3);
    analogWrite(3, pwm4);
    digitalWrite(13, dir1);
    digitalWrite(10, dir2);
    digitalWrite(7, dir3);
    digitalWrite(4, dir4);

  }
}
ros::Subscriber<geometry_msgs::Twist> sub("/manipulator", &messageCb );

void setup()
{
  nh.initNode();
  nh.subscribe(sub);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
