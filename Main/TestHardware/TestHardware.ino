void setup(){
  Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }
  // check sd card format, connection etc.
//  CheckSD();

  // check that devices are connected to I2C bus and what addresses they have
  // This line should only take a few seconds to run. If it takes several minutes then there is a fault in the hardware I2C connection
  ScanI2CBus();
}

void loop(){
  
}

