/*
   rosserial::std_msgs::Float64 Test
   Receives a Float64 input, subtracts 1.0, and publishes it
*/

#include <ros.h>
#include <std_msgs/Float64.h>
#include <DFRobot_QMC5883.h>

float k, x = -77;
float diff, t;
ros::NodeHandle nh;

float b;
DFRobot_QMC5883 compass(&Wire,0x1E);
void messageCb( const std_msgs::Float64& msg) {
  b = msg.data;
  if (b > 0)
  {
    b = b - 180;
  }
  else
  {
    b = 180 - abs(b);
  }
}

std_msgs::Float64 test;
ros::Subscriber<std_msgs::Float64> s("/antenna", &messageCb);
ros::Publisher p("/yaw", &test);

void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  nh.initNode();
  nh.advertise(p);
  nh.subscribe(s);
  compass.begin();
}

void loop()
{

  float declinationAngle = (x + (0.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
  float yaw  = mag.HeadingDegress;

  if (10 < yaw < 350)
  {
    //float error = 0.000910536 * (yaw * yaw) - 0.292766 * yaw - 2.95928;
    //yaw  = yaw + (error);
    delay(10);
  }
  //k = yaw - 180;
  if (yaw < 180 && yaw > 0)
  {
    k = yaw;
  }
  else if (yaw > 180 && yaw < 360)
  {
    k = 180 - yaw;
  }
  test.data = b;
  p.publish(&test);
  diff = k + b;
  if (abs(diff) >  10)
  {
    test.data = diff;
    p.publish(&test);

    if (diff > 0)
    {
      digitalWrite(12, LOW);
      analogWrite(11, 30);
    }
    else if (diff < 0)
    {
      digitalWrite(12, HIGH);
      analogWrite(11, 30);
    }
  }
  test.data = k;
  p.publish(&test);

  nh.spinOnce();
}
