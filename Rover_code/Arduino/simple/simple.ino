#include "MPU9250.h"
#include <HCSR04.h>
MPU9250 mpu;
UltraSonicDistanceSensor hc1(50,52 );
UltraSonicDistanceSensor hc3(38, 40);
UltraSonicDistanceSensor hc5(34, 36);
void setup() {
    Serial.begin(9600);
    Wire.begin();
    delay(2000);
mpu.setup(0x68);
}

void loop() {
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
          print_roll_pitch_yaw();
            prev_ms = millis();
        }
    }
    Serial.println('hc1:');
    Serial.println(hc1.measureDistanceCm());
    Serial.println('hc3:');
    Serial.println(hc3.measureDistanceCm());
    Serial.println('hc5:');
    Serial.println(hc5.measureDistanceCm());
}

void print_roll_pitch_yaw() {
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    
}
