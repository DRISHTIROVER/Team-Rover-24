const int steps[3] = {A0,A2,A4};
const int dirs[3] = {A1,A3,A5};
void setup() {
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(4,INPUT);
  pinMode(8,INPUT);
  pinMode(steps,OUTPUT);
  pinMode(dirs,OUTPUT);
}

void loop() {
  int pin1 = digitalRead(7);
  int pin2 = digitalRead(6);
  int pin3 = digitalRead(4);
  int pin4 = digitalRead(8);
  int motor = pin2 + pin1*2;
  digitalWrite(dirs[motor-1],pin3);
  int pwm = 300+pin4*200;
  if(motor!=0)
  {
    digitalWrite(steps[motor-1],HIGH);
    delayMicroseconds(pwm);
    digitalWrite(steps[motor-1],LOW);
    delayMicroseconds(pwm);
    
  }
  

}
