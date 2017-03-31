  
 #define MOTION_PIN 2
 
 void PIR_setup(){
    pinMode(MOTION_PIN, INPUT_PULLUP);
 }

 void PIR_loop(){
  
    // If the sensor's output goes low, motion is detected
    println( digitalRead(MOTION_PIN) == LOW ? "Movement" : "No Movement");
 }
 
 
