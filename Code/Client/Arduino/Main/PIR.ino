void PIR_setup(){
    pinMode(2, INPUT_PULLUP);
 }

 bool PIR_loop(){
  
    // If the sensor's output goes low, motion is detected
    return digitalRead(2) == LOW;;
 }
 
 

