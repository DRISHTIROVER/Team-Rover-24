const int stepPin = 2;
const int dirPin = 15;
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
//  pinMode(enPin, OUTPUT);
//  digitalWrite(enPin, LOW);
  //Serial.begin(9600);'
  digitalWrite(dirPin,HIGH);
}

void loop() 
{

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(300);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(300);
    }
