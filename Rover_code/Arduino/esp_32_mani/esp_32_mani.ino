#include "WiFi.h"

const char* ssid = "t";
const char* password =  "31032001";

WiFiServer wifiServer(6677);
const int PIN1 = 7;
const int PIN2 = 6;
const int PIN3 = 4;
const int PIN4 = 8;
const int DC11 = 4;
const int DC12 = 2;
const int DC21 = 15;
const int DC22 = 24;
const int DC31 = 26;
const int DC32 = 27;

int PWM;
int ang = 180;

void setup() {

  Serial.begin(115200);

  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  pinMode(DC11, OUTPUT);
  pinMode(DC12, OUTPUT);
  pinMode(DC21, OUTPUT);
  pinMode(DC22, OUTPUT);
  pinMode(DC21, OUTPUT);
  pinMode(DC32, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

    
  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {
      
      

      while(client.available()>0 ) {
        int ans =0;

          char a = client.read();
          int b;
          int d=0;
          while(a!='#')
          {
            b=a-'0';
            d=d*10+b;
            a = client.read();
            
          }
          if(d!=-23){
            //Serial.println(d);
                int x = d/1000;
                int val = d%1000;
                int dir = val/100;
                int pwm = val%100;
                PWM = map(pwm,0,99,0,255);
                //DIR=0 FORWARD; DIR=1 BACKWARD
                
                if(x == 1 && dir==0)
                {
                  digitalWrite(DC11, PWM);
                  digitalWrite(DC12, LOW);
                  Serial.println("motor 1 for");
                }
                if(x == 1 && dir==1)
                {
                  digitalWrite(DC11, LOW);
                  digitalWrite(DC12, PWM);
                  Serial.println("motor 1 back");
                }
                
                else if(x == 2 && dir==0)
                {
                  digitalWrite(DC21, PWM);
                  digitalWrite(DC22, LOW);
                  Serial.println("motor 2 for");
                }
                else if(x == 2 && dir==1)
                {
                  digitalWrite(DC21, LOW);
                  digitalWrite(DC22, PWM);
                  Serial.println("motor 2 back");
                }
                
                else if(x == 3)
                {
                  digitalWrite(DC31, PWM);
                  digitalWrite(DC32, LOW);
                  Serial.println("motor 3 for");
                }
                else if(x == 3)
                {
                  digitalWrite(DC31, LOW);
                  digitalWrite(DC32, PWM);
                  Serial.println("motor 3 back" );
                }
                
                else if(x == 4)
                {
                  digitalWrite(PIN1, 1);
                  digitalWrite(PIN2, 0);
                  digitalWrite(PIN3, dir);
                  Serial.println("st1");
                }
                else if(x == 5)
                {
                  digitalWrite(PIN1, 0);
                  digitalWrite(PIN2, 1);
                  digitalWrite(PIN3, dir);
                  Serial.println("st2");
                }
                else if(x == 6)
                {
                  digitalWrite(PIN1, 1);
                  digitalWrite(PIN2, 1);
                  digitalWrite(PIN3, dir);
                  Serial.println("st3");
                }
          }
          delay(100);
          
      }
      

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
