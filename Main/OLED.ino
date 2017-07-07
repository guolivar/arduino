#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>
//#include <SSD1306AsciiSoftSpi.h>
//#include <SSD1306AsciiSpi.h>
//#include <SSD1306AsciiWire.h>
//#include <SSD1306init.h>

//display address 0x3C

SSD1306AsciiAvrI2c oled;

void show(const __FlashStringHelper *message){

  oled.clear();
  oled.print(message);
  
}

void show_data(String data){
  oled.clear();
  oled.print(data);
}

void OLED_setup(){
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(TimesNewRoman16);
//  oled.setFont(TimesNewRoman16);
//  oled.clear();
//  oled.print("Screen ready");
   show(F("Screen ready"));
}
