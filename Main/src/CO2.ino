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


void CO2_setup() {
   pinMode(13, OUTPUT); // address of the Arduino LED indicator

}

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
  if (i==0){
    bitSet(error,1);
  }

  ///////////////////////

  /* End Read Sequence */

  ///////////////////////

  /*

  Using some bitwise manipulation we will shift our buffer

  into an integer for general consumption

  */

  co2_value = 0;

  co2_value |= buffer[1] & 0xFF;

  co2_value = co2_value << 8;

  co2_value |= buffer[2] & 0xFF;

  //byte sum = 0; //Checksum Byte

  byte sum = buffer[0] + buffer[1] + buffer[2]; //Byte addition utilizes overflow

  if (sum != buffer[3]){
    bitSet(error, 0);
  }
  digitalWrite(13, LOW);
  return co2_value;
}


// make this more robust and efficient by merging this with above Function
// and storing NULL when it errors instead of 0 because at moment is confusing as to
// whether or not the 0 is due to error or legit

int CO2_loop(){
  bitClear(error,1);
  bitClear(error,2);
  CO2 = readCO2();
}
