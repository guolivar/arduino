void PIR_setup(){
    pinMode(2, INPUT);
 }

 bool PIR_loop(){
  
    // If the sensor's output goes low, motion is detected

   
//    display_heading();
//    
//    display.print("PIR: ");
//    display.setTextSize(1);
//
    bool movement = digitalRead(2) == LOW;
//    display.println( movement ? F("Moving \n          Detected" ): F("Still"));
//    display.display();
//    delay(2000);

    return movement;
 }
 
 

