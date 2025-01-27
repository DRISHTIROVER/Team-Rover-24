#include <Servo.h>
Servo esc_signal;

void setup()
{
  esc_signal.attach(12);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);            //ESC initialization delay.
}

void loop()
{
  for (int i = 0; i < 130; i++) 
  {
    esc_signal.write(i);
    delay(100);
  }   //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.

}
