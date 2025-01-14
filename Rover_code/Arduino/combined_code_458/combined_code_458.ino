#include <ros.h>
#include <geometry_msgs/Twist.h>
#define base_enable_pin 51
#define base_step_pin 45
#define base_dir_pin 49
#define wrist_step_pin 27
#define wrist_dir_pin 29
#define wrist_enable_pin 51
#define act1_dir_pin 43
#define act1_pwm_pin 8
#define act2_dir_pin 37
#define act2_pwm_pin 5
#define finger_dir_pin 35
#define finger_pwm_pin 2
bool dir1 = 0;
bool dir2 = 0;
bool dir3 = 0;
bool dir4 = 0;
float pwm1 = 0;
float pwm2 = 0;
float pwm3 = 0;
float pwm4 = 0;
ros::NodeHandle nh;
void messageCb( const geometry_msgs::Twist& msg) {
  if (msg.angular.z == 0)
  {
    if (msg.linear.x == 2)
    {
      digitalWrite(base_dir_pin, HIGH);
      digitalWrite(base_step_pin, HIGH);
    }
    else if (msg.linear.x == -2)
    {
      digitalWrite(base_dir_pin, LOW);
      digitalWrite(base_step_pin, HIGH);
    }
    else if (msg.linear.x == 0)
    {
      digitalWrite(base_step_pin, LOW);
      digitalWrite(base_dir_pin, LOW);
    }
    if (msg.linear.y == 1)
    {
      digitalWrite(wrist_dir_pin, LOW);
      digitalWrite(wrist_step_pin, HIGH);
    }
    else if (msg.linear.y == -1)
    {
      digitalWrite(wrist_dir_pin, HIGH);
      digitalWrite(wrist_step_pin, HIGH);
    }
    else if (msg.linear.y == 0)
    {
      digitalWrite(wrist_step_pin, LOW);
      digitalWrite(wrist_dir_pin, LOW);
    }
    if (msg.angular.x >= 0)
    {
      digitalWrite(act1_dir_pin, LOW);
      analogWrite(act1_pwm_pin, msg.angular.x);
    }
    else if (msg.angular.x < 0)
    {
      digitalWrite(act1_dir_pin, HIGH);
      analogWrite(act1_pwm_pin, -msg.angular.x);
    }
    if (msg.angular.y >= 0)
    {
      digitalWrite(act2_dir_pin, LOW);
      analogWrite(act2_pwm_pin, msg.angular.y);
    }
    else if (msg.angular.y < 0)
    {
      digitalWrite(act2_dir_pin, HIGH);
      analogWrite(act2_pwm_pin, -msg.angular.y);
    }
    if (msg.linear.z == 3)
    {
      digitalWrite(finger_dir_pin, LOW);
      analogWrite(finger_pwm_pin, 200);
    }
    else if (msg.linear.z == -3)
    {
      digitalWrite(finger_dir_pin, HIGH);
      analogWrite(finger_pwm_pin, 200);
    }
    if (msg.linear.z == 4)
    {
      analogWrite(finger_pwm_pin, 0);
    }

  }
  else if (msg.angular.z == 1)
  {
    pwm1 = pwm2 = abs(msg.angular.x);
    pwm3 = pwm4 = abs(msg.angular.y);
    if (msg.angular.x >= 0)
    {
      dir1 = 0;
      dir2 = 1;
    }
    else if (msg.angular.x < 0)
    {
      dir1 = 1;
      dir2 = 0;
    }
    if (msg.angular.y >= 0)
    {
      dir3 = 1;
      dir4 = 0;
    }
    else if (msg.angular.y < 0)
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
void setup() {
  nh.initNode();
  nh.subscribe(sub);
  pinMode(base_step_pin, OUTPUT);
  pinMode(base_dir_pin, OUTPUT);
  pinMode(wrist_step_pin, OUTPUT);
  pinMode(wrist_dir_pin, OUTPUT);
  pinMode(act1_dir_pin, OUTPUT);
  pinMode(act1_pwm_pin, OUTPUT);
  pinMode(act2_dir_pin, OUTPUT);
  pinMode(act2_pwm_pin, OUTPUT);
  pinMode(finger_dir_pin, OUTPUT);
  pinMode(finger_pwm_pin, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  nh.spinOnce();
  delay(1);
}
