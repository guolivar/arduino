
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

// convert int to char array
//char * format(int arg){
//  //maximum 4 digits
//  char num[4];
//  sprintf(num, "%d", arg);
//  return num;
//}

char* Time_loop() {

  char here[14] = 

 
  return { format( hour ), ':' , format( minute ), ':', format( second ), ' ', format( day ), '/', format( month ), '/', format( year ) };
}

