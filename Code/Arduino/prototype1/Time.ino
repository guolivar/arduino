#include "DS3231RTC.h"
#include "Time.h"
//using namespace RTC_DS3231

//#include "RTClib.h"
DS3231RTC rtc;
//RTC_DS3231 rtc;

void Time_setup(){
  //Wire.begin();
//  rtc.begin();
  rtc = DS3231RTC();
}


// This macro allows us to succinctly convert each argument into a string
//#define format( arg ) ( String(rtc.now().arg()) + " " )

//#define format(arg, ...) String(arg, ##__VA_ARGS__)
void Time_loop(){

// RTC lib with code to get time 

/// maybe we should just use this and extract the temp code from the other lib and remove the time library as well 

// String this_time = format( second ) + format( minute ) + format( hour ) + format( day ) + format( month ) + format( year );

//  Serial.println(this_time);
 


// Getting raw seconds from new lib
// Serial.println(rtc.get());

//getting temperature from new lib
//Serial.println(rtc.getTemp());

// new lib code that has temp in it
tmElements_t this_time = tmElements_t();
 rtc.read(this_time);
Serial.println(this_time);

}

