#include <ros.h>
#include <geometry_msgs/Twist.h>
ros::NodeHandle nh;
int none, ntwo, oone, otwo = 0;
float stone, sttwo, xone, xtwo = 0;
int done, dtwo, ione, itwo = 0;
void roverCallBack(const geometry_msgs::Twist& cmd_vel)
{
  oone = xone;
  otwo = xtwo;
  none = cmd_vel.linear.x;
  ntwo = cmd_vel.linear.y;
  if (none < 0) {
    none = -none;
    done = 0;
  }
  else if (none == 0) {
    done = done;
  }
  else {
    done = 1;
  }
  if (ntwo < 0) {
    ntwo = -ntwo;
    dtwo = 0;
  }
  else if (ntwo == 0) {
    dtwo = dtwo;
  }
  else {
    dtwo = 1;
  }
  if (none > 255 || none < 0) {
    none = 0;
  }
  if (ntwo > 255 || ntwo < 0) {
    ntwo = 0;
  }
  stone = (none - oone) / 5.;
  sttwo = (ntwo - otwo) / 5.;

  ione = 0;
  itwo = 0;
}

geometry_msgs::Twist msg;
ros::Publisher ultra("/imu", &msg);
ros::Subscriber <geometry_msgs::Twist> sub("/cmd_vel", roverCallBack);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  digitalWrite(2, 0);
  digitalWrite(4, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);

  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(ultra);
}

void loop() {
  if (xone != none) {
    xone = stone * ione + oone;
    ione = ione + 1;
    if (xone > 255 || xone < 0) {
      xone = 0;
      oone = 0;
    }
    msg.linear.x = xone;
    analogWrite(3, xone);
    analogWrite(9, xone);

  }
  if (xtwo != ntwo) {
    xtwo = sttwo * itwo + otwo;
    itwo = itwo + 1;
    if (xtwo > 255 || xtwo < 0) {
      xtwo = 0;
      otwo = 0;
    }
    msg.linear.y = xtwo;
    analogWrite(6, xtwo);
    analogWrite(5, xtwo);
  }
  digitalWrite(8, done);
  digitalWrite(2, done);
  digitalWrite(4, !dtwo);
  digitalWrite(7, dtwo);

  //  msg.linear.z = ione;
  msg.angular.x = done;
  msg.angular.y = dtwo;
  //  msg.angular.z = stone;
  ultra.publish(&msg);
  nh.spinOnce();
}
