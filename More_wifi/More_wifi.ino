void setup(){
  OLED_setup();
}

void loop(){

  //transmit my command
  Serial.println(Serial.read());

  delay(3000);
  //receive response
  show(Serial.read());
//  show(Serial.readString());
}
  
