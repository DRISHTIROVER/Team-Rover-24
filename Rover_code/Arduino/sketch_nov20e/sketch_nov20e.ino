void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
 digitalWrite(2,LOW);
 pinMode(3,OUTPUT);
 digitalWrite(3,HIGH);
  pinMode(4,OUTPUT);
 //digitalWrite(4,LOW);
 pinMode(5,OUTPUT);
 digitalWrite(5,LOW);
  pinMode(6,OUTPUT);
 digitalWrite(6,LOW);
 pinMode(7,OUTPUT);
 //digitalWrite(7,LOW);
}

void loop() {

 //analogWrite(4,255);
   digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
   delayMicroseconds(800);
     digitalWrite(4,LOW);
      digitalWrite(7,LOW);
   delayMicroseconds(800);

}
