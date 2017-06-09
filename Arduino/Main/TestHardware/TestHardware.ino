void setup(){

  // check sd card format, connection etc.
  CheckSD();

  // check that devices are connected to I2C bus and what addresses they have
  // This line should only take a few seconds to run. If it takes several minutes then there is a fault in the hardware I2C connection
  ScanI2CBus();
}

void loop(){
  
}

