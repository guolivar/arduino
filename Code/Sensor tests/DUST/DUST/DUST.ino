////G3-Arduino source code <reference only>
////#include
//
//long pmcf10 = 0;
//long pmcf25 = 0;
//long pmcf100 = 0;
//long pmat10 = 0;
//long pmat25 = 0;
//long pmat100 = 0;
//
//char buf [50];
//
//void setup () {
//// put your setup code here, to run once:
//Serial.begin (9600);
//Serial1.begin (9600);
//}}
//
//void  loop () {
//// put your main code here, to run repeatedly:
//int  count = 0;
//unsigned  char c;
//unsigned  char high;
//while  (Serial1.available ()) {
//C = Serial1.read ();
//if  ((count == 0 && c! = 0x42) || (count == 1 && c! = 0x4d)) {
//Serial.println ("check failed");
//break ;
//}}
//if  (count> 15) {
//Serial.println ("complete");
//break ;
//}}
//else  if (count == 4 || count == 6 || count == 8 || count == 10 || count == 12 || count == 14) high = c;
//else  if (count == 5) {
//Pmcf10 = 256 * high + c;
//Serial.print ("CF = 1, PM1.0 =");
//Serial.print (pmcf10);
//Serial.println ("ug / m3");
//}}
//else  if (count == 7) {
//Pmcf25 = 256 * high + c;
//Serial.print ("CF = 1, PM2.5 =");
//Serial.print (pmcf25);
//Serial.println ("ug / m3");
//}}
//else  if (count == 9) {
//Pmcf100 = 256 * high + c;
//Serial.print ("CF = 1, PM10 =");
//Serial.print (pmcf100);
//Serial.println ("ug / m3");
//}}
//else  if (count == 11) {
//Pmat10 = 256 * high + c;
//Serial.print ("atmosphere, PM1.0 =");
//Serial.print (pmat10);
//Serial.println ("ug / m3");
//}}
//else  if {count == 13) {
//Pmat25 = 256 * high + c;
//Serial.print ("atmosphere, PM2.5 =");
//Serial.print (pmat25);
//Serial.println ("ug / m3");
//}}
//else  if (count == 15) {
//Pmat100 = 256 * high + c;
//Serial.print ("atmosphere, PM10 =");
//Serial.print (pmat100);
//Serial.println ("ug / m3");
//}}
//count ++
//}}
//while  (Serial1.available ()) Serial1.read ();
//Serial.println ();
//Delay (5000);
//}}
//



// other code

//******************************
//*Abstract: Read value of PM1,PM2.5 and PM10 of air quality
//
//*Version：V3.1
//*Author：Zuyang @ HUST
//*Modified by Cain for Arduino Hardware Serial port compatibility
//*Date：March.25.2016
//******************************
#include <Arduino.h>
#define LENG 31   //0x42 + 31 bytes equal to 32 bytes
unsigned char buf[LENG];

int PM01Value=0;          //define PM1.0 value of the air detector module
int PM2_5Value=0;         //define PM2.5 value of the air detector module
int PM10Value=0;         //define PM10 value of the air detector module

#include <SoftwareSerial.h>
//SoftwareSerial dustport(10,11);
SoftwareSerial dustport(4,8);

void setup()
{
  Serial.begin(9600);   //use serial0

  dustport.begin(9600);
  dustport.setTimeout(1500);    //set the Timeout to 1500ms, longer than the data transmission periodic time of the sensor

}

char checkValue(unsigned char *thebuf, char leng)
{
  char receiveflag=0;
  int receiveSum=0;

  for(int i=0; i<(leng-2); i++){
    receiveSum=receiveSum+thebuf[i];
  }
  receiveSum=receiveSum + 0x42;

  if(receiveSum == ((thebuf[leng-2]<<8)+thebuf[leng-1]))  //check the serial data
  {
    receiveSum = 0;
    receiveflag = 1;
  }
  return receiveflag;
}


// compress all these functions out by just calling the same function 3 times and increment the index by 2

int transmitPM01(unsigned char *thebuf)
{
  // int PM01Val;
  // PM01Val=((thebuf[3]<<8) + thebuf[4]); //count PM1.0 value of the air detector module
  // return PM01Val;

  //return countPM(3, 4, thebuff);
  return countPM(3, buf);
}

//transmit PM Value to PC
int transmitPM2_5(unsigned char *buf)
{
  // int PM2_5Val;
  // PM2_5Val=((thebuf[5]<<8) + thebuf[6]);//count PM2.5 value of the air detector module
  // return PM2_5Val;

    //return countPM(5, 6. buf);
    return countPM(5, buf);
  }

//transmit PM Value to PC
int transmitPM10(unsigned char *buf)
{
  // int PM10Val;
  // PM10Val=((thebuf[7]<<8) + thebuf[8]); //count PM10 value of the air detector module
  // return PM10Val;

  //return countPM(7, 8, buf);
  return countPM(7, buf);
}

// int countPM(int index1, int index2, char *buf){
//
//   return ((buf[index1]<<8) + buf[index2]); //count PM10 value of the air detector module
// }

int countPM(int index, char * buf){
   return ((buf[index]<<8) + buf[index + 1]); //count PM10 value of the air detector module
}

void printPM(String unit, int value){
  Serial.print("PM " + unit + ": ");
  Serial.print(value);
  Serial.println(" ug/m3");
}

void loop()
{
  bool start_read = dustport.find(0x42);
  if(start_read == 0){    //start to read when detect 0x42

     if(buf[0] == 0x8d){
        if(checkValue(buf,LENG)){
          PM01Value=transmitPM01(buf); //count PM1.0 value of the air detector module
          PM2_5Value=transmitPM2_5(buf);//count PM2.5 value of the air detector module
          PM10Value=transmitPM10(buf); //count PM10 value of the air detector module
        }
      }

      static unsigned long OledTimer=millis();
        if (millis() - OledTimer >=1000)
        {
            OledTimer=millis();

            // Serial.print("PM 1.0: ");
            // Serial.print(PM01Value);
            // Serial.println(" ug/m3");
            printPM("1.0", PM01Value);
            printPM("2.5", PM2_5Value);
            printPM("10", PM10Value);

            // Serial.print("PM 2.5: ");
            // Serial.print(PM2_5Value);
            // Serial.println(" ug/m3");
            //
            // Serial.print("PM 10: ");
            // Serial.print(PM10Value);
            // Serial.println(" ug/m3");
            Serial.println();
          }
    } else{
      Serial.println("Address not found!");
    }

  }
