#include <HCSR04.h>

//UltraSonicDistanceSensor ext_left(22, 23);
//UltraSonicDistanceSensor left(49, 51);
//UltraSonicDistanceSensor centre_left(45, 43);
//UltraSonicDistanceSensor centre_right(39, 37);
//UltraSonicDistanceSensor right(31, 33);
//UltraSonicDistanceSensor ext_right(25, 27);
UltraSonicDistanceSensor ext_left(45, 47);
UltraSonicDistanceSensor left(41, 43);
UltraSonicDistanceSensor centre_left(39, 37);
UltraSonicDistanceSensor centre_right(31, 33);
UltraSonicDistanceSensor right(29, 27);
UltraSonicDistanceSensor ext_right(25, 23);
void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    Serial.print("1=");// Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    Serial.println(right.measureDistanceCm());
    Serial.print("2=");
    Serial.println(centre_left.measureDistanceCm());
    Serial.print("3=");
    Serial.println(centre_right.measureDistanceCm());
    Serial.print("4=");
    Serial.println(left.measureDistanceCm());
    Serial.print("5=");
    Serial.println(ext_left.measureDistanceCm());
    Serial.print("6=");
    Serial.println(ext_right.measureDistanceCm());
    delay(500);
}
