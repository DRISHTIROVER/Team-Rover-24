#include <Servo.h>
String msg1 = "Enter the angle1:";
String msg2 = "Enter the angle2:";
float angle1;
float angle2;
Servo servo1;
Servo servo2;

void setup()
{
  Serial.begin(9600);
  servo1.attach(5);
  servo2.attach(7);
}

void loop()
{
  Serial.println(msg1);
  while(Serial.available()==0)
  {}
  angle1 = Serial.parseFloat();
  angle2 = Serial.parseFloat();
  delay(30);
  float step1 = angle1/1000;
  float temp1 = step1;
  float step2 = angle2/1000;
  float temp2 = step2;
  for(int i = 0;i<1000;i++)
  {
     servo1.write(step1);
     step1  = step1 + temp1;
     servo2.write(step2);
     step2 = step2 + temp2;
     delay(20);
  }
  
  
}
