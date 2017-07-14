/*
  WiFiEsp example: WebClientRepeating

  This sketch connects to a web server and makes an HTTP request
  using an Arduino ESP8266 module.
  It repeats the HTTP call each 10 seconds.

  For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

#include "src/WiFiEsp.h"

char ssid[] = "DESKTOP-73HN8ON5011";            // your network SSID (name)
char pass[] = "u65879Q0";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "seat-skomobo.massey.ac.nz";

unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds

// Initialize the Ethernet client object
WiFiEspClient client;

void WIFI_setup()
{

  // initialize ESP module
  WiFi.init(&Serial);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println(F("WiFi card not present"));
    // don't continue

    // fix this to be like old code ie reboot after one send etc
    //    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.println(F("Attempting to connect to AP"));
    //    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println(F("Connected to AP"));

  printWifiStatus();
}

void WIFI_send(char Time[], char PIR, char Temp[], int CO2, char Dust[])
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

    httpRequest(Time, PIR, Temp, CO2, Dust);
  }
}




// integrate this with rest of cocde feed real values

//test variable concatenation

// use other code for own at commands etc to see how to send real values

// remove screen if necessary

// if TCP connection failed then start from beginning agin so setup etc




// this method makes a HTTP connection to the server
void httpRequest(char Time[], char PIR, char Temp[], int CO2, char Dust[])
{
  Serial.println();

  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection
  if (client.connect(server, 80)) {
    Serial.println(F("Connecting..."));

    //    Dust.replace(",", "_");
    //
    //        // replace fullstops in CO2 and temp and humidity
    //    Temp.replace(",", "_");
    ////
    //    Time.replace(":", "_");
    //    Time.replace("/", "_");
    //    Time.replace(" ", "_");
    // send the HTTP PUT request
    //    client.println(F("GET /0_2016-6-23_12332_12_31_23434_12_2434_1 HTTP/1.1"));
    //    char request[70] = "\0";
    //    char request[70];
    //    String request1 = "GET /" BOX_ID "_" + Time + "_" + Dust;
    //    String request2 = "_" + Temp + "_" + String(CO2) + "_" + String(PIR);
    //    Serial.print("AT+CIPSEND=3," + String(request1.length() + request2.length() + 9));
    //    Serial.print(request1);
    //    Serial.print(request2);
    //    String request = "GET /";

    char request[17];
    
    sprintf(request, "GET /" BOX_ID "_%c HTTP/1.1", PIR);

//    char meta[] = " HTTP/1.1";

    //    "GET /" BOX_ID "_" + Time + "_" + Dust + "_" + Temp + "_" + String(CO2) + "_" + String(PIR);


    // magic code do not touch

//    strcat(request, PIR);
//    strcat(request, meta);



    //    char test[] = "GET / HTTP/1.1";
    //    char request[] =

    client.println(request);
    client.println(F("Host: seat-skomobo.massey.ac.nz"));
    client.println(F("Connection: close"));
    client.println();

    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection
    Serial.println(F("Connect failed"));
  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print(F("SSID: "));
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  Serial.print(F("IP Address: "));
  Serial.println(WiFi.localIP());

}
