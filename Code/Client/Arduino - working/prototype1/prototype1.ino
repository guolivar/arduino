#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>

//Adafruit_SSD1306 display(4);

void setup() {
 
  Serial.begin(9600);

  // setup the sd card first because we need it to be ready for virtmem
  SD_setup();

  
  PIR_setup();
//
  co2setup();

  // note dust uses virtmem
  DUST_setup();
//  setupTemp();
  
//  ScanI2CBus();

  Time_setup();
  
//  CheckSD();
//  sd();
//#include "MemoryFree.h"
//I2c.scan();


 
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }
}

// this gets the final address for the heap and the stack so we can see if they are fluctuating
uint8_t * heapptr, * stackptr;
void check_mem() {
  stackptr = (uint8_t *)malloc(4);          // use stackptr temporarily
  heapptr = stackptr;                     // save value of heap pointer
  free(stackptr);      // free up the memory again (sets stackptr to 0)
  stackptr =  (uint8_t *)(SP);           // save value of stack pointer
}

// checks how much ram is available
int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void loop() {

    // Time Movement Temp Humidty CO2 Dust 1.0 2.5 10
    Save_sensors( Time_loop(), PIR_loop(), Temp_loop(), CO2_loop(), DUST_loop());
//     Save_sensors(Time_loop(), PIR_loop(), Temp_loop(), CO2_loop());
//   Serial.println(DUST_loop());
//    Save_sensors( PIR_loop(), Temp_loop(), CO2_loop(), DUST_loop());
//      Save_sensors( PIR_loop(), Temp_loop(), CO2_loop());
//    DUST_loop();


////// add co2 in front of checksum message


  
//    /Serial.println("heap memory: ");
//    Serial.println(freeMemory);
      Serial.println(F("Saved"));
    delay(60000);
//    Serial.println("stack memory: ");
//    Serial.println(&stackptr, DEC);
}
