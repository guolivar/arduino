#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>
//#include <SSD1306AsciiSoftSpi.h>
//#include <SSD1306AsciiSpi.h>
//#include <SSD1306AsciiWire.h>
//#include <SSD1306init.h>

//display address 0x3C

SSD1306AsciiAvrI2c oled;

// we delay the time until the screen gets cleared so that people can read the data
// might need to use interrupts for this at some point so it doesn't bottleneck
void delay_clear(){
  // wait a few milliseconds
  delay(2000);
  oled.clear();
}

// these two functions are exactly the same just with different types, see if theres a way to merge
void show(const __FlashStringHelper *message){
  delay_clear();
  oled.print(message);
  
}

void show(String data){
  delay_clear();
  oled.print(data);
}

void OLED_setup(){
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(TimesNewRoman16);
  show("SKOMOBO"));
//  oled.setFont(TimesNewRoman16);
//  oled.clear();
//  oled.print("Screen ready");
}
