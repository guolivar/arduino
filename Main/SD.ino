#include "SdFat.h"
SdFat SD;

File myFile;

void flash_save(char data[]){
    //if the file opened okay, write to it
  if (myFile) {
    int len = strlen_P(data);
    for(int k = 0; k < len; k++){
        the_char = pgm_read_byte_near(data + k);
        myFile.print(the_char);
    }

    //close the file
    myFile.flush();

  }

  delay(2000);
}

//TODO remove redundancy

void Save(char text[]) {


  //if the file opened okay, write to it
  if (myFile) {

    myFile.print(text);

    //close the file
    myFile.flush();

  }

  delay(2000);
}

bool SD_available = true;

// char text[11] = "Temp: ";
char SD_Data[39];
void Save_sensors() {

  if (SD_available) {
    
    
    sprintf_P(SD_Data, PSTR("%d:%d:%d %d/%d/%d,%c,%d,%g,%g,%d,%d,%d,%d\n"), hour, minute, second, day, month, year, PIR, temperature, humidity, CO2, PM1, PM25, PM10);

    Save(SD_Data);

    // display temperature
    // dtostrf(temperature, 11, 2, &text[6]);
    
    // show(text);

    // TODO: put thing in here to display data on the screen with pretty formatting

  } else {
      show_P("SD card \nnot plugged \nin");
  }

  WIFI_send();
}

void SD_setup() {

  if (SD.begin(10)) {
 
    show_P("Initializing SD");
    // print the headings for our data in the txt file
    myFile = SD.open(F("Box" BOX_ID ".csv"), FILE_WRITE);
    SD_available = true;


    // replace this with save_P macro
    // Print the headings in the csv file
    flash_save(PSTR("Time,Moving,Temp,Humid,CO2,Dust 1.0,Dust 2.5,Dust 10\n"));
    //   show("SD initialized"));

    show_P("Initialization done");
    //   Serial.println(F("init done"));

  }
  else{
    show_P("Initialization failed");
    SD_available = false;
    return;
  }
}
