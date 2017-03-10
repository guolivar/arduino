
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
  
  //IR_setup();
  //CheckSD();
//  sd();
 // PIR_setup();
 // co2setup();
 // DUST_setup();
// setupTemp();
  Time_setup();
  //I2c.scan();
  //ScanI2CBus();
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }

 
}

void loop() {
//  Serial.println(get_time());
//  IR_loop();
 // PIR_loop();
 // DUST_loop();
  //CO2_loop();
  //Temp_loop();
  delay(1000);
}
