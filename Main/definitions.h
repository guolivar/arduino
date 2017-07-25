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

float temperature = 0.0;
float humidity = 0.0;

int CO2 = 0;
unsigned int PM1 = 0, PM25 = 0, PM10 =0;
char PIR = '0';
char Buffer[56] = "\0";

#define show_P(arg) flash_show(PSTR(arg))
#define save_P(arg) flash_save(PSTR(arg))
