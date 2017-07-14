
//#include "src/Time.h"

// is this still working??

#include "src/RTClib.h"

// if space needs to be reduced then perform my own dead code elimination by recreating the parts of libraries that i use
RTC_DS3231 rtc;

void Time_setup() {
  rtc.begin();
}


// swap to char array implementation to save more space and find more space saving libs

// This macro allows us to succinctly convert each argument into a string
#define format( arg ) ( rtc.now().arg() )

char my_time[14];
char* Time_loop() {

  sprintf(my_time, "%d:%d:%d %d/%d/%d", format(hour), format(minute), format(second), format(day), format(month), format(year));
  return my_time;
//  return { format( hour ), ':' , format( minute ), ':', format( second ), ' ', format( day ), '/', format( month ), '/', format( year ) };
}

