#include "SdFat.h"
SdFat SD;

File myFile;

// void flash_print(char data[], size_t (*print)( char ) ){
//     size_t len = strlen_P(data);
//     for(int k = 0; k < len; k++){
    
//         //! remove the_char and just insert directly
//         the_char = pgm_read_byte_near(data + k);
//         print(the_char);
//         // myFile.print(the_char);
//     }
// }


void flash_save(char data[]){
    //if the file opened okay, write to it
  if (myFile) {
    int len = strlen_P(data);
    for(int k = 0; k < len; k++){
        the_char = pgm_read_byte_near(data + k);
        myFile.print(the_char);
    }
    // flash_print(data, &myFile.print);
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


//TODO: replace with variadic function or single function with branching ifs

void Show_sensor(char format[], int length, int val){
    
    snprintf_P(Buffer, length, format, val);
    show(Buffer);

}

void Show_sensor(char format[], int length, int val, int val2){
    
    snprintf_P(Buffer, length, format, val, val2);
    show(Buffer);

}

void Show_sensor(char format[], int length, int val, int val2, int val3){
    
    snprintf_P(Buffer, length, format, val, val2, val3);
    show(Buffer);

}

void Show_sensors(){

    Show_sensor(PSTR("Time: %d:%d:%d"), 14, hour, minute, second);
    Show_sensor(PSTR("Date: %d/%d/%d"), 16, day, month, year);
    Show_sensor(PSTR("Temperature: %d.%d"), 20, (int)temperature, (int)(temperature * 100) %100);
    Show_sensor(PSTR("Humidity: %d.%d"), 16, (int)humidity, (int)(humidity * 100) % 100);
    Show_sensor(PSTR("CO2: %d"), 9, CO2);
    Show_sensor(PSTR("Dust PM1: %d"), 14, PM1);
    Show_sensor(PSTR("Dust PM2.5: %d"), 14, PM25);
    Show_sensor(PSTR("Dust PM10: %d"), 14, PM10);

}

void Save_sensors() {

  Show_sensors();

  if (SD_available) {

    snprintf_P(Buffer, 66, PSTR("%d:%d:%d %d/%d/%d,%c,%d.%d,%d.%d,%d,%d,%d,%d\n"), hour, minute, second, day, month, year, PIR, (int)temperature, (int)(temperature * 100) % 100, (int)humidity, (int)(humidity * 100) % 100, CO2, PM1, PM25, PM10);

    Save(Buffer);
    show_P("Saved data\nto SD");

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


    // Print the headings in the csv file
    save_P("Time,Moving,Temp,Humid,CO2,Dust 1.0,Dust 2.5,Dust 10\n");

    show_P("SD initialized");

  }
  else{
    show_P("Initialization failed");
    SD_available = false;
    return;
  }
}