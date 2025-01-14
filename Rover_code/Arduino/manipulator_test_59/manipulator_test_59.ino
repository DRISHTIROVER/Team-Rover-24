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
ros::NodeHandle nh;
void messageCb( const geometry_msgs::Twist& msg) {
  if (msg.angular.z == 0)
  {
    if (msg.linear.x == 2)
    {
      digitalWrite(base_dir_pin, LOW);
      digitalWrite(base_step_pin, HIGH);
      delayMicroseconds(50);
      digitalWrite(base_step_pin,LOW);
      delayMicroseconds(50);
    }
    else if (msg.linear.x == -2)
    {
      digitalWrite(base_dir_pin, HIGH);
      digitalWrite(base_step_pin, HIGH);
      delayMicroseconds(50);
      digitalWrite(base_step_pin, LOW);
      delayMicroseconds(50);
    }
    if (msg.linear.y == 1)
    {
      digitalWrite(wrist_dir_pin, LOW);
      digitalWrite(wrist_step_pin, HIGH);
      delayMicroseconds(55);
      digitalWrite(wrist_step_pin, LOW);
      delayMicroseconds(55);
    }
    else if (msg.linear.y == -1)
    {
      digitalWrite(wrist_dir_pin, HIGH);
      digitalWrite(wrist_step_pin, HIGH);
      delayMicroseconds(55);
      digitalWrite(wrist_step_pin, LOW);
      delayMicroseconds(55);
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
    if(msg.linear.z == 4)
    {
      analogWrite(finger_pwm_pin, 0);
    }

  }
}

ros::Subscriber<geometry_msgs::Twist> sub("/manipulator", &messageCb );
void setup() {
  nh.initNode();
  nh.subscribe(sub);
  pinMode(base_step_pin, OUTPUT);
  pinMode(base_dir_pin, OUTPUT);
  pinMode(base_enable_pin,OUTPUT);
  pinMode(wrist_step_pin, OUTPUT);
  pinMode(wrist_dir_pin, OUTPUT);
  pinMode(wrist_enable_pin,OUTPUT);
  pinMode(act1_dir_pin, OUTPUT);
  pinMode(act1_pwm_pin, OUTPUT);
  pinMode(act2_dir_pin, OUTPUT);
  pinMode(act2_pwm_pin, OUTPUT);
  pinMode(finger_dir_pin,OUTPUT);
  pinMode(finger_pwm_pin,OUTPUT);
  digitalWrite(base_enable_pin,LOW);
  digitalWrite(wrist_enable_pin,LOW);
}

void loop() {
  nh.spinOnce();
}
