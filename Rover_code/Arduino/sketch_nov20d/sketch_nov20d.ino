void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Smoke:Detected");
  Serial.println("CarbonMonoxide:Not detected");
  Serial.println("Moisture:3%");
  Serial.println("Ammonia:not detected");
  Serial.println("RGB: 0.263 B");
    Serial.println("---------------------------------------------------------------------");
  delay(1000);
}
