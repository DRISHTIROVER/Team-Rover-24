bool dir1;
bool dir2;
bool dir3;
bool dir4;
float pwm1;
float pwm2;
float pwm3;
float pwm4;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
}

void loop() {
  analogWrite(2, 200);
  analogWrite(3, 200);
  analogWrite(4, 200);
  analogWrite(5, 200);
  digitalWrite(22, 1);
  digitalWrite(24, 0);
  digitalWrite(26, 0);
  digitalWrite(28, 1); // put your main code here, to run repeatedly:

}
