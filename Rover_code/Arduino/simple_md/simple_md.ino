#include <HCSR04.h>
UltraSonicDistanceSensor right_sensor(13, 10);
UltraSonicDistanceSensor centre_sensor(12,9);
UltraSonicDistanceSensor left_sensor(11,8);
#define dir_left 2
#define pwm_left 3
#define dir_right 4
#define pwm_right 5
#define max_front_distance 25

void setup () {
  pinMode(dir_left, OUTPUT);
  pinMode(dir_right,OUTPUT);
  pinMode(pwm_left, OUTPUT);
  pinMode(pwm_right,OUTPUT);
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}
void left()
{
  digitalWrite(dir_left,LOW);
  digitalWrite(dir_right,HIGH);
  analogWrite(pwm_right,0);
  analogWrite(pwm_left,80);
}
void right()
{
  digitalWrite(dir_left,HIGH);
  digitalWrite(dir_right,LOW);
  analogWrite(pwm_right,80);
  analogWrite(pwm_left,0);
}
void forward()
{
  digitalWrite(dir_left,LOW);
  digitalWrite(dir_right,LOW);
  analogWrite(pwm_right,80);
  analogWrite(pwm_left,80);
}
void backward()
{
  digitalWrite(dir_left,HIGH);
  digitalWrite(dir_right,HIGH);
  analogWrite(pwm_right,80);
  analogWrite(pwm_left,80);
}
void sharp_right(int speed)
{
    digitalWrite(dir_left,HIGH);
    digitalWrite(dir_right,LOW);
    analogWrite(pwm_left, speed);
    analogWrite(pwm_right,speed);
    delay(5000);
}
void sharp_left(int speed)
{
    digitalWrite(dir_left,LOW);
    digitalWrite(dir_right,HIGH);
    analogWrite(pwm_left, speed);
    analogWrite(pwm_right, speed);
    delay(5000);
}
void loop()
{
  if(left_sensor.measureDistanceCm() < 0 || centre_sensor.measureDistanceCm()<0 || right_sensor.measureDistanceCm() <0)
  return;
  bool r1,r2,r3;
  if(left_sensor.measureDistanceCm()<15)
  r1 = 1;
  else r1 = 0;
  if(right_sensor.measureDistanceCm()<15)
  r3 = 1;
  else r3 = 0;
  if(centre_sensor.measureDistanceCm()<20)
  r2 = 1;
  else r2 = 0;
  bool x = (r1&&~r3)||(r1&&r2);
  bool y = (r2&&r3);
  if(x == 0 && y == 0)
  forward();
  if(x == 0 && y== 1)
  left();
  if(x == 1 && y == 0)
  right();
  if(x == 1 && y == 1)
  backward();
  
  
}
