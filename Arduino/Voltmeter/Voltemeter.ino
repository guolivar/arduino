void setup(){
  Serial.begin(115200);
}

void loop(){
  CheckVoltage();
}

void CheckVoltage(){
  Serial.print(analogRead(A1) * (5.0/1023.0));
  Serial.println(F("V"));
  delay(1000);
}

