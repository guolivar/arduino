
void Temp_setup(){
 Wire.begin();
}

void getdata(byte *a, byte *b, byte *c, byte *d)
{

  Wire.beginTransmission(40);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(40, 4);
  *a = Wire.read();

  *b = Wire.read();
  *c = Wire.read();
  *d = Wire.read();
}

float adjust_temp(float rawData){
  return rawData;
}

void Temp_loop()
{

 byte aa,bb,cc,dd;
 temperature=0.0; humidity=0.0;
 getdata(&aa,&bb,&cc,&dd);

// humidity = (rH_High [5:0] x 256 + rH_Low [7:0]) / 16384 x 100
 humidity = (float)(((aa & 0x3F ) << 8) + bb) / 16384.0 * 100.0;

// temperature = (Temp_High [7:0] x 64 + Temp_Low [7:2]/4 ) / 16384 x 165 40
 temperature = adjust_temp((float)((unsigned)(cc  * 64) + (unsigned)(dd >> 2 )) / 16384.0 * 165.0 - 40.0);

}

