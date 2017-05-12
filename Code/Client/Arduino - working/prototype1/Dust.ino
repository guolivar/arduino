//////
//#include <SoftwareSerial.h>
//SoftwareSerial dustport(8,9);
//
//void DUST_setup() {
//  dustport.begin(9600);
//  
//}
////
//////
//////void show(String environment, String particle_size){
//////  Serial.print(environment + ", PM " + particle_size + " = ");
//////  Serial.print(calc_pm());
//////  Serial.println(" ug/m3");
//////}
////
////byte c;
////  
////long calc_pm(){ 
////  return 256 *( 2 * c);
////}
////
////// look into difference between atmosphere and the cm values
////#define Sep( val ) val + ","
////
////
////
////long pm1 = 0;
////
//////pm 2.5
////long pm25 = 0;
////
//////pm 10
////long pm10 = 0;
////
////String DUST_loop() {
////  int count = 0;
////  pm1 = 0;
////
////  //pm 2.5
////  pm25 = 0;
////  
////  //pm 10
////  pm10 = 0;
//// while (dustport.available()) {
////    c = dustport.read();
////
////    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
////      Serial.println(F("check failed"));
////    }
////
////    if(count == 11){
////      pm1 = calc_pm();
////    }
////    else if(count == 13){
////      pm25 = calc_pm();
////    }
////    else if(count == 15){
////      pm10 = calc_pm();
////
////
////    }
////    if(count > 15){
////      Serial.println(F("complete"));
//////      Serial.println(String(pm1) + " " + String(pm25) + " " + String(pm10) + " " + String(count));
//////       Serial.println(String(pm1));
//////       Serial.println(String(pm25));
//////       Serial.println(String(pm10));
//////      Serial.println(NULL);
//////      if(!pm1 && !pm25 && !pm10){
////
////      /// ,ight have to try and test each one individually store final results in vars and then return them as null or not null based on values
//////      if(pm1 != NULL && pm25 != NULL && pm10 != NULL){
//////        
////        return Sep(String(pm1)) + Sep(String(pm25)) + String(pm10);
//////      }
//////      else{
//////        return F("null,null,null");
//////      }
////
////    }
////
//////    check_mem();
////
////   
//////    char text[30];
//////    sprintf(text, "heap memory: %p\n", heapptr);
//////    Serial.println(text);
//////    sprintf(text, "stack memory: %p\n", stackptr);
//////    Serial.println(text); 
////
////    count++;
////  }
////
////
////  while(dustport.available()) dustport.read();
////  Serial.println();
////  delay(5000);
////}
////
//
//
//#include <SoftwareSerial.h>
//SoftwareSerial dustport(8,9);
//
//void DUST_setup() {
//  //mega
//  //Serial2.begin(9600);
//  dustport.begin(9600);
//  
//}
//
//
//String show(String environment, String particle_size){
//  Serial.print(environment + ", PM " + particle_size + " = ");
//  Serial.print(calc_pm());
//  Serial.println(" ug/m3");
//
//  return String(calc_pm());
//}
//
//unsigned char c;
//  
//long calc_pm(){ 
//  return 256 *( 2 * c);
//}
//
//String DUST_loop() {
//
//  int count = 0;
//
//  String vals = "";
//
//  //mega
////  while (Serial2.available()) {
////    
////    c = Serial2.read();
//
// while (dustport.available()) {
//    c = dustport.read();
//    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
//      Serial.println("check failed");
//      break;
//    }
//
//    if(count == 5){
//      show("CF = 1", "1");
//    }
//    else if(count == 7){
//      show("CF = 1", "2.5");
//    }
//    else if(count == 9){
//      show("CF = 1", "10");
//    }
//    else if(count == 11){
//      vals = vals + show("atmosphere", "1.0");
//    }
//    else if(count == 13){
//      vals = vals + "," + show("atmosphere", "2.5");
//    }
//    else if(count == 15){
//      vals = vals + "," + show("atmosphere", "10");
//    }
//    if(count > 15){
//      Serial.println("complete");
////      break;
//      return vals;
//    }
//
//    count++;
//  }
//  //mega
//  //while(Serial2.available()) Serial2.read();
//  while(dustport.available()) dustport.read();
//  Serial.println();
//  delay(5000);
//}


//long pmcf10=0;
//long pmcf25=0;
//long pmcf100=0;


//using namespace virtmem;

// Create virtual a memory allocator that uses SD card (with FAT filesystem) as virtual memory pool
// The default memory pool size (1 MB) is used.
//SDVAlloc valloc;
//
//int pmat10=0;
//int pmat25=0;
//int pmat100=0;
////
////VPtr <int, SDVAlloc> pmat10= 0;
////VPtr <int, SDVAlloc>t pmat25=0;
////VPtr <int, SDVAlloc> pmat100=0;
//
//char buf[50];
//
////#include <SoftwareSerial.h>
////SoftwareSerial dustport(8,9);
////Serial dustport; 
//
//void DUST_setup() {
//  // put your setup code here, to run once:
//  //Serial.begin(9600);
////  Serial2.begin(9600);
//  
////  valloc.start();
//
//  
////  dustport.begin(9600);
//  Serial1.begin(9600);
//}
//
//String DUST_loop() {
//  // put your main code here, to run repeatedly:
//  int count = 0;
//  unsigned char c;
//  unsigned char high;
////  Serial.println(Serial2.available());
////  while (dustport.available()) {
//  while (Serial1.available()) {
////    c = dustport.read();
//    c = Serial1.read();
//    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
//      Serial.println(F("check failed"));
//      break;
//
//      // bug fails 90% of the time
//      return "check failed";
//
//      ///// this appears to be the failing point it makes it work like this but when check fails it becomes unstable
//    }
//
//    if(count > 15){
//      Serial.println(F("complete"));
//      
//
//      // consider returning a long array instead because string concatenation dodgy
//
//      String result = String(pmat10) + ", " + String(pmat25) + ", " + String(pmat100);
//      return result;
////        long values [] = {pmat10, pmat25, pmat100};
////        return values;
//    }
//    else if(count == 4 || count == 6 || count == 8 || count == 10 || count == 12 || count == 14) {
//      high = c;
//    }
//
//    //// note we are not using the pmcf values -- think it might be combustion??? we comment out to save ram
////    else if(count == 5){
//////      pmcf10 = 256*high + c;
//////      Serial.print("CF=1, PM1.0=");
//////      Serial.print(pmcf10);
//////      Serial.println(" ug/m3");
////    }
////    else if(count == 7){
//////      pmcf25 = 256*high + c;
//////      Serial.print("CF=1, PM2.5=");
//////      Serial.print(pmcf25);
//////      Serial.println(" ug/m3");
////    }
////    else if(count == 9){
//////      pmcf100 = 256*high + c;
//////      Serial.print("CF=1, PM10=");
//////      Serial.print(pmcf100);
//////      Serial.println(" ug/m3");
////    }
//    else if(count == 11){
//      
////      if(256*high + c;)
//      pmat10 = 256*high + c;
//      Serial.print(F("Free Ram in dust: "));
//      Serial.println(freeRam());
//      Serial.println(pmat10);
//      
////      Serial.print("atmosphere, PM1.0=");
////      Serial.print(pmat10);
////      Serial.println(" ug/m3");
//    }
//    else if(count == 13){
//      pmat25 = 256*high + c;
//      Serial.print(F("Free Ram in dust: "));
//      Serial.println(freeRam());
//      Serial.println(pmat25);
////      Serial.print("atmosphere, PM2.5=");
////      Serial.print(pmat25);
////      Serial.println(" ug/m3");
//    }
//    else if(count == 15){
//      pmat100 = 256*high + c;
//      Serial.print(F("Free Ram in dust: "));
//      Serial.println(freeRam());
//      Serial.println(pmat100);
////      Serial.print("atmosphere, PM10=");
////      Serial.print(pmat100);
////      Serial.println(" ug/m3");
//    }
//    count++;
//  }
////  while(dustport.available()) dustport.read();
////  while(Serial1.available()) Serial1.read();
////  dustport.println();
//  delay(5000);
//}

//#define receiveDatIndex 24 // Sensor data payload size
//
////Variable declarations
//byte receiveDat[receiveDatIndex]; //receive data from the air detector module
//boolean valid_data;
//unsigned int PM1,PM25,PM10;
//unsigned int checkSum,checkresult;
//void readDust(){
//  while (Serial2.peek()!=66){
//    receiveDat[0]=Serial2.read();
//  }
//  Serial2.readBytes((char *)receiveDat,receiveDatIndex);
//  checkSum = 0;
//  for (int i = 0;i < receiveDatIndex;i++){
//    checkSum = checkSum + receiveDat[i];
//  }
//  checkresult = receiveDat[receiveDatIndex-2]*256+receiveDat[receiveDatIndex-1]+receiveDat[receiveDatIndex-2]+receiveDat[receiveDatIndex-1];
//  valid_data = (checkSum == checkresult);
//}
//
//byte getData(unsigned int index){
//  return (receiveDat[index]*256)+receiveDat[index + 1];
//}
//
// void loop(){
//  readDust();
//  PM1 = (receiveDat[4]*256)+receiveDat[5];
//  PM25 = (receiveDat[6]*256)+receiveDat[7];
//  PM10 = (receiveDat[8]*256)+receiveDat[9];
//  String message1 = String(PM1) + F("\t") + String(PM25) + F("\t") + String(PM10);
//
//  Serial.println(message1);
////  Serial.write(getData(4));
////  Serial.write(getData(8));
////  getData(6);
////  getData(8);
//
//    
// }
  
//long pmcf1=0;
//long pmcf25=0;
//long pmcf10=0;
//long pmat1=0;
//long pmat25=0;
//long pmat10=0;

//char buf[50];

//#include <SoftwareSerial.h>
//SoftwareSerial dustport(8,9);

#include <SoftwareSerial.h>
SoftwareSerial dustport(8,9);

void DUST_setup() {
  //mega
//  Serial1.begin(9600);
  dustport.begin(9600);
  
}


//void show(String environment, String particle_size){
//  Serial.print(environment + ", PM " + particle_size + " = ");
//  Serial.print(calc_pm());
//  Serial.println(" ug/m3");
//}
//
//unsigned char c;
//  
//long calc_pm(){ 
//  return 256 *( 2 * c);
//}
//
//void DUST_loop() {
//
//  int count = 0;
//
//  //mega
//  while (Serial1.available()) {
//    
//    c = Serial1.read();
//
//// while (dustport.available()) {
////    c = dustport.read();
//    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
//      Serial.println("check failed");
//      break;
//    }
//
//    if(count == 5){
//      show("CF = 1", "1");
//    }
//    else if(count == 7){
//      show("CF = 1", "2.5");
//    }
//    else if(count == 9){
//      show("CF = 1", "10");
//    }
//    else if(count == 11){
//      show("atmosphere", "1.0");
//    }
//    else if(count == 13){
//      show("atmosphere", "2.5");
//    }
//    else if(count == 15){
//      show("atmosphere", "10");
//    }
//    if(count > 15){
//      Serial.println("complete");
//      break;
//    }
//
//    count++;
//  }
//  //mega
//  while(Serial1.available()) Serial1.read();
////  while(dustport.available()) dustport.read();
//  Serial.println();
//  delay(5000);
//}

#define receiveDatIndex 24 // Sensor data payload size

//Variable declarations
byte receiveDat[receiveDatIndex]; //receive data from the air detector module
boolean valid_data;
unsigned int PM1,PM25,PM10;
unsigned int checkSum,checkresult;


void readDust(){
  while (dustport.peek()!=66){
    receiveDat[0]=dustport.read();
  }
  dustport.readBytes((char *)receiveDat,receiveDatIndex);
  checkSum = 0;
  for (int i = 0;i < receiveDatIndex;i++){
    checkSum = checkSum + receiveDat[i];
  }
  checkresult = receiveDat[receiveDatIndex-2]*256+receiveDat[receiveDatIndex-1]+receiveDat[receiveDatIndex-2]+receiveDat[receiveDatIndex-1];
  valid_data = (checkSum == checkresult);
}

byte getData(unsigned int index){
  return (receiveDat[index]*256)+receiveDat[index + 1];
}

 String DUST_loop(){
  readDust();
  PM1 = (receiveDat[4]*256)+receiveDat[5];
  PM25 = (receiveDat[6]*256)+receiveDat[7];
  PM10 = (receiveDat[8]*256)+receiveDat[9];
  String message1 = String(PM1) + F(",") + String(PM25) + F(",") + String(PM10);

//  Serial.println(message1);
  return message1;
  
//  Serial.write(getData(4));
//  Serial.write(getData(8));
//  getData(6);
//  getData(8);

    
 }
  

