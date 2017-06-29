/*
 WiFiEsp example: WebClientRepeating

 This sketch connects to a web server and makes an HTTP request
 using an Arduino ESP8266 module.
 It repeats the HTTP call each 10 seconds.

 For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

#include "src/WiFiEsp.h"

//char ssid[] = "4G UFI_8B8";           // your network SSID (name)

char ssid[] = "DESKTOP-73HN8ON 5011";
char pass[] = "u65879Q0";   

//char pass[] = "1234567890";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "seat-skomobo.massey.ac.nz";

unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds

// Initialize the Ethernet client object
WiFiEspClient client;

void setup()
{
  // initialize serial for debugging
  Serial.begin(115200);

  // initialize ESP module
  WiFi.init(&Serial);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
//    ////Serial.println("WiFi shield not present");
    
    //change this so that it doesnt waste time doing other wifi setup stuff but does carry on to use sd card etc

    // actually a hardware reset button to restart this code with a interrupt would be good, wire it in to pin 3???
     
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
  
  printWifiStatus();
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
  if (client.connect(server, 80)) {
    ////Serial.println("Connecting...");
    
    // send the HTTP PUT request
//    client.println(F("GET /12332_12_31_23434_12_2434_2342425_242132_2421_4124_5335_535363_134124_4234_5235_true_2016-6-23 HTTP/1.1"));
    client.println(F("GET /0_2016-6-23_12332_12_31_23434_12_2434_1 HTTP/1.1"));
    client.println(F("Host: seat-skomobo.massey.ac.nz"));
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection
//    Serial.println("Connection failed");
  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  //Serial.print("SSID: ");
  ////Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  //Serial.print("IP Address: ");
  ////Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  //Serial.print("Signal strength (RSSI):");
  //Serial.print(rssi);
  ////Serial.println(" dBm");
}

// for using arduino mega as voltmeter
void CheckVoltage(){
  Serial.print(analogRead(A1) * (5.0/1023.0));
  Serial.println(F("V"));
}

