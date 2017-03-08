
#include <SPI.h>

void print( String text){
  Serial.print(text);
}

void println(String text){
  Serial.println(text);
}


#include <Wire.h>

void setup() {
 
  Serial.begin(9600);
  //IR_setup();
  //CheckSD();
//  sd();
 // PIR_setup();
 // co2setup();
 // DUST_setup();
//   setupTemp();
  // ScanI2CBus();
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }

 
}

void loop() {
  Serial.println(get_time());
//  IR_loop();
 // PIR_loop();
 // DUST_loop();
  //CO2_loop();
  //Temp_loop();
  delay(1000);
}
