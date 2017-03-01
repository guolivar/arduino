
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
  PIR_setup();
  co2setup();
  DUST_setup();

  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }

 //sd();
}

void loop() {
  IR_loop();
  //PIR_loop();
  //DUST_loop();
  //CO2_loop();
  delay(1000);
}
