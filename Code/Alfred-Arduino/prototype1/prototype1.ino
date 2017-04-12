#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void print( String text){
  Serial.print(text);
}

void println(String text){
  Serial.println(text);
}




Adafruit_SSD1306 display(4);

void setup() {
 
  Serial.begin(9600);
  oledsetup();
  PIR_setup();
  
//  IR_setup();

  co2setup();
  DUST_setup();
  setupTemp();
//  ScanI2CBus();
  Time_setup();
//CheckSD();
//  sd();
//I2c.scan();

  SD_setup();
 
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {

//    IR_loop();
    Save_sensors(Time_loop(), PIR_loop(), Temp_loop(), CO2_loop(), DUST_loop());
    delay(1000);
}
