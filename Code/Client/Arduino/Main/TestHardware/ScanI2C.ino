#include <Wire.h>

void ScanI2CBus()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning");

  nDevices = 0;
  for (address = 1; address <= 127; address++ )
  {
    // The i2c_scanner uses the return value of Write.endTransmisstion to see if a module is connected to that address

    // real time clock address = 104, m version of i2c clock has address 00h according to datasheet
    Wire.beginTransmission(address);

    //  todo use a watchdog timer for this would be good if I can somehow 
    // timeout if timeout is reached then we assume that there is a hardware issue with the i2c bus
    // https://learn.adafruit.com/multi-tasking-the-arduino-part-2/timers
    /// or use a timed interrupt so that once time is exceeded then it swaps to the error message printer and says hardware issue
    
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at ");
      Serial.print(address, DEC); Serial.println(" (decimal)");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at ");
      Serial.println(address, DEC);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

}
