

#include <SPI.h>
#include <SD.h>

File myFile;

//pir
const int MOTION_PIN = A2; // Pin connected to motion detector
const int LED_PIN = 13; // LED pin - active-high


void setup() {
  // PIR
   Serial.begin(9600);
  // The PIR sensor's output signal is an open-collector, 
  // so a pull-up resistor is required:

  // This shouldn't need a pullup on the mega because it has 5v logic 
  pinMode(MOTION_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  co2setup();

  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }


 sd();
}

void sd(){
   Serial.print("Initializing SD card...");

  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

//   open the file. note that only one file can be open at a time,
//   so you have to close this one before opening another.
//  myFile = SD.open(test.txt, FILE_WRITE);

//   if the file opened okay, write to it
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
//     close the file
    myFile.close();
    Serial.println("done.");
  } else {
   //  if the file didn't open, print an error
    Serial.println("error opening test.txt");
  }

//   re-open the file for reading
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt");

//     read from the file until there's nothing else in it
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
//     close the file
    myFile.close();
  } else {
//     if the file didn't open, print an error
    Serial.println("error opening test.txt");
  }
}

void loop() {
  int proximity = analogRead(MOTION_PIN);
  if (proximity == HIGH) // If the sensor's output goes low, motion is detected
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Movment!");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  readCO2();
}





// CO2 Meter K-series Example Interface



#include <Wire.h>



// Arduino analog input 5 - I2C SCL

// Arduino analog input 4 - I2C SDA

/*

In this example we will do a basic read of the CO2 value and checksum

verification. For more advanced applications see the I2C Comm guide.

*/

int co2Addr = 0x68;

// This is the default address of the CO2 sensor, 7bits shifted left.

void co2setup() {

    Wire.begin ();

     pinMode(13, OUTPUT); // address of the Arduino LED indicator

     Serial.println("Application Note AN-102: Interface Arduino to K-30");

}

///////////////////////////////////////////////////////////////////

// Function : int readCO2()

// Returns : CO2 Value upon success, 0 upon checksum failure

// Assumes : - Wire library has been imported successfully.

// - LED is connected to IO pin 13

// - CO2 sensor address is defined in co2_addr

///////////////////////////////////////////////////////////////////

int readCO2()

{

int co2_value = 0; // Store the CO2 value inside this variable.

digitalWrite(13, HIGH); // turn on LED

// On most Arduino platforms this pin is used as an indicator light.

//////////////////////////

/* Begin Write Sequence */

//////////////////////////

Wire.beginTransmission(co2Addr);

Wire.write(0x22);

Wire.write(0x00);

5

Wire.write(0x08);

Wire.write(0x2A);

Wire.endTransmission();

/////////////////////////

/* End Write Sequence. */

/////////////////////////

/*

Wait 10ms for the sensor to process our command. The sensors's

primary duties are to accurately measure CO2 values. Waiting 10ms

ensures the data is properly written to RAM

*/

delay(10);

/////////////////////////

/* Begin Read Sequence */

/////////////////////////

/*

Since we requested 2 bytes from the sensor we must read in 4 bytes.

This includes the payload, checksum, and command status byte.

*/

Wire.requestFrom(co2Addr, 4);

byte i = 0;

byte buffer[4] = {0, 0, 0, 0};

/*

Wire.available() is not necessary. Implementation is obscure but we

leave it in here for portability and to future proof our code

*/

while (Wire.available())

{

buffer[i] = Wire.read();

i++;

}

///////////////////////

/* End Read Sequence */

///////////////////////

6

/*

Using some bitwise manipulation we will shift our buffer

into an integer for general consumption

*/

co2_value = 0;

co2_value |= buffer[1] & 0xFF;

co2_value = co2_value << 8;

co2_value |= buffer[2] & 0xFF;

byte sum = 0; //Checksum Byte

sum = buffer[0] + buffer[1] + buffer[2]; //Byte addition utilizes overflow

if (sum == buffer[3])

{

// Success!

digitalWrite(13, LOW);

return co2_value;

}

else

{

// Failure!

/*

Checksum failure can be due to a number of factors,

fuzzy electrons, sensor busy, etc.

*/

digitalWrite(13, LOW);

return 0;

}

}

void loop() {

int co2Value = readCO2();

if (co2Value > 0)

{

Serial.print("CO2 Value: ");

Serial.println(co2Value);

}

else

{

Serial.println("Checksum failed / Communication failure");

}

delay(2000);

}

