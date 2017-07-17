//moving all the variable definitions here because arduino
// concats all ino files alphabetically

unsigned int hour, minute, second, day, month, year;

float temperature;
float humidity;

int CO2;
unsigned int PM1,PM25,PM10;
char PIR;

#define show_P(arg) flash_show(PSTR(arg))
