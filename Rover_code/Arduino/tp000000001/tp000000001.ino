#include <HCSR04.h>
UltraSonicDistanceSensor right(13, 10);
UltraSonicDistanceSensor centre(12,9);
UltraSonicDistanceSensor left(11,8);

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop()
{
int r2 = centre.measureDistanceCm();
int r1 = left.measureDistanceCm();
int r3 = right.measureDistanceCm();
Serial.println("r1");
  Serial.println(r1);
  Serial.println("r2");
  Serial.println(r2);
  Serial.println("r3");
  Serial.println(r3);
}
