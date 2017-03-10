


void ScanI2CBus()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
//    Serial.println("test: " + String(Wire.requestFrom(address, 1)));
    Serial.println("attempting " + String(address));
  
//    I2c.beginTransmission(address);
//    error = I2c.endTransmission();  
//    TwoWire twoWire = TwoWire();
//    twoWire.beginTransmission(address);
//    error = twoWire.endTransmission();
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    //Serial.println("Error: " + String(error));
    
    if (error == 0)
    {
      Serial.print("I2C device found at address ");
      Serial.print(address, DEC); Serial.println(" (decimal)");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address ");
      Serial.println(address, DEC);
    }
    else{
      Serial.println("Error was " + String(error));
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

}
