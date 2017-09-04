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
        // the_char = pgm_read_byte_near(data + k);
        myFile.print((char)pgm_read_byte_near(data + k));
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

    Show_sensor(PSTR("Time: %d:%d:%d"), 15, hour, minute, second);
    Show_sensor(PSTR("Date: %d/%d/%d"), 17, day, month, year);
    // Show_sensor(PSTR("Time: %d:%d:%d\nDate: %d/%d/%d"), 30, hour, minute, second, day, month, year);
    Show_sensor(PSTR("Temperature: %d.%d"), 21, (int)temperature, (int)(temperature * 100) %100);
    Show_sensor(PSTR("Humidity: %d.%d"), 17, (int)humidity, (int)(humidity * 100) % 100);
    Show_sensor(PSTR("CO2: %d"), 10, CO2);
    Show_sensor(PSTR("Dust 1: %d"), 15, PM1);
    Show_sensor(PSTR("Dust 2.5: %d"), 15, PM25);
    Show_sensor(PSTR("Dust 10: %d"), 15, PM10);

}

void Save_sensors() {

  Show_sensors();

  if (SD_available) {

    show_P("Saving data\nto SD");
    // snprintf_P(Buffer, 66, PSTR("%d:%d:%d %d/%d/%d,%c,%d.%d,%d.%d,%d,%d,%d,%d\n"), hour, minute, second, day, month, year, PIR, (int)temperature, (int)(temperature * 100) % 100, (int)humidity, (int)(humidity * 100) % 100, CO2, PM1, PM25, PM10);
    snprintf_P(Buffer, 22, PSTR("%d:%d:%d %d/%d/%d,%c"), hour, minute, second, day, month, year, PIR);
    Save(Buffer);

    snprintf_P(Buffer, 50, PSTR(",%d.%d,%d.%d,%d,%d,%d,%d,%d\n"), (int)temperature, (int)(temperature * 100) % 100, (int)humidity, (int)(humidity * 100) % 100, CO2, PM1, PM25, PM10,error);

    Save(Buffer);
    show_P("Saved data\nto SD");

  } else {
      show_P("SD card \nnot plugged \nin");
  }

  // blue_send();
  // WIFI_send();
}

void SD_setup() {
  show_P("Initializing SD");
  if (SD.begin(10)) {
    SD_available = true;
    show_P("SD initialized");

    // Read the config information from file
    show_P("Reading config");
    myFile = SD.open(F("config.txt"),FILE_READ);
    // Read Unit number
    //Read Serial Number
    String readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    readtmp.toCharArray(BOX_ID,readtmp.length()+1);
    readtmp=myFile.read();
    // Read wifi toggle
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    s_wifi = (readtmp.toInt() == 1);
    readtmp=myFile.read();
    // Read BT toggle
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    s_bt = (readtmp.toInt() == 1);
    readtmp=myFile.read();
    // Read localstorage toggle
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    s_local = (readtmp.toInt()==1);
    readtmp=myFile.read();
    // Read ssid
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    readtmp.toCharArray(HOTSPOT, readtmp.length()+1);
    readtmp=myFile.read();
    // Read pwd
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    readtmp.toCharArray(PASSWORD, readtmp.length()+1);
    readtmp=myFile.read();
    // Read server
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    readtmp.toCharArray(server, readtmp.length()+1);
    readtmp=myFile.read();
    // Read PORT
    readtmp = "";
    while (myFile.peek()!='\n'){
      readtmp = readtmp + String((char)myFile.read());
    }
    port = readtmp.toInt();
    myFile.close();

    // print the headings for our data in the txt file
    myFile = SD.open(F("Data.csv"), FILE_WRITE);
    // Print the headings in the csv file
    save_P("Time,Moving,Temp,Humid,CO2,Dust 1.0,Dust 2.5,Dust 10,ERROR\n");

  }
  else{
    show_P("Initialization failed");
    SD_available = false;
    return;
  }
}
