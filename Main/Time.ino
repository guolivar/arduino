#include "src/RTClib.h"

// if space needs to be reduced then perform my own dead code elimination by recreating the parts of libraries that i use
RTC_DS3231 rtc;

void Time_setup() {
  rtc.begin();
}

// This macro allows us to succinctly convert each argument into a string
#define fetch( arg ) ( arg = rtc.now().arg() )

//char my_time[14];
void Time_loop() {

  // put in validation for clock presence if there isnt any
  
  fetch( hour ); fetch( minute ); fetch( second ); fetch( day ); fetch( month ); fetch( year );
    
}

