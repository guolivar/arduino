#include <SSD1306Ascii.h>
#include <SSD1306AsciiAvrI2c.h>
//
////display address 0x3C
//
SSD1306AsciiAvrI2c oled;
//
////bool OLED_connected = false;
//
//// we delay the time until the screen gets cleared so that people can read the data
// might need to use interrupts for this at some point so it doesn't bottleneck
void delay_clear(){
  // wait a few milliseconds
  delay(2000);
  oled.clear();
}
//
bool OLED_connected = false;
//
//// these two functions are exactly the same just with different types, see if theres a way to merge
//void show(const __FlashStringHelper *message){
//
//  if(OLED_connected){
//    delay_clear();
//    oled.print(message);
//  }
//  
//}

void show(char data[]){
    
  // if(OLED_connected){
    delay_clear();
    oled.print(data);
  // }
  // else{
  //   Serial.println(data);
  // }
}
//
//// to make text bigger use oled.set2X();
//// to undo use oled.set1X();
//
void OLED_setup(){


  // this code was ok but not needed
  // Wire.beginTransmission(0x3C);

  // if it returns 0 then the screen exists
  // OLED_connected = Wire.endTransmission() == 0;

  // if(OLED_connected){
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(TimesNewRoman16);
  show("SKOMOBO");
  // }else{
    // testing that this code works
    // Serial.println(F("OLED not connected"));
    
  //}
}
