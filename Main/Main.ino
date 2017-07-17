#include <Wire.h>

// all our own definitions
#include "definitions.h"

#include <avr/pgmspace.h>

void setup(){

  Serial.begin(115200);
  //  CheckVoltage();
  
  // setup all the modules
  OLED_setup();
  SD_setup();
  PIR_setup();
  CO2_setup();
  Dust_setup();
  Temp_setup();
  Time_setup();

  //  Wifi_setup();
  WIFI_setup();
}

void loop() {

  // collect the data and store globally
  Time_loop();
  PIR_loop();
  Temp_loop();
  CO2_loop();
  Dust_loop();

  // save the data
  Save_sensors();

  // ordering of shit no longer matters!!! which is awesome only one that matters is wifi but that will change soon

  // this way means no type checking all the time and having to change args
  // makes it much more flexible like javascript I guess better for prototyping like now

  // harder to reason about because more to remember??

  // does not force code correctness and validate for me

  // takes up less space and means memory is now static so unstable memory shouldny be issue


  
  // csv file headings, the functions need to be called in this order
  // Time Movement Temp Humidty CO2 Dust 1.0 2.5 10
//  delay(10000);
}
