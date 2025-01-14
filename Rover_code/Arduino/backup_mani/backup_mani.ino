void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(2) == 1)
  {
    int dir1 = digitalRead(3);

    digitalWrite(6, dir1);
    digitalWrite(7, HIGH);
    delayMicroseconds(500);
    digitalWrite(7, LOW);
    delayMicroseconds(500);
    Serial.println("1");
  }
  if (digitalRead(4) == 1)
  {
    int dir2 = digitalRead(5);
    digitalWrite(8, dir2);
    digitalWrite(9, HIGH);
    delayMicroseconds(500);
    digitalWrite(9, LOW);
    delayMicroseconds(500);
    Serial.println("2");
  }

}
