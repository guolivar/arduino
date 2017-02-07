
// * Dust Sensor sampler/ *   Using a ATTiny85 to deal with the dust sensor signal
// *   Read on analog channel with pulseIn()
// * Movement with PIR
// * Distance with Maxbotix EZ4
// * CO2 with Parallax unit
// * CO with Parallax unit
// * Timing controlled by Real Time Clock
// * Save using SdFat library with Adafruit uSD board
// * Analog deMux with 74HC4052
// * Time managed by Chronodot using Chronodot library by Stephanieplanet
// * In-temperature from Chronodot. Out-temperature from LM335A
//Add the SD Library
#include <SD.h>
//Add Libraries to work with the Real Time Clock
#include <Wire.h>
#include "Chronodot.h" // Chronodot library by Stephanieplanet adjusted by Ryan Weyers for the arduino pro micro
Chronodot RTC;
DateTime time;
//Control AnalogDemux
int x9=6;
int x10=5;
//Dust sensor variable
unsigned long Dust;
//Temperature sensor variable
unsigned long Temp; //Temperature
//Distance variable
unsigned long Distance; //Distance
//CO2 variable
unsigned long CO2; //CO2 signal
//CO constants and variables
int COswpin=3; //CO switch pin
unsigned long CO; //CO signal
//variables for the CO sensor power cycle
unsigned long currTimeCO;
unsigned long prevTimeCO;
unsigned long currCOPwrTimer;
byte COPwrState,COstatus;
//Movement constants and variables
int PIRPin=4; //PIR input pin
int movement;
//General constants and variables
unsigned long rcount;
// Create the variables to be used by SdFat Library
File currfile;
// Savefile name in String and char format
String fname;
String currdir;
char file_fname[20];
char dir_dname[10];
//long fcount,dcount;
int psec,csec;

unsigned long GetDust()
{
  selectDUST();
  // wait to stabilize the pin
  delayMicroseconds(500);
  return pulseIn(A0,HIGH);
}
unsigned long GetDistance()
{
  unsigned long RAW=0;
  selectRF();
  for (int ii=1;ii<=50;ii++){
    RAW=RAW+analogRead(1);
  }
  return long(RAW/50);
}
unsigned long GetTemperature()
{
  unsigned long RAW=0;
  selectTEMP();
  for (int ii=1;ii<=50;ii++){
    RAW=RAW+analogRead(0);
  }
  return long(RAW/50);
}
unsigned long GetCO2()
{
  unsigned long RAW=0;
  selectCO2();
  for (int ii=1;ii<=50;ii++){
    RAW=RAW+analogRead(0);
  }
  return long(RAW/50);
}
unsigned long GetCO()
{
  unsigned long RAW=0;
  selectCO();
  for (int ii=1;ii<=50;ii++){
    RAW=RAW+analogRead(0);
  }
  return long(RAW/50);
}
void COPwrCycler(){
    currTimeCO = millis();
    if (currTimeCO - prevTimeCO > currCOPwrTimer){
      prevTimeCO = currTimeCO;
      COstatus=1;
    if(COPwrState == 71){
      COPwrState = 255;
      currCOPwrTimer = 60000;  //60 seconds at 5v
    }
    else{
      COPwrState = 71;
      currCOPwrTimer = 90000;  //90 seconds at 1.4v
    }
    analogWrite(COswpin,COPwrState);
    if (COPwrState==71){
      COstatus=COstatus+1;
    }
    else{
      COstatus=1;
    }
  }
}

String fname_date(DateTime ctime)
{
  String xday, xmonth, xx;
  // Converstion of the month and date to a string which will be displayed as the sdCard file name
  //One digit days
  if (ctime.day()<10){
    xday="0"+String(ctime.day());
  }
  else {
    xday=String(ctime.day());
  }
  //One digit months
  if (ctime.month()<10){
    xmonth="0"+String(ctime.month());
  }
  else {
    xmonth=String(ctime.month());
  }
   xx=String(ctime.year())+xmonth+xday;
  // Obtain the string xx and save as the name of the sdCard file
  return xx;
}
String recordstring(DateTime ctime){
  String xx3= String(rcount) + "\t" + String(ctime.year()) + "\t" + String(ctime.month()) + "\t" + String(ctime.day()) + "\t" +
	String(ctime.hour()) + "\t" + String(ctime.minute()) + "\t" + String(ctime.second()) + "\t" +
	String(Distance) + "\t" + String(Temp) + "\t" + String(long(time.tempC()*100)+27315) + "\t" +
	String(Dust) + "\t" + String(CO2) + "\t" + String(CO) + "\t" + String(movement) + "\t" + String(COstatus);
  return xx3;
}
void SaveData(DateTime xtime)
{
  //Movement from PIR
  if (digitalRead(PIRPin)==LOW){movement=1;}
  //Dust from Dust sensor
  Dust=GetDust();
  //Distance from Range Finder
  Distance=GetDistance();
  //Serial.println("Distance Done");
  //Temperature from analog
  Temp=GetTemperature();
  //Serial.println("Temperature Done");
  //CO2 from analog
  CO2=GetCO2();
  Serial.println("CO2 Done");
  //CO from analog
  CO=GetCO();
  Serial.println("CO Done");
  //Increment Record count
  rcount++;
  //Get the current RECORD string
  String currRecord=recordstring(xtime);
  Serial.println("Current Time Done");
  //Output the measured values
  //To the serial port
  Serial.println(currRecord);
  //To the file output
  //Open the current file
  Serial.println("Opening file");
  //digitalWrite(13,HIGH);
  fname=String(fname_date(xtime)+".txt");
  fname.toCharArray(file_fname,fname.length()+1);
  currfile=SD.open(file_fname, FILE_WRITE);
  //Write to the file
  Serial.println("Writing to file");
  currfile.println(currRecord);
  currfile.close();
  Serial.println("Writing to file Done");
  //Reinitialise the variables
  Dust=0;
  Distance=0;
  Temp=0;
  CO2=0;
  CO=0;
  movement=0;
  //check CO pwr cycle
  COPwrCycler();
  //pat the watchdog
  //wdt_reset();
}
void selectDUST(){
  digitalWrite(x9,LOW);
  digitalWrite(x10,LOW);
}
void selectRF(){
  digitalWrite(x9,LOW);
  digitalWrite(x10,LOW);
}
void selectTEMP(){
  digitalWrite(x9,LOW);
  digitalWrite(x10,HIGH);
}
void selectCO2(){
  digitalWrite(x9,HIGH);
  digitalWrite(x10,LOW);
}
void selectCO(){
  digitalWrite(x9,HIGH);
  digitalWrite(x10,HIGH);
}
void setup(){
  //Set up serial comms
  Serial.begin(57600);
  
  //Set up RTC
  Wire.begin();
  RTC.begin();   // the function to get the time from the RTC
  time=RTC.now();
  Serial.println(fname_date(time));
  //Set up PIR
  Serial.println("Setting PIR");
  pinMode(PIRPin,INPUT);
  //Set up AnalogDemux
  Serial.println("Setting DeMux");
  pinMode(x9,OUTPUT);
  pinMode(x10,OUTPUT);
  //Set the analog read pin modes
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  //Set up file(s)
  Serial.println("Initialising SD card");
  
  // Comment this out so that I can use the serial printing 
 pinMode(10, OUTPUT); //Pin 10 must be set as an output for the SD communication to work.

  
 if (!SD.begin(10)){
    //Initialize the SD card and configure the I/O pins.
    //Serial.println("Initialisation failed!!");
   return;
 }

  
  Serial.println("Initialisation done.");
  fname=String(fname_date(time)+".txt");
  fname.toCharArray(file_fname,fname.length()+1);
  currfile=SD.open(file_fname, FILE_WRITE);
  currfile.println("Count\tYear\tMonth\tDay\tHour\tMinute\tSecond\tDistance\tTmpOUT\tTmpIN\tPM\tCO2\tCO\tMovement\tCOstatus");
  currfile.close(); //Close the file
  Serial.println(file_fname);
  //Serial data headers
  Serial.println("Count\tYear\tMonth\tDay\tHour\tMinute\tSecond\tDistance\tTmpOUT\tTmpIN\tPM\tCO2\tCO\tMovement\tCOstatus");
  //Initialise variables
  Dust=0;
  Distance=0;
  Temp=0;
  movement=0;
  CO2=0;
  CO=0;
  //Initialise CO cycling
  currTimeCO=0;
  prevTimeCO=0;
  currCOPwrTimer=500;
  COPwrState=71;
  COstatus=1;
  pinMode(COswpin,OUTPUT);
  psec=time.second();
}
void loop(){
  time=RTC.now();
  csec=time.second();
  if (csec!=psec) {
    psec=csec;
    SaveData(time);
  }
}
