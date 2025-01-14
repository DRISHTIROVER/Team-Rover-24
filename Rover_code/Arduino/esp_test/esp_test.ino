int m1dir = 5;
int m1pwm = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);//Link-01 Actuator-Dir
  pinMode(4,OUTPUT);//Link-01 Actuator-PWM
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(5,LOW);
 digitalWrite(4,HIGH);
}
