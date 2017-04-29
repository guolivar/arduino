#include <SD.h>

File myFile;

void Save(String text){
  myFile = SD.open("data.txt", FILE_WRITE);

  //if the file opened okay, write to it
  if (myFile) {
    
//    print("Writing data.txt");
    myFile.println(text);
    
    //close the file
    myFile.close();
  
  }
}

// fix this function so that we can make sure that the spaces are even?

void Save_sensors(String Time, bool PIR, String Temp, int CO2, String Dust){
 
  Save(Time + " " + String(PIR) + " " + Temp + " " + String(CO2) + " " + Dust);
}
 
void SD_setup(){
  Serial.print("Init SD");

  if (!SD.begin(53)) {
    Serial.println("Init failed!");
    return;
  }
  
//  Serial.println("init done");

  // print the headings for our data in the txt file

//  String headings = "Time Movement Temperature Humidty CO2 IR 1 2 3 4 5 6 7 Dust 1.0 2.5 10";
  
  const String headings = "Time Moving Temp Humid CO2 Dust 1.0 2.5 10";

  myFile = SD.open("data.txt");
  
  if(myFile){

    char * buf = {};
    myFile.read(buf, headings.length());
    
    if( String(buf) != headings){
      Save(headings);
    }
  }
  myFile.close();
}
//
////File myFile;
//
//void sd(){
//
//  print("Initializing SD card...");
//
//  if (!SD.begin(53)) {
//    println("initialization failed!");
//    return;
//  }
//  
//  println("initialization done.");
//
//  //open the file. note that only one file can be open at a time, so you have to close this one before opening another. 
//  //myFile = SD.open(test.txt, FILE_WRITE);
//
//  //if the file opened okay, write to it
//  if (myFile) {
//    
//    print("Writing to test.txt...");
//    myFile.println("testing 1, 2, 3.");
//    
//    //close the file
//    myFile.close();
//    println("done.");
//  
//  } 
//  
//  else {
//    
//    //if the file didn't open, print an error
//    println("error opening test.txt");
//    
//  }
//
//  //re-open the file for reading
//  myFile = SD.open("TEST.TXT");
//
//  if (myFile) {
//    println("test.txt");
//
//    //read from the file until there's nothing else in it
//    while (myFile.available()) {
//      Serial.write(myFile.read());
//    }
//    
//    //close the file
//    myFile.close();
//  } 
//  
//  else {
//    //if the file didn't open, print an error
//    println("error opening test.txt");
//  }
//}
//
//// set up variables using the SD utility library functions:
////Sd2Card card;
////SdVolume volume;
////SdFile root;
//
//#include <SPI.h>
//
//// change this to match your SD shield or module;
//// Arduino Ethernet shield: pin 4
//// Adafruit SD shields and modules: pin 10
//// Sparkfun SD shield: pin 8
//// MKRZero SD: SDCARD_SS_PIN
//const int chipSelect = 10;
//
//void CheckSD() {
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

/*
  Listfiles

 This example shows how print out the files in a
 directory on a SD card

 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 2 Feb 2014
 by Scott Fitzgerald

 This example code is in the public domain.

 */
// #include <SPI.h>
// #include <SD.h>

// File root;

// void setup() {
//   // Open serial communications and wait for port to open:
//   Serial.begin(9600);
//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for native USB port only
//   }

//   Serial.print("Initializing SD card...");

//   if (!SD.begin(4)) {
//     Serial.println("initialization failed!");
//     return;
//   }
//   Serial.println("initialization done.");

//   root = SD.open("/");

//   printDirectory(root, 0);

//   Serial.println("done!");
// }

// void loop() {
//   // nothing happens after setup finishes.
// }

// void printDirectory(File dir, int numTabs) {
//   while (true) {

//     File entry =  dir.openNextFile();
//     if (! entry) {
//       // no more files
//       break;
//     }
//     for (uint8_t i = 0; i < numTabs; i++) {
//       Serial.print('\t');
//     }
//     Serial.print(entry.name());
//     if (entry.isDirectory()) {
//       Serial.println("/");
//       printDirectory(entry, numTabs + 1);
//     } else {
//       // files have sizes, directories do not
//       Serial.print("\t\t");
//       Serial.println(entry.size(), DEC);
//     }
//     entry.close();
//   }
// }



