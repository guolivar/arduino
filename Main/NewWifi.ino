//char ssid[] = "4G UFI_8B8";           // your network SSID (name)
//char pass[] = "1234567890";        // your network password

//char ssid[] = "DESKTOP-73HN8ON 5011";           // your network SSID (name)
//char pass[] = "u65879Q0"; 


//int status = WL_IDLE_STATUS;     // the Wifi radio's status

//char server[] = "192.168.100.100";
//char server[] = "seat-skomobo.massey.ac.nz";

// returns a boolean allowing it to function like a async function if it fails it returns false
boolean send_next(const __FlashStringHelper *command){
//  Serial.println(Serial.readString());
  // make sure to only continue if OK is received after each command
  if(Serial.find("OK")){
    Serial.println(command);
    return true;
  }
  else{
    
//    Serial.println(Serial.readString());
  
    return false;
  }
}

void try_again(const __FlashStringHelper *command, int num_retrys){
  for(int i = 0; i < num_retrys; i++){
    if(send_next(command)){
      break;
    }
  }
}



void inspect(){
  Serial.println(Serial.readString());
}

//typedef void (*Function)();

//Function cat = inspect;

void after(char* message, void (*callback)() ){

  if(Serial.find(message)){
    callback();
  }
  
} 

void pause_print(int num){
  delay(num);
  inspect();
}

// setup this macro to tidy up lines
//#define CMD( arg ) "AT+"arg
void WIFI_setup(){

  // consider setting the timeout to something smaller
  
  // see if its there using AT
  // if it says OK then continue else keep trying 5 times
    
  Serial.println(F("AT"));
//  Serial.println(Serial.readString());
  if(!Serial.find("OK")){
    try_again(F("AT"), 4);
    Serial.println(F("WIFI module not connected"));
  }
  else{

    //disable echoing because it causes the module to crash
//    Serial.println(F("ATE0"));
    
    // when ok send AT+RST to restart it
    // means that if any settings are still stored then it will start fresh
  
    // tidy this up by sending a array with all these commands in it to one function that iterates them and sends next each one
//    send_next(F("AT+RST"));
    Serial.println(F("AT+RST"));
//send_next(F("AT+RST"));
  
    // Send ATE0 to stop the esp from echoing back the commands again
    
    send_next(F("ATE0"));
     
    // Send AT+CIPMUX=1 to set multiple connections to enable multiple connections for server mode
    // set to 0 by default
//    send_next(F("AT+CIPMUX=0"));

    // set to client mode
    send_next(F("AT+CWMODE_CUR=1"));
  
    // Send AT+CWAUTOCONN=0 to prevent autoconnecting? apparently it causes issues
    // default seems to be 0 but not sure use this to debug if necessary
//    send_next(F("AT+CWAUTOCONN=0"));
//    send_next(F("AT+CWAUTOCONN?"));
    
    // Send AT+CWHDCP=1,1 to enable DHCP for dynamic IP addresses from the hotspot

    // defaults to 3 dont know if this refers to channel 3 or something else weird
    send_next(F("AT+CWDHCP_CUR=1,1"));
//    pause_print(1000);
//    pause_print(2000);
    // Send AT+GMR to get version number
//    send_next(F("AT+GMR")); 
    
    // Send AT+CWJAP_CUR="ssid""password" to connect to the wifi
    // TODO make these login details more secure

    send_next(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"1234567890\""));

    pause_print(1000);
//    after("OK", inspect);
//    if(Serial.find("ERROR")){
      
//    }
    //crashes here remove _Cur
//    Serial.println(Serial.readString());

    //get local IP address
    send_next(F("AT+CIFSR"));

    Serial.println(Serial.readString());
  
    // Send AT+CIPSTATUS to see the ip address etc -- we shouldnt need this but for testing could be useful
//    
  
    // assign to status variable to say we are ready, if not ready then try 5 times
  }
  
}

void WIFI_send(String Time, bool PIR, String Temp, int CO2, String Dust){
  
  /// first num is id of channel I dont think this is necessary cus this is a one channel only connection
  // Send AT+CIPSTART=3, "TCP", "server", servers_http_port

  // need to put check in to see if we have connection to hostpot if not retry
  Serial.println(F("AT+CIPSTART=\"TCP\", \"192.168.100.100\", 81"));

  // if no connection skip rest

  // maybe should retry 5 times?? see how we go we can probs afford to miss out on server data maybe ask Alfred

  if(Serial.find("OK")){
      // Send AT+CIPSEND=3,55 to say the serial content will have X length I think where x in the example is 55

      // may need to set to length of url
      send_next(F("AT+CIPSEND=55"));
    
      // Send GET /"path" HTTP:1/1 to prep request

      // finally send the data

      // use wrapper like this cus is not a flash string
      if(Serial.find("OK")){

        Dust.replace(",", "_");
        Temp.replace(",", "_");
        Time.replace(":", "_");
        Time.replace("/", "_");
        Time.replace(" ", "_");
        Serial.println("GET /" BOX_ID "_" + Time + F("_") + Dust + F("_") + Temp + F("_") + String(CO2) + F("_") + String(PIR) + F(" HTTP/1.1"));
        send_next(F("HOST: \"192.168.100.100\""));
        send_next(F("Connection: close"));
      }
      
      // Send AT+CIPSEND=3,23 last number is the length of the data so length of path??
      send_next(F("AT+CIPSEND=23"));
      
    
      // Send AT+CIPCLOSE=3 to end the tcp connection

      send_next(F("AT+CIPCLOSE"));

    
      // if we encounter ERROR we should probably cancel what we are doing somehow
    
      // may need to create my own find function to get the above working so maybe leave out for now
  }

}

