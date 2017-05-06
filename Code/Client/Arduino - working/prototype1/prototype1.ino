#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>

//Adafruit_SSD1306 display(4);

void setup() {
 
  Serial.begin(9600);
  PIR_setup();
//
  co2setup();
  DUST_setup();
  setupTemp();
  
//  ScanI2CBus();

  Time_setup();
  
//  CheckSD();
//  sd();
//#include "MemoryFree.h"
//I2c.scan();

  SD_setup();
 
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }
}

uint8_t * heapptr, * stackptr;
void check_mem() {
  stackptr = (uint8_t *)malloc(4);          // use stackptr temporarily
  heapptr = stackptr;                     // save value of heap pointer
  free(stackptr);      // free up the memory again (sets stackptr to 0)
  stackptr =  (uint8_t *)(SP);           // save value of stack pointer
}

void loop() {
//  Time_loop();
    // Time Movement Temp Humidty CO2 Dust 1.0 2.5 10
    Save_sensors(Time_loop(), PIR_loop(), Temp_loop(), CO2_loop(), DUST_loop());
//     Save_sensors(Time_loop(), PIR_loop(), Temp_loop(), CO2_loop());
    
//    /Serial.println("heap memory: ");
//    Serial.println(freeMemory);
    
    delay(2000);
//    Serial.println("stack memory: ");
//    Serial.println(&stackptr, DEC);
}
