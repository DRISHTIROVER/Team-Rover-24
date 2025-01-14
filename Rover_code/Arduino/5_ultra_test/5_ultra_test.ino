#include <HCSR04.h>
//UltraSonicDistanceSensor right_sensor(37,39);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(45,OUTPUT);
  pinMode(39,OUTPUT);
}

void loop() {
//Serial.println(right_sensor.measureDistanceCm());
digitalWrite(45,HIGH);
//digitalWrite(39,HIGH);
}
