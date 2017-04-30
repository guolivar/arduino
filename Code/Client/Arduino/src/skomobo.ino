#include <SPI.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <Arduino.h>
//void print( String text){
//  Serial.print(text);
//}
//
//void println(String text){
//  Serial.println(text);
//}

// This macro allows us to succinctly convert each argument into a string
#define format( arg ) ( String(rtc.now().arg()) )

#include "RTClib.h"

RTC_DS3231 rtc;


Adafruit_SSD1306 display(4);

void setup() {
 
  Serial.begin(9600);
  oledsetup();
  PIR_setup();
  
//  IR_setup();

  co2setup();
  DUST_setup();
  setupTemp();
  rtc.begin();

//  ScanI2CBus();
  // Time_setup();
//CheckSD();
//  sd();
//I2c.scan();

  SD_setup();
 
  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }
}

#define current_time "  " + format( hour ) + ":" + format( minute ) +":" + format( second ) 
#define day_month_year "      " + format( day ) + "/" + format( month )+ "/" + format( year )

void loop() {

//    IR_loop();

    // RTC lib with code to get time 

/// maybe we should just use this and extract the temp code from the other lib and remove the time library as well 

//  String this_time = "  " + format( hour ) + ":" + format( minute ) +":" + format( second ) ;
//  String that_time = "      " + format( day ) + "/" + format( month )+ "/" + format( year );

//  Serial.println(this_time);
 


// Getting raw seconds from new lib
// Serial.println(rtc.get());

//getting temperature from new lib
//Serial.println(rtc.getTemp());

// new lib code that has temp in it
//tmElements_t this_time = tmElements_t();
// rtc.read(this_time);

// add in code for heat again
  display_heading();
  display.println(current_time);
  display.setTextSize(1);
  display.println(day_month_year);
  display.display();
  delay(2000);

//  return that_time + " " + this_time;

    // Time Movement Temp Humidty CO2 Dust 1.0 2.5 10
    Save_sensors(current_time + day_month_year, PIR_loop(), Temp_loop(), CO2_loop(), DUST_loop());
    delay(1000);
}


//#include "DS3231RTC.h"
//#include "Time.h"
//using namespace RTC_DS3231


// void Time_setup(){
//   //Wire.begin();
//   rtc.begin();
// //  rtc = DS3231RTC();
// }



//#define format(arg, ...) String(arg, ##__VA_ARGS__)
// String Time_loop(){


// }

