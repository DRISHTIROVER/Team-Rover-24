#define dir_left 7
#define pwm_left 6
#define dir_right 4
#define pwm_right 3

void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);

  pinMode(dir_left, OUTPUT);
  pinMode(dir_right,OUTPUT);
  pinMode(pwm_left, OUTPUT);
  pinMode(pwm_right,OUTPUT);
  delay(5000);
}
int set_move(int speed) // set speed on each motor
{
  analogWrite(pwm_left, speed);
  analogWrite(pwm_right,speed);
  return 0;
}

void set_dir(int dir) // Set pins to high or low to decide direction
{
  if(dir == 0)
  {
    digitalWrite(dir_left,HIGH);
    digitalWrite(dir_right,LOW);
  }
  else if(dir == 1)
  {
    digitalWrite(dir_left, LOW);
    digitalWrite(dir_right,HIGH);
  }
}
void loop() {
    delay(3000);
    set_dir(0); // set direction to forward
    int speed = 100;
    set_move(speed);
    delay(3000);
    speed = 0;
    set_move(speed); // stop!
    delay(1000);
  
    set_dir(1);
    speed = 100;
    set_move(speed);
    delay(2000);
  
    speed = 0; 
    set_move(speed);
}
