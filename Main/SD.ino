#include "SdFat.h"
SdFat SD;

File myFile;

void Save(char text[]) {


  //if the file opened okay, write to it
  if (myFile) {

    myFile.print(text);

    //close the file
    myFile.flush();

  }

  delay(2000);
}

// using a macro to join the seperating character to make it easier to change and not take up memory
#define SEP( val ) val + ","
bool SD_available = true;

void Save_sensors() {

  if (SD_available) {
    
    char Data[39];
    sprintf(Data, "%d:%d:%d %d/%d/%d,%c,%d,%g,%g,%d,%d,%d,%d\n", hour, minute, second, day, month, year, PIR, temperature, humidity, CO2, PM1, PM25, PM10);

    Save(Data);

  } else {
    //      show(F("SD card \nnot plugged \nin"));
  }

  //   Wifi_send(Time, PIR, Temp, CO2, Dust);
  //    WIFI_send(Time, PIR, Temp, CO2, Dust);
  //   WIFI_send("06:30:01 12/07/2017", true, "21,245", 51, "244,423,123");
  char test_time[] = "06_30_01_12_07_2017";
  char test_temp_humidity[] = "21,245";
  char test_dust[] = "244,423,123";
  WIFI_send(test_time, PIR, test_temp_humidity, 51, test_dust);
}

void SD_setup() {

  if (SD.begin(10)) {
 
    //  show(F("Initializing SD"));
    // print the headings for our data in the txt file
    myFile = SD.open(F("Box" BOX_ID ".csv"), FILE_WRITE);
    SD_available = true;
    // Print the headings in the csv file

    char headings[] = "Time,Moving,Temp,Humid,CO2,Dust 1.0,Dust 2.5,Dust 10\n";
    Save(headings);
    //   show(F("SD initialized"));
  
    //   Serial.println(F("init done"));

  }
  else{
       //    show(F("Initialization failed"));
    SD_available = false;
    return;
  }
}
