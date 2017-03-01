#include <SD.h>

File myFile;

void sd(){

  print("Initializing SD card...");

  if (!SD.begin(53)) {
    println("initialization failed!");
    return;
  }
  
  println("initialization done.");

  //open the file. note that only one file can be open at a time, so you have to close this one before opening another. 
  //myFile = SD.open(test.txt, FILE_WRITE);

  //if the file opened okay, write to it
  if (myFile) {
    
    print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    
    //close the file
    myFile.close();
    println("done.");
  
  } 
  
  else {
    
    //if the file didn't open, print an error
    println("error opening test.txt");
    
  }

  //re-open the file for reading
  myFile = SD.open("test.txt");

  if (myFile) {
    println("test.txt");

    //read from the file until there's nothing else in it
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    
    //close the file
    myFile.close();
  } 
  
  else {
    //if the file didn't open, print an error
    println("error opening test.txt");
  }
}

