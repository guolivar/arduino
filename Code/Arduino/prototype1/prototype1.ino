
#include <SPI.h>

void print( String text){
  Serial.print(text);
}

void println(String text){
  Serial.println(text);
}


#include <Wire.h>
//#include "WSWire.h"
//U#include "I2C.h"


void setup() {
 
  Serial.begin(9600);


  // note for refactoring put each thing in a class then in setup just pass classes and have their setup functions called
  // eg: setup_board( [ IR, CO2, PIR, DUST, Temp] )
  // better:

//   setup_board( 
//    [ 
//      IR, 
//      CO2, 
//      PIR, 
//      DUST, 
//      Temp
//     ] );

//  PIR_setup();
     
//  IR_setup();
//  co2setup();
//  DUST_setup();
//   setupTemp();


  ScanI2CBus();
   
   Time_setup();

  //CheckSD();
//  sd();
   
  //I2c.scan();
  


//  SETUP IR
  
//  SETUP PIR 
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }

 
}

void loop() {

//  GET IR_loop
//    LOOP IR

//    LOOP PIR
    
//  GET PIR_loop
 
//  #ifdef IR
//    IR_loop();
//  #endif
//  
//  #ifdef PIR
//    PIR_loop();
//  #endif
//  
//  #ifdef DUST
//    DUST_loop();
//  #endif
//  
//  #ifdef CO2
//    CO2_loop();
//  #endif
//  
//  #ifdef TEMP
//    Temp_loop();
//  #endif
//  
//  #ifdef TIME
   
    Time_loop();
//  #endif
 
 delay(1000);
}
