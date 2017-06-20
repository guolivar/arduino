//void setup() {
//  Serial.setTimeout(5000);
//  Serial.begin(115200);
//  Serial2.begin(115200);
//
//  delay(1000);
//}
//
//void loop() {
////  delay(2000);
//  Serial2.println("AT");
//  CheckVoltage();
//
//  Serial.println(Serial2.readString());//  Serial1.println(command);
//  delay(100);
////  if(Serial1.available())
////  {
////    while(Serial1.available())
////    {
////      char c=Serial1.read();
////      Serial.write(c);          
////    }
////  }
//}


void CheckVoltage(){
  Serial.print(analogRead(A1) * (5.0/1023.0));
  Serial.println(F("V"));
}


///*
// WiFiEsp example: WebClient
// This sketch connects to google website using an ESP8266 module to
// perform a simple web search.
// For more details see: http://yaab-arduino.blogspot.com/p/wifiesp-example-client.html
//*/
//
#include "WiFiEsp.h"
//
//// Emulate Serial1 on pins 6/7 if not present
////#ifndef HAVE_HWSERIAL1
////#include "SoftwareSerial.h"
////SoftwareSerial Serial1(6, 7); // RX, TX
//// Initialize the Ethernet client object
WiFiEspClient client;
//
////#endif
//
char ssid[] = "4G UFI_8B8";            // your network SSID (name)
char pass[] = "1234567890";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
//
char server[] = "arduino.cc";
//
//// AT+RST
////#define num_words 100
//
////AT&GMR
////#define num_words 7
void setup()
{
//  Serial.begin(115200);
//
//  long bauds[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 74880, 115200, 230400, 250000, 500000, 1000000, 2000000};
//
//  // scanning baud rates
////  for(int i = 0; i< sizeof(bauds)/sizeof(long); i++){
//
//  Serial.println("Scanning");
//  Serial.println(sizeof(bauds)/sizeof(long));
//  
//  for(int i = 0; i < sizeof(bauds)/sizeof(long); i++){
//    Serial1.begin(bauds[i]);
//
//    Serial.print("Scanning baud ");
//    Serial.println(bauds[i]);
//    Serial1.print("AT+GMR");
//
//    // length 100 says error with baudrate 115200
//
////    char words[num_words];
//
//    //scan 10 bytes to be sure
////    Serial1.readBytes(words, num_words);
//    
//    Serial.println(Serial1.readString(), DEC);
//    Serial1.flush();
//  }
//  
  // initialize serial for debugging
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial2.begin(115200);
  // initialize ESP module

  
  WiFi.init(&Serial2);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");

  printWifiStatus();

  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
  if (client.connect(server, 80)) {
    Serial.println("Connected to server");
    // Make a HTTP request
    String content = "Hey, just testing a post request.";
    client.println("POST YOUR_RESOURCE_URI HTTP/1.1");
    client.println("Host: SERVER:PORT");
    client.println("Accept: */*");
    client.println("Content-Length: " + content.length());
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println();
    client.println(content);
  }

}

void loop()
{
  // if there are incoming bytes available
  // from the server, read them and print them
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client
  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting from server...");
    client.stop();

    // do nothing forevermore
    while (true);
  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
