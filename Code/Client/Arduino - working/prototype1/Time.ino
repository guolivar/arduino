//#include "DS3231RTC.h"
#include "Time.h"
//using namespace RTC_DS3231

#include "RTClib.h"
#include <time.h>

RTC_DS3231 rtc;
//DS3231RTC rtc;
void Time_setup() {
  rtc.begin();

  //(int hr, int min, int sec, int day, int month, int yr)
  //    setTime(17, 57, 0, 5, 5, 2017);
  //    Serial.println("time set");
}


// This macro allows us to succinctly convert each argument into a string
#define format( arg ) ( String(rtc.now().arg()) )

String Time_loop() {

  // RTC lib with code to get time

  /// maybe we should just use this and extract the temp code from the other lib and remove the time library as well

  //  Serial.println(this_time);

  // Getting raw seconds from new lib
  // Serial.println(rtc.get());

  //getting temperature from new lib
  //Serial.println(rtc.getTemp());

  // new lib code that has temp in it
  //tmElements_t this_time = tmElements_t();
  //  tmElements_t t;
  //  breakTime(rtc.get(), t);

  //  rtc.getTemp();

  // time is measured from 1970 but we are in 2017 now so add an extra 17
  //  Serial.println(year());

  //Serial.println(t.Hour + 5);
  // add in code for heat again

  //  delay(2000);

  // return that_time + " " + this_time;
  return format( hour ) + ":" + format( minute ) + ":" + format( second ) + " " + format( day ) + "/" + format( month ) + "/" + format( year );
}

