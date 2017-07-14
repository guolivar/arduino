//#include <SPI.h>

// check that sd still works if not uncomment above line

#include <Wire.h>

void setup(){

  Serial.begin(115200);
  //  CheckVoltage();
  
  // setup all the modules
//  OLED_setup();
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

  // csv file headings, the functions need to be called in this order
  // Time Movement Temp Humidty CO2 Dust 1.0 2.5 10

  Save_sensors( Time_loop(), PIR_loop(), Temp_loop(), CO2_loop(), Dust_loop() );

//  delay(10000);
}
