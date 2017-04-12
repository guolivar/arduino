void PIR_setup(){
    pinMode(2, INPUT);
 }

 bool PIR_loop(){
  
    // If the sensor's output goes low, motion is detected

    bool movement = digitalRead(2) == LOW;
    println( movement ? "Movement" : "No Movement");

    display_heading();
//    display.clearDisplay();
//    display.setTextSize(1);
//    display.setTextColor(WHITE);
//    display.setCursor(0,0);
//    display.println("       SKOMOBO");
    
    display.setTextSize(2);
    display.print("PIR: ");
    display.setTextSize(1);
    display.println( digitalRead(2) == LOW ? "Movement \n          Detected" : "No Movement");
    display.display();
    delay(2000);

    return movement;
 }
 
 

