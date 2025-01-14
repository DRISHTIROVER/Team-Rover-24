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
  Serial.println(r3);}
