//long pmcf1=0;
//long pmcf25=0;
//long pmcf10=0;
//long pmat1=0;
//long pmat25=0;
//long pmat10=0;

//char buf[50];

void DUST_setup() {
  Serial2.begin(9600);
}


void show(String environment, String particle_size){
  Serial.print(environment + ", PM " + particle_size + " = ");
  Serial.print(calc_pm());
  Serial.println(" ug/m3");
}

unsigned char c;
  
long calc_pm(){ 
  return 256 *( 2 * c);
}

void DUST_loop() {

  int count = 0;
  
  while (Serial2.available()) {
    
    c = Serial2.read();
    
    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
      Serial.println("check failed");
      break;
    }

    if(count == 5){
      show("CF = 1", "1");
    }
    else if(count == 7){
      show("CF = 1", "2.5");
    }
    else if(count == 9){
      show("CF = 1", "10");
    }
    else if(count == 11){
      show("atmosphere", "1.0");
    }
    else if(count == 13){
      show("atmosphere", "2.5");
    }
    else if(count == 15){
      show("atmosphere", "10");
    }
    if(count > 15){
      Serial.println("complete");
      break;
    }

    count++;
  }
  while(Serial2.available()) Serial2.read();
  Serial.println();
  delay(5000);
}

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
  

