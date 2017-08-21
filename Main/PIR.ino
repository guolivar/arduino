void PIR_setup(){
    pinMode(2, INPUT);
 }

 bool PIR_loop(){
  
    // If the sensor's output goes low, motion is detected

    bool movement = digitalRead(2) == HIGH;
    return movement;
 }
 
 

