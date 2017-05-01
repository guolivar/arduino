#include <SPI.h>
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <Arduino.h>
#include <SD.h>


#include "RTClib.h"

RTC_DS3231 rtc;


Adafruit_SSD1306 display(4);

#include <SoftwareSerial.h>
SoftwareSerial dustport(8,9);

// T9602 is temp sensor


void display_heading(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println(F("       SKOMOBO"));
    display.setTextSize(2);
}


unsigned char c;
  
long calc_pm(){ 
  return 256 *( 2 * c);
}


long pm1;

//pm 2.5
long pm25;

//pm 10
long pm10;

// look into difference between atmosphere and the cm values


// use F function to save on space

String DUST_loop() {

  int count = 0;

  //mega
//  while (Serial2.available()) {
//    
//    c = Serial2.read();

 while (dustport.available()) {
    c = dustport.read();
    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
      Serial.println(F("check failed"));
      break;
    }

//    if(count == 5){
////      show("CF = 1", "1");
//    }
//    else if(count == 7){
////      show("CF = 1", "2.5");
//    }
//    else if(count == 9){
////      show("CF = 1", "10");
//    }
    if(count == 11){
//      show("atmosphere", "1.0");
      pm1 = calc_pm();
    }
    else if(count == 13){
//      show("atmosphere", "2.5");
      pm25 = calc_pm();
    }
    else if(count == 15){
//      show("atmosphere", "10");
      pm10 = calc_pm();

      display_heading();
          
      display.print(F("PM: "));

      display.print(calc_pm());
      display.setTextSize(1);
      display.println(F("ug/m3"));
      display.println(F(" "));
      display.println(F(" 10"));
      display.display();
    }
    if(count > 15){
//      Serial.println("complete");
        break;
//      long pms[3] = {pm1, pm25, pm10};
//      return pms;
    }

    count++;
  }
  //mega
  //while(Serial2.available()) Serial2.read();
  // while(dustport.available()) dustport.read();
  Serial.println();
  delay(2000);

  // replace with proper concatenation
  return String(pm1) + " " + String(pm25) +  " " + String(pm10);
  
}


// This macro allows us to succinctly convert each argument into a string
#define format( arg ) ( String(rtc.now().arg()) )

#define current_time "  " + format( hour ) + ":" + format( minute ) +":" + format( second ) 
#define day_month_year "      " + format( day ) + "/" + format( month )+ "/" + format( year )


void ScanI2CBus()
{
  byte error, address;
  int nDevices;

  Serial.println(F("Scanning"));

  nDevices = 0;
  for (address = 1; address <= 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
//    Serial.println("test: " + String(Wire.requestFrom(address, 1)));
//    Serial.println("attempting " + String(address));
 
   
    Wire.beginTransmission(address);

    //rtclib address
    //Wire.beginTransmission(104);

    //datasheet address for m version
//    Wire.beginTransmission(00h);
    
    error = Wire.endTransmission();
    
//    Serial.println("Error: " + String(error));
    
    if (error == 0)
    {
      Serial.print(F("I2C device found at "));
      Serial.print(address, DEC); Serial.println(F(" (decimal)"));

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print(F("Unknown error at "));
      Serial.println(address, DEC);
    }
//    else{
//      Serial.println("Error was " + String(error));
//    }
  }
  if (nDevices == 0)
    Serial.println(F("No I2C devices found\n"));
  else
    Serial.println(F("done\n"));

}


void setupTemp(){
 //Serial.begin(115200);  // start serial for output

 
// Serial.println("Amphenol Advanced Sensors");
// Serial.println("Arduino T9602 Monitor");
}

void getdata(byte *a, byte *b, byte *c, byte *d)
{

//  //Serial.println(*a);
//
  Wire.beginTransmission(40);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(40, 4);
  *a = Wire.read();
  //Serial.println(*a);

  *b = Wire.read();
  *c = Wire.read();
  *d = Wire.read();
}

// is this function necessary?
float adjust_temp(float rawData){
  return rawData;
}

void display_val(String label, float val){
  display_heading();
  display.print(label + F(": "));
  display.print(val);
}

void display_end(String thing ){
  display.println(thing);
  display.display();
}

String Temp_loop()
{
 byte aa,bb,cc,dd;
 float temperature=0.0;  float humidity=0.0;
 getdata(&aa,&bb,&cc,&dd);

// humidity = (rH_High [5:0] x 256 + rH_Low [7:0]) / 16384 x 100
 humidity = (float)(((aa & 0x3F ) << 8) + bb) / 16384.0 * 100.0;

// temperature = (Temp_High [7:0] x 64 + Temp_Low [7:2]/4 ) / 16384 x 165 40
 temperature = adjust_temp((float)((unsigned)(cc  * 64) + (unsigned)(dd >> 2 )) / 16384.0 * 165.0 - 40.0);

  display_val("T", temperature);

  display.drawCircle(100, 11, 3, WHITE);
  display_end(" C");

  display_val("RH", humidity);
  display_end("%");

  delay(2000);

  return String(temperature) + " " + String(humidity);
}





///////////////////////////////////////////////////////////////////

// Function : int readCO2()

// Returns : CO2 Value upon success, 0 upon checksum failure

// Assumes : - Wire library has been imported successfully.

// - LED is connected to IO pin 13

// - CO2 sensor address is defined in co2_addr

///////////////////////////////////////////////////////////////////


// CO2 Meter K-series Example Interface


// Arduino analog input 5 - I2C SCL

// Arduino analog input 4 - I2C SDA

/*

In this example we will do a basic read of the CO2 value and checksum

verification. For more advanced applications see the I2C Comm guide.

*/

void co2setup() {

   //Wire.begin ();

   pinMode(13, OUTPUT); // address of the Arduino LED indicator

   //println("Application Note AN-102: Interface Arduino to K-30");

}

//void wire_write(int nums[4]){
//
//  for(int i = 0; i < 4; ++i){
//    Wire.write(nums[i]);
//  }
//
//}

int readCO2(){

  int co2_value = 0; // Store the CO2 value inside this variable.

  digitalWrite(13, HIGH); // turn on LED

  // On most Arduino platforms this pin is used as an indicator light.

  //////////////////////////

  /* Begin Write Sequence */

  //////////////////////////

  
  const int co2Addr = 127;
  //104

// This is the default address of the CO2 sensor, 7bits shifted left.

  Wire.beginTransmission(co2Addr);

  Wire.write(0x22);

  Wire.write(0x00);

  Wire.write(0x08);

  Wire.write(0x2A);


  //wire_write([0x22, 0x00, 0x08, 0x2A]);

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

  while (Wire.available()){
    
    buffer[i] = Wire.read();
    i++;

  }

  ///////////////////////

  /* End Read Sequence */

  ///////////////////////

  /*

  Using some bitwise manipulation we will shift our buffer

  into an integer for general consumption

  */

  //co2_value = 0;

  co2_value |= buffer[1] & 0xFF;

  co2_value = co2_value << 8;

  co2_value |= buffer[2] & 0xFF;

  //byte sum = 0; //Checksum Byte

  byte sum = buffer[0] + buffer[1] + buffer[2]; //Byte addition utilizes overflow

  if (sum == buffer[3]){

  // Success!

    digitalWrite(13, LOW);

    return co2_value;

  }

  else{

    // Failure!

    /*

    Checksum failure can be due to a number of factors,

    fuzzy electrons, sensor busy, etc.

    */

    digitalWrite(13, LOW);

    return 0;

  }

}

int CO2_loop(){
  int co2Value = readCO2();
  //int co2Value = analogRead(A0);
  if (co2Value > 0){
    
    display_heading();
    
    display.print(F("CO2: "));
    display.print(co2Value);
    display.setTextSize(1);
    display.println(F("ppm"));
    display.display();
    delay(2000);

    return co2Value;
  }

  else {
    Serial.println(F("Checksum failed / Communication failure"));
  }
}


void Save(String text){
  File myFile = SD.open(F("data.txt"), FILE_WRITE);

  //if the file opened okay, write to it
  if (myFile) {

    myFile.println(text);
    
    //close the file
    myFile.close();
  
  }
}

void loop() {


    // RTC lib with code to get time 

// Getting raw seconds from new lib
// Serial.println(rtc.get());

//getting temperature from new lib
//Serial.println(rtc.getTemp());

// new lib code that has temp in it
//tmElements_t this_time = tmElements_t();
// rtc.read(this_time);

// add in code for heat again
  display_heading();
  display.println(current_time);
  display.setTextSize(1);
  display.println(day_month_year);
  display.display();
  delay(2000);

  // PIR sensor
  display_heading();
  display.print("PIR: ");
  display.setTextSize(1);

  bool movement = digitalRead(2) == LOW;
  display.println( movement ? F("Moving \n          Detected" ): F("Still"));
  display.display();
  delay(2000);

  // change formatting to match server url

  // do proper string concatenation because this is causing a tonne of heap fragmentation I think
  Save(current_time + day_month_year + " " + String(movement) + " " + Temp_loop() + " " + String(CO2_loop()) + " " + DUST_loop());
  delay(1000);
}

void setup() {
 
  Serial.begin(9600);

  // oled
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  display.println(F("  SKOMOBO"));
  display.println(F("  PROJECT"));
  display.display();
  delay(2000);
  
  // Start i2c for temp sensor and other sensors
  Wire.begin();

  // set PIR pin
  pinMode(2, INPUT);
  

  co2setup();
  setupTemp();
  rtc.begin();

//  ScanI2CBus();
  // Time_setup();
//CheckSD();
//  sd();
//I2c.scan();

  Serial.println(F("Init SD"));

  if (!SD.begin(53)) {
    Serial.println(F("Init failed!"));
    // return;
  }
  

  File myFile = SD.open(F("data.txt"));

  
  // we save the headings regardless of whether or not they are there  already because it marks any reboots to the system
  Save(F("Time Moving Temp Humid CO2 Dust 1.0 2.5 10"));

  while (!Serial) {
    //;  wait for serial port to connect. Needed for native USB port only
  }
}