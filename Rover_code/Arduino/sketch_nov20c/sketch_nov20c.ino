#define act1_dir_pin 
#define act1_pwm_pin 2

void setup() {
pinMode(43,OUTPUT);
pinMode(8,OUTPUT);
}

void loop() {
 digitalWrite(43,0);
 analogWrite(8,100);
}
