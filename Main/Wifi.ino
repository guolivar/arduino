/////*
//// WiFiEsp example: WebClientRepeating
////
//// This sketch connects to a web server and makes an HTTP request
//// using an Arduino ESP8266 module.
//// It repeats the HTTP call each 10 seconds.
////
//// For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
////*/
////
////#include "src/WiFiEsp.h"
//
////char ssid[] = "4G UFI_8B8";           // your network SSID (name)
////char pass[] = "1234567890";        // your network password
//
//////char ssid[] = "DESKTOP-73HN8ON 5011";           // your network SSID (name)
//////char pass[] = "u65879Q0"; 
////
////
////
////
////int status = WL_IDLE_STATUS;     // the Wifi radio's status
////
////char server[] = "192.168.100.100";
//////char server[] = "seat-skomobo.massey.ac.nz";
////
////// sd card not present causes wifi connection to fail
////
////
////
//////unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
//////const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds
////
////// Initialize the Ethernet client object
////WiFiEspClient client;
////
////void Wifi_setup()
////{
////////  Serial2.begin(115200);
//////
//////  // initialize ESP module
////////  WiFi.init(&Serial2);
////  WiFi.init(&Serial);
//////
//////  // check for the presence of the shield
//////  if (WiFi.status() == WL_NO_SHIELD) {
//////
//////      // do nothing for now eventually print error to display screen
//////      
//////    
////////    Serial.println("WiFi shield not present");
//////    
//////    //change this so that it doesnt waste time doing other wifi setup stuff but does carry on to use sd card etc
//////
//////    // actually a hardware reset button to restart this code with a interrupt would be good, wire it in to pin 3???
//////     
//////    // don't continue
////////    while (true);
////// 
//////    // if we cut out gfx then we may be able to use display
//////
//////      
//////  }
////
////  // make sure that if any of these steps fail the system continues
////
////  // attempt to connect to WiFi network
//////  while ( status != WL_CONNECTED) {
////////    Serial.print("Attempting to connect to WPA SSID: ");
////////    Serial.println(ssid);
//////    // Connect to WPA/WPA2 network
//////    status = WiFi.begin(ssid, pass);
////////  }
//////  
//////  for (int i = 0; i< 5; i= i + 1) {
//////    if(status != WL_CONNECTED){
//////       status = WiFi.begin(ssid, pass);
//////    }
//////    else{
//////      break;
//////    }
//////  }
////
////  
////
////
////  
//////  Serial.println("You're connected to the network");
////  
//////  printWifiStatus();
//////}
//////
//////void loop()
//////{
//////  // if there's incoming data from the net connection send it out the serial port
//////  // this is for debugging purposes only
////////  while (client.available()) {
////////    char c = client.read();
////////    Serial.write(c);
////////  }
//////
//////  // if 10 seconds have passed since your last connection,
//////  // then connect again and send data
////////  if (millis() - lastConnectionTime > postingInterval) {
////////    httpRequest();
////////  }
//////}
////
////// this method makes a HTTP connection to the server
////void Wifi_send(String Time, bool PIR, String Temp, int CO2, String Dust)
////{
////  ////Serial.println();
////    
////  // close any connection before send a new request
////  // this will free the socket on the WiFi shield
////
////
////
////   // if status is not connected to hotspot then try and connect again in each loop
////   // only attempt server connection if hotspot connection successful
////   // only attempt get request if server connection successful 
////   
////
////
////  delay(10000);
//////  Serial.println("Sending data");
//////  client.stop(); 
////  
////  // invert this for cleanliness
////
////  // if no connection then try again
////  
////  if(status != WL_CONNECTED){
////    status = WiFi.begin(ssid, pass);
////  }
////  else{
////     // if there's a successful connection
////    if (client.connect(server, 81)) {
////  
////  //    Serial.println("Connecting...");
////  
////      // upgrade to SSL later should just be change from client.connect to client.connectSSL(ip etc)
////      
////      // send the HTTP PUT request
////  
////      //replace this with json
////  //    Serial.println(Time[5]);
////  //    client.println("GET /" BOX_ID "_" + Time[5] + "_" + Time[4] + "_" + Time[3] + "_" + Time[0] + "_" + Time[1] + "_" + Time[2] + "_" + Dust[0] + "_" + Dust[1] + "_" + Dust[2] + "_" + Temp[0] + "_" + Temp[1] + "_" + CO2 + "_" + PIR + " HTTP/1.1 ");
////  
////      // this will print the exact same line as client.println but it avoids the nasty issue where
////      // the library appends shit unnesearrily due to this being a normal sring rather than a flash string
////  
////  //    Serial.println("GET /" BOX_ID "_" + Time + F("_") + Dust.replace(",", "_") + F("_") + Temp.replace(",", "_") + F("_") + CO2 + F("_") + PIR + F(" HTTP/1.1"));
////      
////      // look at the other message it sends first and also send that message think it is AT+CIPSEND ..... followed by AT+CIPCLOSE maybe
////      
//////      Dust.replace(",", "_");
//////      Temp.replace(",", "_");
//////      Time.replace(":", "_");
//////      Time.replace("/", "_");
//////      Time.replace(" ", "_");
////
////
////      // can the fucking wifi esp library and do it myself
////
////      
////      // use normal serial because the library stuffs it up
//////      Serial.println("GET /" BOX_ID "_" + Time + F("_") + Dust + F("_") + Temp + F("_") + String(CO2) + F("_") + String(PIR) + F(" HTTP/1.1"));
//////      Serial.println(F("AT+CIPSEND=3,50"));
//////      Serial.println(F("AT+CIPCLOSE=3"));
//////      Serial.println("AT+CIPSEND 
////     
//////      client.println(F("GET /0_2016_6_23_12332_12_31_23434_12_2434_1 HTTP:1/1"));
////  //    client.println(F("Host: 192.168.100.100"));
////      
////      // change lib so that we can use .print properly so we can dynamically change the server etc
////  //    client.println(F("Host: seat-skomobo.massey.ac.nz"));
//////      client.println(F("Host: 192.168.100.100"));
//////  
//////      client.println(F("Connection: close"));
//////      client.println();
////  
////  //    Serial.println("Data sent");
////  
////    // if there's incoming data from the net connection send it out the serial port
////    // this is for debugging purposes only
////  //    while (client.available()) {
////  //      char c = client.read();
////  //      Serial.write(c);
////  //    }
////  
////  
////      // note the time that the connection was made
////  //    lastConnectionTime = millis();
////    }
////  //  else {
////      // if you couldn't make a connection
////  //    Serial.println("Connection failed");
////  //  }
////  }
////}
////
////
//////void printWifiStatus()
//////{
//////  // print the SSID of the network you're attached to
//////  Serial.print("SSID: ");
//////  Serial.println(WiFi.SSID());
//////
//////  // print your WiFi shield's IP address
//////  IPAddress ip = WiFi.localIP();
//////  Serial.print("IP Address: ");
//////  Serial.println(ip);
//////
//////  // print the received signal strength
//////  long rssi = WiFi.RSSI();
//////  Serial.print("Signal strength (RSSI):");
//////  Serial.print(rssi);
//////  Serial.println(" dBm");
//////}
//////

