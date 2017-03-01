
 void PIR_setup(){
    // This shouldn't need a pullup on the mega because it has 5v logic
    pinMode(MOTION_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
 }

 void PIR_loop(){
  int proximity = digitalRead(MOTION_PIN);
  if (proximity == LOW) // If the sensor's output goes low, motion is detected
  {
    //digitalWrite(LED_PIN, HIGH);
    println("Movment");
  }
  else
  {
    println("No Movement");
    //digitalWrite(LED_PIN, LOW);
  }
 }
 
 

