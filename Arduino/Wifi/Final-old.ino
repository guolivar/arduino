
void CheckVoltage(){
  Serial.print(analogRead(A1) * (5.0/1023.0));
  Serial.println(F("V"));
}

//char ssid[] = "";            // your network SSID (name)
//char pass[] = "1234567890";        // your network password

void show(){

  // read until newline character
  Serial.println(Serial2.readString());
//  delay(3000);
}

//void wait(){
//  Serial2.flush();
//  while(Serial2.available());
//}



void setup()
{
  // initialize serial for communicating
  Serial.begin(115200);
  Serial2.begin(115200);
  // should use onboard LED to communicate errors eg no shield == two light flash, no connect == 1 or something

  // need checks for wifi shield connection, wifi connection too for now blindly make requests

  // restart the esp8266 along with the arduino
//  Serial2.println(F("AT+RST"));
//  show();
//  show();
//  wait();
  Serial2.println(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"1234567890\""));
  show();
//  while(!Serial2.available());

  
  //wait();

  
//  Serial.println(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"1234567890\""));

//  show();
//  // check if wifi connected if not keep retrying until it works
//  while(Serial2.readString() != "WIFI GOT IP"){
//    Serial2.println(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"1234567890\""));
//    Serial.println(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"1234567890\""));
//    show();
//  }

  String url = "192.168.100.100";
  
//  show();
  while(!Serial2.available());
  Serial2.println("AT+CIPSEND=95");
  while(!Serial2.available());

  while(!Serial2.available());
  Serial2.println("AT+CIPSTART=\"TCP\",\"" + url + """\",8080");
  show();



//  wait();
  show();
 // while( Serial2.readString() != 

  // check for response to see if connection works and if it doesnt then retry

}

void loop()
{
  Serial2.println("GET /12332_12_31_23434_12_2434_2342425_242132_2421_4124_5335_535363_134124_4234_5235_true_2016-6-23");
  show();
//  Serial.println(Serial2.readString());
//  CheckVoltage();
  delay(2000);
}

