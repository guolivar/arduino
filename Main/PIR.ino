void PIR_setup(){
    pinMode(2, INPUT_PULLUP);
 }

//bool PIR = false;
void PIR_loop(){
   
    // If the sensor's output goes low, motion is detected
    
    if (digitalRead(2) == LOW) {
      PIR = '1';
//       PIR = '1';
    } else {
//      PIR = '0';
      PIR = '0';
    }
 }