#include "SdFat.h"
SdFat SD;

File myFile;

void Save(String text, String label = ""){

  
  if(label != ""){
      Serial.print(label);
      Serial.print(F(": "));
      Serial.println(text);
  }

  //if the file opened okay, write to it
  if (myFile) {
    
    myFile.print(text);
    
    //close the file
    myFile.flush();
  
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

void Save_sensors(String Time, bool PIR, String Temp, int CO2, String Dust){

    Save_sensor(Time, F("Time"));
    
    Save_sensor(String(PIR), F("PIR"));
    Save_sensor(Temp, F("Temp"));
    Save_sensor(String(CO2),F("CO2"));

    Save(Dust, F("Dust"));
    
    Save(F("\n"));
}

void SD_setup(){
  Serial.println(F("Init SD"));

  if (!SD.begin(10)) {
    Serial.println(F("Init failed!"));
    return;
  }

  // print the headings for our data in the txt file
   myFile = SD.open(F("Box" BOX_ID ".csv"), FILE_WRITE);

   Save(F("Time,"));
   Save(F("Moving,"));
   Save(F("Temp,"));
   Save(F("Humid,"));
   Save(F("CO2,"));
   Save(F("Dust 1.0,"));
   Save(F("Dust 2.5,"));
   Save(F("Dust 10\n"));
   

   Serial.println(F("init done"));
}
