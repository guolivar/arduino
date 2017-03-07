

 #define MOTION_PIN 2
 
 void PIR_loop(){
  
    // If the sensor's output goes low, motion is detected
    println( digitalRead(MOTION_PIN) == LOW ? "Movement" : "No Movement");
 }
 
 

