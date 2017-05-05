/*
Copyright (c) 2016 Amphenol Advanced Sensors
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

void setupTemp(){
 //Serial.begin(115200);  // start serial for output

 Wire.begin();
// Serial.println("Amphenol Advanced Sensors");
// Serial.println("Arduino T9602 Monitor");
}

void getdata(byte *a, byte *b, byte *c, byte *d)
{

//  //Serial.println(*a);
//
  Wire.beginTransmission(40);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(40, 4);
  *a = Wire.read();
  //Serial.println(*a);

  *b = Wire.read();
  *c = Wire.read();
  *d = Wire.read();
}

float adjust_temp(float rawData){
  return rawData;
}

#define Sep( val ) val + ","

String Temp_loop()
{
 byte aa,bb,cc,dd;
 float temperature=0.0;  float humidity=0.0;
 getdata(&aa,&bb,&cc,&dd);

// humidity = (rH_High [5:0] x 256 + rH_Low [7:0]) / 16384 x 100
 humidity = (float)(((aa & 0x3F ) << 8) + bb) / 16384.0 * 100.0;

// temperature = (Temp_High [7:0] x 64 + Temp_Low [7:2]/4 ) / 16384 x 165 40
 temperature = adjust_temp((float)((unsigned)(cc  * 64) + (unsigned)(dd >> 2 )) / 16384.0 * 165.0 - 40.0);

// 2 2000 delays

  return Sep(String(temperature)) + String(humidity);
}

