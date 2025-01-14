const int LEDPin = 2;  /* GPIO16 */

int dutyCycle;
/* Setting PWM Properties */
const int PWMFreq = 5000; /* 5 KHz */
const int PWMChannel = 0;
const int PWMResolution = 8;
const int MAX_DUTY_CYCLE = (int)(pow(2, PWMResolution) - 1);
void setup()
{  
  Serial.begin(9600);
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  /* Attach the LED PWM Channel to the GPIO Pin */
  ledcAttachPin(LEDPin, PWMChannel);
}
void loop()
{
  /* Increasing the LED brightness with PWM */
  for(dutyCycle = 0; dutyCycle <= MAX_DUTY_CYCLE; dutyCycle++)
  {
    Serial.println(MAX_DUTY_CYCLE);
    ledcWrite(PWMChannel, 125);
    delay(3);
    //delayMicroseconds(100);
  }
}
