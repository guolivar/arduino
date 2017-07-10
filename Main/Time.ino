
//#include "src/Time.h"

// is this still working??

#include "src/RTClib.h"

// if space needs to be reduced then perform my own dead code elimination by recreating the parts of libraries that i use
RTC_DS3231 rtc;

void Time_setup() {
  rtc.begin();
}


// This macro allows us to succinctly convert each argument into a string
#define format( arg ) ( String(rtc.now().arg()) )

String Time_loop() {
  
  return format( hour ) + ":" + format( minute ) + ":" + format( second ) + " " + format( day ) + "/" + format( month ) + "/" + format( year );
//  String Time[] = {format( hour ), format( minute ), format( second ), format( day ), format( month ), format( year )};
//  return Time;
}

