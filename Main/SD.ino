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

    //      String temp = Temp.substring(0, Temp.indexOf(','));
    //      String humidity = Temp.substring(Temp.indexOf(','));
    //      Save_sensor(Time, F("Time"));

    // copy data from time instead of assigining reference
    //      String my_time = String(Time);
    //      my_time.replace(' ', '\n');
    char Time[14];

    sprintf(Time, "%d:%d:%d %d/%d/%d", hour, minute, second, day, month, year);
    Save(Time);
    //      show("Time: " + my_time);

    /////// BUG Screen will not show values if sd not available

    
    Save(&PIR);

    char data[12];
    sprintf(data, "%g,%g,%d", temperature, humidity, CO2);
    Save(data);
//    Save(temperature);
//    Save(humidity);
//    Save(CO2);

    char Dust[13];
    sprintf(Dust, "%d,%d,%d\n", PM1, PM25, PM10);
    Save(Dust);

    // I think things being global wont cause issues


    //      Save('\n');
    //      Save(F("\n"));
  } else {
    //      show(F("SD card \nnot plugged \nin"));
  }

  //   Wifi_send(Time, PIR, Temp, CO2, Dust);
  //    WIFI_send(Time, PIR, Temp, CO2, Dust);
  //   WIFI_send("06:30:01 12/07/2017", true, "21,245", 51, "244,423,123");

  WIFI_send("06_30_01_12_07_2017", PIR, "21,245", 51, "244,423,123");
}

void SD_setup() {

  if (!SD.begin(10)) {
    //    show(F("Initialization failed"));
    SD_available = false;
    return;
  }


  //  show(F("Initializing SD"));
  // print the headings for our data in the txt file
  myFile = SD.open(F("Box" BOX_ID ".csv"), FILE_WRITE);

  // Print the headings in the csv file
  // please note these do not use the SEP macro because they get converted to Flashstrings which are stored in program memory to save SRAM
  // as a result we can't use dynamic concatenation I don't think
  Save("Time,");
  Save("Moving,");
  Save("Temp,");
  Save("Humid,");
  Save("CO2,");
  Save("Dust 1.0,");
  Save("Dust 2.5,");
  Save("Dust 10\n");

  //   show(F("SD initialized"));

  //   Serial.println(F("init done"));
}
