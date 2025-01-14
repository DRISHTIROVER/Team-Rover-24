#include <HCSR04.h>
#include "Complex.h"
UltraSonicDistanceSensor right_sensor(38, 40);
UltraSonicDistanceSensor centre_sensor(34, 36);
UltraSonicDistanceSensor left_sensor(30, 32);
UltraSonicDistanceSensor ext_left_sensor(24, 26);
UltraSonicDistanceSensor ext_right_sensor(42, 44);
#define dir1 2
#define pwm1 3
#define dir2 4
#define pwm2 5
float r1, r2, r3, r4, r0 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  r0 = ext_left_sensor.measureDistanceCm();
  r1 = left_sensor.measureDistanceCm();
  r2 = centre_sensor.measureDistanceCm();
  r3 = right_sensor.measureDistanceCm();
  r4 = ext_right_sensor.measureDistanceCm();
  //value so just to maximize the angle between resultant vectors
  Complex c0(0, -r0);
  Complex c1(r1 * 0.707, -r1 * 0.707);
  Complex c2(0, 0);
  Complex c3(r3 * 0.707, r3 * 0.707);
  Complex c4(0, r4);
  Complex c = c0 + c1 + c2 + c3 + c4;

  float ohm = (atan(c.imag() / c.real())) * 114.64968; //285 for range between 0 to 180 degrees
  //Serial.println(ohm);
  Serial.println(c) ;
  delay(150);
}
