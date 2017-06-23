
// for using the arduino mega (or another board) as a voltemeter
void CheckVoltage(){

  // Print the value received on analog pin 1 after converting it to volts
  Serial.print(analogRead(A1) * (5.0/1023.0));
  Serial.println(F("V"));
  delay(1000);
}

