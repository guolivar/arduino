/*
 WiFiEsp example: WebClientRepeating

 This sketch connects to a web server and makes an HTTP request
 using an Arduino ESP8266 module.
 It repeats the HTTP call each 10 seconds.

 For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

// note need to install arduino json using library manager

#include "src/WiFiEsp.h"

char ssid[] = "4G UFI_8B8";           // your network SSID (name)
char pass[] = "1234567890";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "192.168.100.100";

unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds

// Initialize the Ethernet client object
WiFiEspClient client;

void setup()
{
  // initialize serial for debugging
  Serial.begin(115200);
  
  // initialize serial for ESP module
//  Serial2.begin(115200);
  // initialize ESP module
  WiFi.init(&Serial);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
//    ////Serial.println("WiFi shield not present");
    
    //change this so that it doesnt waste time doing other wifi setup stuff but does carry on to use sd card etc
     
    // don't continue
    while (true);

      
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
//    Serial.print("Attempting to connect to WPA SSID: ");
//    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

//  Serial.println("You're connected to the network");
  
//  printWifiStatus();
}

void loop()
{
  // if there's incoming data from the net connection send it out the serial port
  // this is for debugging purposes only
//  while (client.available()) {
//    char c = client.read();
//    Serial.write(c);
//  }

  // if 10 seconds have passed since your last connection,
  // then connect again and send data
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}

// this method makes a HTTP connection to the server
void httpRequest()
{
  ////Serial.println();
    
  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection
  if (client.connect(server, 8080)) {
    ////Serial.println("Connecting...");
    int value = 23;
    String content = "{\"key\":" + String(value) + "}";
    // send the HTTP PUT request
    client.println(F("POST /arduino HTTP/1.1"));
    client.println(F("Host: 192.168.100.100"));
    client.println(F("Accept: */*"));
    client.println("Content-Length:" + String(content.length()));
    client.println(F("Content-Type: application/json"));
    client.println(content);
    client.println(F("Connection: close"));
    client.println();

    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection
//    Serial.println("Connection failed");
  }
}


//void printWifiStatus()
//{
//  // print the SSID of the network you're attached to
//  //Serial.print("SSID: ");
//  ////Serial.println(WiFi.SSID());
//
//  // print your WiFi shield's IP address
//  IPAddress ip = WiFi.localIP();
//  //Serial.print("IP Address: ");
//  ////Serial.println(ip);
//
//  // print the received signal strength
//  long rssi = WiFi.RSSI();
//  //Serial.print("Signal strength (RSSI):");
//  //Serial.print(rssi);
//  ////Serial.println(" dBm");
//}







void CheckVoltage(){
  Serial.print(analogRead(A1) * (5.0/1023.0));
  Serial.println(F("V"));
}
//
//
/////*
//// WiFiEsp example: WebClient
//// This sketch connects to google website using an ESP8266 module to
//// perform a simple web search.
//// For more details see: http://yaab-arduino.blogspot.com/p/wifiesp-example-client.html
////*/
////
//#include "src/WiFiEsp.h"
////
////// Emulate Serial2 on pins 6/7 if not present
//////#ifndef HAVE_HWSerial2
//////#include "SoftwareSerial.h"
//////SoftwareSerial Serial2(6, 7); // RX, TX
////// Initialize the Ethernet client object
//WiFiEspClient client;
////
//////#endif
////
//char ssid[] = "4G UFI_8B8";            // your network SSID (name)
//char pass[] = "1234567890";        // your network password
//int status = WL_IDLE_STATUS;     // the Wifi radio's status
//
//char server[] = "arduino.cc";
//void setup()
//{
//  // initialize serial for debugging
//  Serial.begin(115200);
//  // initialize serial for ESP module
//  Serial2.begin(115200);
//  // initialize ESP module
//  WiFi.init(&Serial2);
//
//  // check for the presence of the shield
//  if (WiFi.status() == WL_NO_SHIELD) {
//    ////Serial.println("WiFi shield not present");
//    // don't continue
//    while (true);
//  }
//
//  // attempt to connect to WiFi network
//  while ( status != WL_CONNECTED) {
//    //Serial.print("Attempting to connect to WPA SSID: ");
//    ////Serial.println(ssid);
//    // Connect to WPA/WPA2 network
//    status = WiFi.begin(ssid, pass);
//  }
//
//  // you're connected now, so print out the data
//  ////Serial.println("You're connected to the network");
//
//  printWifiStatus();
//
//  ////Serial.println();
//  ////Serial.println("Starting connection to server...");
//  // if you get a connection, report back via serial
//  char url[] = "192.168.100.100:8080/12332_12_31_23434_12_2434_2342425_242132_2421_4124_5335_535363_134124_4234_5235_true_2016-6-23";
//  if (client.connect( url , 80)) {
//    ////Serial.println("Connected to server");
//    
//    // Make a HTTP request
////    String content = "Hey, just testing a post request.";
////    client.println("POST YOUR_RESOURCE_URI HTTP/1.1");
////    client.println("Host: SERVER:PORT");
////    client.println("Accept: */*");
////    client.println("Content-Length: " + content.length());
////    client.println("Content-Type: application/x-www-form-urlencoded");
////    client.println();
////    client.println(content);
//  }
//
//}
//
//void loop()
//{
//  // if there are incoming bytes available
//  // from the server, read them and print them
//  while (client.available()) {
//    char c = client.read();
//    Serial.write(c);
//  }
//
//  // if the server's disconnected, stop the client
//  if (!client.connected()) {
//    ////Serial.println();
//    ////Serial.println("Disconnecting from server...");
//    client.stop();
//
//    // do nothing forevermore
//    while (true);
//  }
//}
//
//
//void printWifiStatus()
//{
//  // print the SSID of the network you're attached to
//  //Serial.print("SSID: ");
//  ////Serial.println(WiFi.SSID());
//
//  // print your WiFi shield's IP address
//  IPAddress ip = WiFi.localIP();
//  //Serial.print("IP Address: ");
//  ////Serial.println(ip);
//
//  // print the received signal strength
//  long rssi = WiFi.RSSI();
//  //Serial.print("Signal strength (RSSI):");
//  //Serial.print(rssi);
//  ////Serial.println(" dBm");
//}
