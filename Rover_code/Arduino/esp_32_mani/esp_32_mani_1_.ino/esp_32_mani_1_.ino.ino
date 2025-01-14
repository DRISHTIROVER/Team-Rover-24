#include "WiFi.h"
int m1dir = 4;
int m2dir = 15;
int m3dir = 18;
int m4dir = 21;
int m5dir = 13;
int m6dir = 14;

int m1ena = 5;
int m2ana = 2;
int m3ana = 19;
int m4ana = 22;
int m5ana = 12;
int m6ana = 27;
//motor 4 try low rpm to improve torque
int svalue = 200;
int x= 30;

const char* ssid = "ROVER_LINK_EXT_2.4G";
const char* password =  "Vihaan1234";

WiFiServer wifiServer(6677);
int b = 0;
int d, c = 0;
char a;
void setup() {

  Serial.begin(115200);
  pinMode(15, OUTPUT);//Link-01 Actuator-Dir
  pinMode(2,OUTPUT);//Link-01 Actuator-PWM
  pinMode(14,OUTPUT);//arm single motor-Dir
  pinMode(27,OUTPUT);//arm single motor-PWM
  pinMode(13,OUTPUT);//DC motor wrist-Dir
  pinMode(12,OUTPUT);//DC motor wrist-PWM
  pinMode(21,OUTPUT);//Pulley DC Motor-Dir
  pinMode(22,OUTPUT);//Pulley DC Motor-PWM
  pinMode(18,OUTPUT);//Actuator-02-Dir
  pinMode(19,OUTPUT);//Actuator-02-PWM
  pinMode(4,OUTPUT);//stepper-Dir
  pinMode(5,OUTPUT);//stepper-pulse
  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
}

void loop() {

  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {

      while (client.available() > 0) {
        a = client.read();
        b = a - '0';
        if (b > 2 && b < 10)
        {
          c = b;
          Serial.print("X = ");
          Serial.println(b);
        }
        if (b < 3 && b > -1) {
          d = b;
          Serial.print("Y = ");
          Serial.println(d);
        }
      }
      Serial.println(c);
      if (c == 4) {//........................motor4 DC
      Serial.println("motor4");
        if (d == 0) {
          digitalWrite(m4dir, LOW);
          analogWrite(m4ana, 255);
        }
        else if (d == 1) {
          analogWrite(m4ana, 40);//........do not use this motor currently
        }
        else if (d == 2) {
          digitalWrite(m4dir, HIGH);
          analogWrite(m4ana, 255);
        }
      }
      if (c == 5) {//........................motor5 DC
      Serial.println("motor5");
        if (d == 0) {
          digitalWrite(m5dir, LOW);
          analogWrite(m5ana, 150);
        }
        else if (d == 1) {
          analogWrite(m5ana, 0);
        }
        else if (d == 2) {
          digitalWrite(m5dir, HIGH);
          analogWrite(m5ana, 150);
        }
      }
      if (c == 6) {//........................motor6 planatary
      Serial.println("motor6");
        if (d == 0) {
          digitalWrite(m6dir, LOW);
          analogWrite(m6ana, svalue);
        }
        else if (d == 1) {
          analogWrite(m6ana, 0);
        }
        else if (d == 2) {
          digitalWrite(m6dir, HIGH);
          analogWrite(m6ana, svalue);
        }
      }
      if (c == 3) {//........................motor1 stepper
      Serial.println("motor1");
        if (d == 0) {
          digitalWrite(m1ena, HIGH);                           
          delayMicroseconds(200);
          digitalWrite(m1ena, LOW);
          delayMicroseconds(200);
        }
        else if (d == 1) {
          digitalWrite(m1ena, 0);
        }
        else if (d == 2) {
          digitalWrite(m1dir, HIGH);
          digitalWrite(m1ena, HIGH);
          delayMicroseconds(200);
          digitalWrite(m1ena, LOW);
          delayMicroseconds(200);
        }
      }
      if (c == 7) {//........................motor2 linear
      
        if (d == 0) {
          digitalWrite(m2dir, LOW);
          analogWrite(m2ana, svalue);
          Serial.println("motor2");
        }
        else if (d == 1) {
          analogWrite(m2ana, 0);
          Serial.println("motor2.");
        }
        else if (d == 2) {
          digitalWrite(m2dir, HIGH);
          analogWrite(m2ana, svalue);
          Serial.println("motor2..");
        }
      }
      if (c == 8) {//........................motor3 linear
        
        if (d == 0) {
          digitalWrite(m3dir, LOW);
          analogWrite(m3ana, svalue);
          Serial.println("motor3");
        }
        else if (d == 1) {
          analogWrite(m3ana, 0);
          Serial.println("motor3.");
        }
        else if (d == 2) {
          digitalWrite(m3dir, HIGH);
          analogWrite(m3ana, svalue);
          Serial.println("motor3..");
        }
      }
      if (c == 9) {//........................STOP
        if (d == 0) {
          svalue = svalue - x;
          d = 1;
          Serial.print("...................");
          Serial.println(svalue);
        }
        else if (d == 1) {
          analogWrite(m1ena, 0);
          analogWrite(m2ana, 0);
          analogWrite(m3ana, 0);
          analogWrite(m4ana, 0); //......................issues
          analogWrite(m5ana, 0);
          analogWrite(m6ana, 0);
          Serial.println("System HOLD!");
        }
        else if (d == 2) {
          svalue = svalue + x;
          d = 1;
          Serial.print("...................");
          Serial.println(svalue);
        }
      }
      //delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}
