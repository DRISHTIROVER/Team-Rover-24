#include<Servo.h>
Servo A;
int poten=1500;

void setup() {
  // put your setup code here, to run once:
        A.attach(9,1000,2000);
        Serial.begin(9600);
        pinMode(A2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
      delay(5);
      Serial.println(analogRead(A2));
}
