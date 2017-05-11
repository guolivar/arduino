#include "SdFat.h"
SdFat SD;

File myFile;

void Save(String text, String label = ""){

  
  Serial.print(F("Free Ram: "));
  Serial.println(freeRam());
    
  if(label != ""){
      Serial.print(label);
      Serial.print(F(": "));
      Serial.println(text);
  }

  //if the file opened okay, write to it
  if (myFile) {
    
//    print("Writing data.txt");
    myFile.print(text);
    
    //close the file
    myFile.flush();
//    myFile.close();
    Serial.println(F("Saved"));
  
  }
}

// fix this function so that we can make sure that the spaces are even?

#define Sep( val ) val + ","

void Save_sensor(String data, __FlashStringHelper* label){
  Save(Sep(data), label);
}

void Save_time(int x, int y, int z, __FlashStringHelper* sep){
    Save(String(x), F("Time-x"));
    Save(sep);
    Save(String(y), F("Time-y"));
    Save(sep);
    Save(String(z), F("Time-z"));
}

//typedef struct time_stamp{
//  int hour;
//  int minute;
//  int second;
//  int day;
//  int month;
//  int year;
//} Time_stamp;

#include "Time.h"
//using namespace RTC_DS3231

#include "RTClib.h"
//#include <time.h>
//
RTC_DS3231 rtc;
//DS3231RTC rtc;
void Time_setup() {
  rtc.begin();

  //(int hr, int min, int sec, int day, int month, int yr)
  //    setTime(17, 57, 0, 5, 5, 2017);
  //    Serial.println("time set");
}


#define format( arg ) ( rtc.now().arg() )

//void Save_sensors(Time_stamp Time, bool PIR, String Temp, int CO2, String Dust){
//void Save_sensors( bool PIR, String Temp, int CO2, String Dust){

void Save_sensors( bool PIR, String Temp, int CO2){
    // break it up so that the giant string doesnt go to ram
//    Save(Sep(Time), F("Time"));
//    Save(Sep(String(PIR)), F("PIR"));
//    Save(Sep(Temp), F("Temp"));
//    Save(Sep(String(CO2)),F("CO2"));

//    Save_sensor(Time, F("Time"));

//    Save(Time.hour);
//    Save(F(':'));
//    Save(Time.minute);
//    Save(F(':');
//    Save(Time.second);
    Save_time(format(hour), format(minute), format(second), F(":"));
    Save(F(" "));
//    Save(Time.day);
    Save_time(format(day), format(month), format(year), F("/"));
//    Save(F('/'));
//    Save(Time.month);
//    Save(F('/'));
//    Save(Time.year);
    
    Save_sensor(String(PIR), F("PIR"));
    Save_sensor(Temp, F("Temp"));
    Save_sensor(String(CO2),F("CO2"));
    Save(String(CO2),F("CO2"));
//    Serial.println(Dust);
    

//    Save(Dust, F("Dust"));
//    for(int i = 0; i < sizeof(Dust); i++){
//
//      if(i < sizeof(Dust) - 1){
//        Save(Sep(String(Dust[i])));
//      }
//      else{
//        Save(String(Dust[i]), "Dust");
//      }
//    }
    Save(F("\n"));
}

void SD_setup(){
  Serial.println(F("Init SD"));

  if (!SD.begin(10)) {
    Serial.println(F("Init failed!"));
    return;
  }

  // print the headings for our data in the txt file
   myFile = SD.open(F("data.csv"), FILE_WRITE);

   Save(F("Time,"));
   Save(F("Moving,"));
   Save(F("Temp,"));
   Save(F("Humid,"));
   Save(F("CO2,"));
   Save(F("Dust 1.0,"));
   Save(F("Dust 2.5,"));
   Save(F("Dust 10\n"));
   
//   Save(F("Time,Moving,Temp,Humid,CO2,Dust,1.0,2.5,10\n"));

// COL_HEADING("Time");
// COL_HEADING("Moving");
// COL_HEADING("Temp");
// COL_HEADING("Humid");
// COL_HEADING("CO2");
// COL_HEADING("Dust");
// COL_HEADING("1.0");
// COL_HEADING("2.5");
// COL_HEADING("10");
// END_LINE;
//   Save(Sep(F("Temp")));
//   Save(Sep(F("Humid")));
//   Save(Sep(F("CO2")));
//   Save(Sep(F("Dust")));
//   Save(Sep(F("1.0")));
//   Save(Sep(F("2.5")));
//   Save(Sep(F("10")));
//   Save(F("\n"));
   Serial.println(F("init done"));
}


//#include <SPI.h>

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// MKRZero SD: SDCARD_SS_PIN

//void CheckSD() {
//
//  const int chipSelect = 10;
//    // set up variables using the SD utility library functions:
//  Sd2Card card;
//  SdVolume volume;
//  SdFile root;
//  // Open serial communications and wait for port to open:
//  //Serial.begin(9600);
////  while (!Serial) {
////    ; // wait for serial port to connect. Needed for native USB port only
////  }
//
//
//  Serial.print("\nInitializing SD card...");
//
//  // we'll use the initialization code from the utility libraries
//  // since we're just testing if the card is working!
//  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
//    Serial.println("initialization failed. Things to check:");
//    Serial.println("* is a card inserted?");
//    Serial.println("* is your wiring correct?");
//    Serial.println("* did you change the chipSelect pin to match your shield or module?");
//    Serial.end();
//    return;
//  } else {
//    Serial.println("Wiring is correct and a card is present.");
//  }
//
//  // print the type of card
//  Serial.print("\nCard type: ");
//  switch (card.type()) {
//    case SD_CARD_TYPE_SD1:
//      Serial.println("SD1");
//      break;
//    case SD_CARD_TYPE_SD2:
//      Serial.println("SD2");
//      break;
//    case SD_CARD_TYPE_SDHC:
//      Serial.println("SDHC");
//      break;
//    default:
//      Serial.println("Unknown");
//  }
//
//  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
//  if (!volume.init(card)) {
//    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
//    return;
//  }
//
//
//  // print the type and size of the first FAT-type volume
//  uint32_t volumesize;
//  Serial.print("\nVolume type is FAT");
//  Serial.println(volume.fatType(), DEC);
//  Serial.println();
//
//  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
//  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
//  volumesize *= 512;                            // SD card blocks are always 512 bytes
//  Serial.print("Volume size (bytes): ");
//  Serial.println(volumesize);
//  Serial.print("Volume size (Kbytes): ");
//  volumesize /= 1024;
//  Serial.println(volumesize);
//  Serial.print("Volume size (Mbytes): ");
//  volumesize /= 1024;
//  Serial.println(volumesize);
//
//
//  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
//  root.openRoot(volume);
//
//  // list all files in the card with date and size
//  root.ls(LS_R | LS_DATE | LS_SIZE);
//}
