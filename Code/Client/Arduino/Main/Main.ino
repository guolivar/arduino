#include <SPI.h>
#include <Wire.h>

void setup() {
 
  Serial.begin(9600);

  // setup all the modules
  SD_setup();
  PIR_setup();
  co2setup();
  DUST_setup();
  Temp_setup();
  Time_setup();

 //wait for Arduino serial port to become available
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {

    // csv file headings, the functions need to be called in this order
    // Time Movement Temp Humidty CO2 Dust 1.0 2.5 10
    Save_sensors( Time_loop(), PIR_loop(), Temp_loop(), CO2_loop(), DUST_loop() );
    Serial.println(F("Saved"));
    delay(60000);
}
