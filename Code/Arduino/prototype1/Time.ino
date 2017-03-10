#include "RTClib.h"
//using namespace RTC_DS3231


RTC_DS3231 rtc;

void Time_setup(){
  //Wire.begin();
  rtc.begin();
  DateTime this_time = rtc.now();
  Serial.println(this_time.year());
}

void Time_loop(){
   DateTime this_time = rtc.now();
   
}

