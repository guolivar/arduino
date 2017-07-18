/*
  WiFiEsp example: WebClientRepeating

  This sketch connects to a web server and makes an HTTP request
  using an Arduino ESP8266 module.
  It repeats the HTTP call each 10 seconds.

  For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

#include "src/WiFiEsp.h"


// make a macro that stores all these strings in flash and then reads out char arrays at runtime?
// make a seperate function that constructs the array using the one that reads out individual chars

char ssid[] = HOTSPOT;            // your network SSID (name)
char pass[] = PASSWORD;        // your network password
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


  // put in proper retrys here
  // check for the presence of the shield

  show_P("Checking\n WIFI card");
  if (WiFi.status() == WL_NO_SHIELD) {
    show_P("WiFi card\n not present");
    // don't continue
    return;

    // fix this to be like old code ie reboot after one send etc
    //    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    show_P("Connecting\n to AP");
    //    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // Serial.println(F("Connected to AP"));
  show_P("Connected\n to AP");
  // printWifiStatus();
}


// merge this function with the http request one g

void WIFI_send()
{
  // if there's incoming data from the net connection send it out the serial port
  // this is for debugging purposes only
  //  while (client.available()) {
  //    char c = client.read();
  //    Serial.write(c);
  //  }

  // keep this for robustness 

  // check if TCP closed if yes then restart?

  // try improving hardware and further reducing memory to improve robustness

  // if 10 seconds have passed since your last connection,
  // then connect again and send data
  if (millis() - lastConnectionTime > postingInterval) {

    httpRequest();
  }
}




// integrate this with rest of cocde feed real values

//test variable concatenation

// use other code for own at commands etc to see how to send real values

// remove screen if necessary

// if TCP connection failed then start from beginning agin so setup etc

char request[47];

void send_data(){
   // if there's a successful connection
  if (client.connect(server, 80)) {
    show_P("Sending data\nto server");
    
    // may need to make seperate get requests so that it can cope

    // maybe make one route for each sensor value??

    // after that put in the script to start the server on boot using this https://www.computerhope.com/issues/ch000322.htm

   
    // sprintf_P(request, PSTR("GET /1_" BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d HTTP/1.1"), year, month, day, hout, minute, second, PM1, PM25, PM10);

    client.println(request);

    client.println(F("Host: seat-skomobo.massey.ac.nz "));
    client.println(F("Connection: close"));
    client.println();

    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection
   show_P("Server\nconnection\nlost");
  }

}

// this method makes a HTTP connection to the server
void httpRequest()
{
  Serial.println();

  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();


  //???????? 
  /// replace ssid at top with the Macro versions 
  //??????


  
  show_P("Connecting\n to server");

  sprintf_P(request, PSTR("GET /1_" BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d HTTP/1.1"), year, month, day, hour, minute, second, PM1, PM25, PM10);
  send_data();

  show_P("Sending second\ndata to server");
  sprintf_P(request, PSTR("GET /2_" BOX_ID "_%d_%d_%d_%c HTTP/1.1"), (int)(temperature*100.0), (int)(humidity*100.0), CO2, PIR);
  send_data();
  delay(6000);

}