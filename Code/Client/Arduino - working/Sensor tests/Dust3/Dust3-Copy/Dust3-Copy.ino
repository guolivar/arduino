long pmcf10=0;
long pmcf25=0;
long pmcf100=0;
long pmat10=0;
long pmat25=0;
long pmat100=0;

char buf[50];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
}

//void loop() {
//  // put your main code here, to run repeatedly:
//  int count = 0;
//  unsigned char c;
//  unsigned char high;
////  Serial.println(Serial2.available());
//  while (Serial2.available()) {
//    c = Serial2.read();
//    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
//      Serial.println("check failed");
//      break;
//    }
//    if(count > 15){
//      Serial.println("complete");
//      break;
//    }
//    else if(count == 4 || count == 6 || count == 8 || count == 10 || count == 12 || count == 14) {
//      high = c;
//    }
//    else if(count == 5){
//      pmcf10 = 256*high + c;
//      Serial.print("CF=1, PM1.0=");
//      Serial.print(pmcf10);
//      Serial.println(" ug/m3");
//    }
//    else if(count == 7){
//      pmcf25 = 256*high + c;
//      Serial.print("CF=1, PM2.5=");
//      Serial.print(pmcf25);
//      Serial.println(" ug/m3");
//    }
//    else if(count == 9){
//      pmcf100 = 256*high + c;
//      Serial.print("CF=1, PM10=");
//      Serial.print(pmcf100);
//      Serial.println(" ug/m3");
//    }
//    else if(count == 11){
//      pmat10 = 256*high + c;
//      Serial.print("atmosphere, PM1.0=");
//      Serial.print(pmat10);
//      Serial.println(" ug/m3");
//    }
//    else if(count == 13){
//      pmat25 = 256*high + c;
//      Serial.print("atmosphere, PM2.5=");
//      Serial.print(pmat25);
//      Serial.println(" ug/m3");
//    }
//    else if(count == 15){
//      pmat100 = 256*high + c;
//      Serial.print("atmosphere, PM10=");
//      Serial.print(pmat100);
//      Serial.println(" ug/m3");
//    }
//    count++;
//  }
//  while(Serial2.available()) Serial2.read();
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
  while (Serial2.peek()!=66){
    receiveDat[0]=Serial2.read();
  }
  Serial2.readBytes((char *)receiveDat,receiveDatIndex);
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

 void loop(){
  readDust();
  PM1 = (receiveDat[4]*256)+receiveDat[5];
  PM25 = (receiveDat[6]*256)+receiveDat[7];
  PM10 = (receiveDat[8]*256)+receiveDat[9];
  String message1 = String(PM1) + F("\t") + String(PM25) + F("\t") + String(PM10);

  Serial.println(message1);
//  Serial.write(getData(4));
//  Serial.write(getData(8));
//  getData(6);
//  getData(8);

    
 }
  

