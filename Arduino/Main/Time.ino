
#include "src/Time.h"

#include "src/RTClib.h"

RTC_DS3231 rtc;

void Time_setup() {
  rtc.begin();
}


// This macro allows us to succinctly convert each argument into a string
#define format( arg ) ( String(rtc.now().arg()) )

String Time_loop() {
 
  return format( hour ) + ":" + format( minute ) + ":" + format( second ) + " " + format( day ) + "/" + format( month ) + "/" + format( year );

}

