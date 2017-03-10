#include "RTClib.h"
//using namespace RTC_DS3231


RTC_DS3231 rtc;

void Time_setup(){
  //Wire.begin();
  rtc.begin();
  
}

void Time_loop(){
   DateTime this_time = rtc.now();
   
}

