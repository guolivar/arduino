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

char request[51] = "\0";

void send_data(){
   // if there's a successful connection
  if (client.connect(server, 80)) {
    show_P("Sending data\nto server");
    
    // may need to make seperate get requests so that it can cope

    // maybe make one route for each sensor value??

    // after that put in the script to start the server on boot using this https://www.computerhope.com/issues/ch000322.htm

   
    // sprintf_P(request, PSTR("GET /1_" BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d HTTP/1.1"), year, month, day, hout, minute, second, PM1, PM25, PM10);

    client.println(request);

    // client.println(F("Host: seat-skomobo.massey.ac.nz "));
    // client.println(F("Connection: close"));
    // client.println();

    // sprintf_P(request, PSTR(BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d"), year, month, day, hour, minute, second, PM1, PM25, PM10)

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

  // move this to bottom for my own protocol
  client.stop();


  //???????? 
  /// replace ssid at top with the Macro versions 
  //??????


  
  show_P("Connecting\n to server");

  // 51
  
  // sprintf_P(request, PSTR("GET /1_" BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d HTTP/1.1"), year, month, day, hour, minute, second, PM1, PM25, PM10);
  // sprintf_P(request, PSTR(BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d_%d_%d_%d_%c"), year, month, day, hour, minute, second, PM1, PM25, PM10, (int)(temperature*100.0), (int)(humidity*100.0), CO2, PIR);
  
  //! still need two seperate requests to transmit data server needs to handle too
  sprintf_P(request, PSTR(BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d"), year, month, day, hour, minute, second, PM1, PM25, PM10);
  send_data();

  // show_P("Sending second\ndata to server");
  // sprintf_P(request, PSTR("GET /2_" BOX_ID "_%d_%d_%d_%c HTTP/1.1"), (int)(temperature*100.0), (int)(humidity*100.0), CO2, PIR);
  // send_data();

  // consider JSON encoding here but length issue will still persist I think

  // char content[14] = "\0";
  // sprintf_P(content, PSTR("{id:" BOX_ID ",PIR:%c, }"))
  // client.println(F("POST /arduino"));

  // would either need to use chunked encoding where each chunk gives a length like this
  // char length[4] = "\0";
  // client.println("")
  // or would need to append all values in string or somehow calculate all lengths of values
  // without storing them in memory

  // also the above would have to be SRAM because it is purely dynamic not static

  // client.println(F())
  // need content length buffer here
  // client.println(F(Content_length = ))

  // 

  // would just be easier with my scheme

  // my scheme

  // client.println("arduino");
  // sprintf_P(request, "BOX ID Time Date dusts pir etc ");
  // client.println(request);
  // server closes connection
  // rinse repeat

  // could even do basic encryption before
  delay(6000);

}