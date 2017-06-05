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


// read 10 times if 5 or more are moving then it is moving else not moving

    int count = 0;
    for(int i = 0; i < 10; i++ ){
      
      if(digitalRead(2) == LOW)
      {
        count++;
      }
    }

    if(count > 5){
      return true;
    }
    else{
      return false;
    }
   

//    bool movement = digitalRead(2) == LOW;
//    display.println( movement ? F("Moving \n          Detected" ): F("Still"));
//    display.display();
//    delay(2000);

//    return movement;
 }
 
 

