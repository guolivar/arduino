void PIR_setup(){
    pinMode(2, INPUT_PULLUP);
 }

bool PIR = false;
void PIR_loop(){
   
    // If the sensor's output goes low, motion is detected
    PIR = digitalRead(2) == LOW;
 }
 
 

