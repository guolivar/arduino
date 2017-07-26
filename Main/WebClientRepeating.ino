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

void WIFI_connect(){
  // attempt to connect to WiFi network

  // attept to connect to AP

  for(int i = 0; i<5; i++){
    show_P("Connecting\n to AP");
    status = WiFi.begin(ssid, pass);
    
    if(status == WL_CONNECTED){
      show_P("Connected\n to AP");
      break;
    }
    else{
        // Connect to WPA/WPA2 network
      status = WiFi.begin(ssid, pass);
    }

  }
 
}

void WIFI_setup()
{

  show_P("Configuring\nWIFI card");
  // initialize ESP module
  WiFi.init(&Serial);

  WIFI_connect();

  // put in proper retrys here
  // check for the presence of the shield

  show_P("Checking\n WIFI card");
  if (WiFi.status() == WL_NO_SHIELD) {
    show_P("WiFi card\n not present");

    // fix this to be like old code ie reboot after one send etc
  }

}


// merge this function with the http request one g

void WIFI_send()
{
 
  // if 10 seconds have passed since your last connection,
  // then connect again and send data
  if (millis() - lastConnectionTime > postingInterval) {

    httpRequest();
  }
}



// use other code for own at commands etc to see how to send real values

void send_data(){
   // if there's a successful connection
  if (client.connect(server, 80)) {
    show_P("Sending data\nto server");
    
    // may need to make seperate get requests so that it can cope

    // maybe make one route for each sensor value??

    client.println(Buffer);
    client.println(F("Host: seat-skomobo.massey.ac.nz"));
    client.println(F("Connection: close"));
    client.println();

    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection
    show_P("Server\nconnection\nlost");
    
    // WiFi.init(&Serial);
    // WIFI_connect();
  }

}

// this method makes a HTTP connection to the server
void httpRequest()
{
  // close any connection before send a new request
  // this will free the socket on the WiFi shield

  // move this to bottom for my own protocol
  client.stop();

  show_P("Connecting\n to server");

  sprintf_P(Buffer, PSTR("GET /1_" BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d HTTP/1.1"), year, month, day, hour, minute, second, PM1, PM25, PM10);
  // layout_P("GET /1_" BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d HTTP/1.1", year, month, day, hour, minute, second, PM1, PM25, PM10);
  send_data();
 
  sprintf_P(Buffer, PSTR("GET /2_" BOX_ID "_%d.%d_%d.%d_%d_%c HTTP/1.1"), (int)temperature, (int)(temperature * 100) % 100, (int)humidity, (int)(humidity * 100) % 100, CO2, PIR);
  // layout_P("GET /2_" BOX_ID "_%i_%d_%d_%c HTTP/1.1", (int)trunc(temperature*100.0f), (int)trunc(humidity*100.0f), CO2, PIR);
  send_data();
  
  delay(6000);

}