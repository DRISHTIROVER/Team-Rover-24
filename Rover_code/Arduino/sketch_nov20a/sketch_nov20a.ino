#define base_step_pin 45
#define base_dir_pin 49

void setup() {
  pinMode(base_step_pin, OUTPUT);
  pinMode(base_dir_pin, OUTPUT);
  digitalWrite(base_dir_pin,LOW);
}

void loop() {
  digitalWrite(base_step_pin,HIGH);
  delayMicroseconds(300);
  digitalWrite(base_step_pin,LOW);
  delayMicroseconds(300);
}
