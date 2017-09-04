//moving all the variable definitions here because arduino
// concats all ino files alphabetically

// properly initiliazing all variables to avoid memory misalignment issues

// unsigned int hour = 0 , minute = 0, second = 0, day = 0, month = 0, year = 0;

// float temperature = 0.0;
// float humidity = 0.0;

// int CO2 = 0;
// unsigned int PM1 = 0,PM25 = 0,PM10 = 0;
// char PIR = '0';


unsigned int hour = 0, minute = 0, second = 0, day = 0, month = 0, year = 0;
unsigned int buff_size = 100;
float temperature = 0.0;
float humidity = 0.0;

int CO2 = 0;
unsigned int PM1 = 0, PM25 = 0, PM10 =0;
char PIR = '0';
// char Buffer[54] = "\0";
char Buffer[100] = "\0";

// Configuration file variables
// These will get overwritten if a config file is available
char PASSWORD[20] = "box box box";
char HOTSPOT[20] = "ufixx";
char BOX_ID[4] = "000";
bool s_wifi = 1, s_bt = 0, s_local = 1;
char server[50] = "seat-skomobo.massey.ac.nz";
byte error = 0;
/*
CO2 checksum fail: 00000001
CO2 comms fail: 00000010
Dust comms fail: 00000100
Memory card fail: 00001000
T&RH fail: 00010000
BT fail: 00100000
Alarm1: 01000000
Alarm2: 10000000
*/
int port = 80;

/// make sd buffer smaller by chunking then reduce global buffer

// All the p versions of our functions are macros that use the PSTR macro for working with flash
// memory succinctly

#define show_P(arg) flash_show(PSTR(arg))
#define save_P(arg) flash_save(PSTR(arg))
// #define layout_P(arg1, ...) layout(PSTR(arg1), __VA_ARGS__)
