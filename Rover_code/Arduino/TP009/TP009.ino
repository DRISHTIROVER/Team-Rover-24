#include <HCSR04.h>

UltraSonicDistanceSensor right(13, 10);
UltraSonicDistanceSensor centre(12, 9);
UltraSonicDistanceSensor left(11, 8);
#define dir1 2
#define pwm1 3
#define dir2 4
#define pwm2 5

void setup () {
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop () {

  float r1 = left.measureDistanceCm();
  float r2 = centre.measureDistanceCm();
  float r3 = right.measureDistanceCm();
  Serial.println("r1:");
  Serial.println(r1);
  Serial.println("r2");
  Serial.println(r2);
  Serial.println("r3");
  Serial.println(r3);

if (r1 >= 30 || r1 == -1)
r1 = 30;
if (r2 >= 30 || r2 == -1)
r2 = 30;
if (r3 >= 30 || r3 == -1)
r3 = 30;
if(r2 < 10)
{
  digitalWrite(dir2, HIGH);
  digitalWrite(dir1, HIGH);
  analogWrite(pwm2,80);
  analogWrite(pwm1,80);
  delay(800);
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  delay(300);
  digitalWrite(dir2, HIGH);
  digitalWrite(dir1, LOW);
  delay(500);
  analogWrite(pwm1,80);
  analogWrite(pwm2,80);
  Serial.println("sleft");
  delay(1500);  
}

if(r1 == 30 && r2 == 30 && r3 ==30)
{

  digitalWrite(dir2, LOW);
  digitalWrite(dir1, LOW);
  analogWrite(pwm2,60);
  analogWrite(pwm1,60);
  Serial.println("forward");
}


else
{
float k = (r1 - r3)/(r1 + r3);
if (k > 0.5 && k< 1)
{
  digitalWrite(dir2, LOW);
  digitalWrite(dir1, LOW);
  analogWrite(pwm2,80*(k));
  analogWrite(pwm1,80*1.1*k);
  Serial.println("left");
}
else if(k > 0 && k <= 0.5)
{
  digitalWrite(dir2, HIGH);
  digitalWrite(dir1, LOW);
  map(k,0,0.5,45,120);
  analogWrite(pwm1,(k));
  analogWrite(pwm2,(k));
  Serial.println("sleft");

}

else if (k > -0.5 && k<= 0)
{
  digitalWrite(dir2, LOW);
  digitalWrite(dir1, HIGH);
  map(k,-0.5,0,45,120);
  analogWrite(pwm2,k);
  analogWrite(pwm1,k);
  Serial.println("sright");
}

else if (k > -1 && k<= -0.5)
{
  digitalWrite(dir2, LOW);
  digitalWrite(dir1, LOW);
  analogWrite(pwm2,80*(-1.1*k));
  analogWrite(pwm1,80*(-k));
  Serial.println("right");
}
}
}
