#include <ros.h>
#include <HCSR04.h>
#include "MPU9250.h"
#include <geometry_msgs/Twist.h>
MPU9250 mpu;
UltraSonicDistanceSensor hc1(38, 40);
UltraSonicDistanceSensor hc2(34,36);
UltraSonicDistanceSensor hc3(30,32);
ros::NodeHandle nh;
geometry_msgs::Twist msg;
ros::Publisher chatter("/bot", &msg);
void setup() {
    Wire.begin();
    delay(2000);
    nh.initNode();
    nh.advertise(chatter);
    mpu.setup(0x68);
    
}

void loop() {
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            prev_ms = millis();
        }
    }
    msg.linear.x = mpu.getYaw()+22.3;
    msg.linear.y = mpu.getRoll();
    msg.linear.z = mpu.getPitch();
    msg.angular.x = hc3.measureDistanceCm();
    msg.angular.y = hc2.measureDistanceCm();
    msg.angular.z = hc1.measureDistanceCm();
    chatter.publish(&msg);
    nh.spinOnce();

}
