int inputdir = 4;

int outputpwm = 5;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(4, OUTPUT);//Link-01 Actuator-Dir
  pinMode(5,OUTPUT);//Link-01 Actuator-PWM
}

void loop() {
 digitalWrite(4,HIGH);
 digitalWrite(5,HIGH);
 delay(0.5);
 digitalWrite(5,LOW);
 delay(0.5);
}
