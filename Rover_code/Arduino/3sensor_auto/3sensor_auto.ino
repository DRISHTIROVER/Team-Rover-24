#include <HCSR04.h>
UltraSonicDistanceSensor right_sensor(13, 10);
UltraSonicDistanceSensor centre_sensor(12,9);
UltraSonicDistanceSensor left_sensor(11,8);
#define dir_left 2
#define pwm_left 3
#define dir_right 4
#define pwm_right 5


void setup () {
  pinMode(dir_left, OUTPUT);
  pinMode(dir_right,OUTPUT);
  pinMode(pwm_left, OUTPUT);
  pinMode(pwm_right,OUTPUT);
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}
void set_dir(int dir) // Set pins to high or low to decide direction
{
  if(dir == 0)
  {
    digitalWrite(dir_left,HIGH);
    digitalWrite(dir_right,LOW);
  }
  else if(dir == 1)
  {
    digitalWrite(dir_left, LOW);
    digitalWrite(dir_right,HIGH);
  }
}
int set_move(int speed) // set speed on each motor
{
  digitalWrite(dir_left, LOW);
  digitalWrite(dir_right,LOW);
  analogWrite(pwm_left, speed);
  analogWrite(pwm_right,speed);
  return 0;
}
void left()
{
  set_dir(0);
  set_move(60);
}
void right()
{
  set_dir(1);
  set_move(60);
}
void forward()
{
  set_move(60);
}
void sharp_right(int speed)
{
    digitalWrite(dir_left,LOW);
    digitalWrite(dir_right,HIGH);
    analogWrite(pwm_left, speed);
    analogWrite(pwm_right,0);
}
void sharp_left(int speed)
{
    digitalWrite(dir_left,HIGH);
    digitalWrite(dir_right,LOW);
    analogWrite(pwm_left, 0);
    analogWrite(pwm_right, speed);
}
void loop()
{
int r2 = centre_sensor.measureDistanceCm();
int r1 = left_sensor.measureDistanceCm();
int r3 = right_sensor.measureDistanceCm();
  Serial.println(r1);
  Serial.println(r2);
  Serial.println(r3);
if(r2<30)
{
  if(r1<20 && r3<20)
  {
    if(r1>r3)
    {
      Serial.println("Sharp right");
    }
    else
    {
      Serial.println("Sharp left");
    }
  }
  else
  {
    if(r3<20)
    {Serial.println("left");
    }
    else
    {Serial.println("Right");
    }
  }
  
}
else
{
  Serial.println("Forward");
  forward();
}

delay(2000);
}
