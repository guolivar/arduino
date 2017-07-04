//char ssid[] = "4G UFI_8B8";           // your network SSID (name)
//char pass[] = "1234567890";        // your network password

//char ssid[] = "DESKTOP-73HN8ON 5011";           // your network SSID (name)
//char pass[] = "u65879Q0"; 


//int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "192.168.100.100";
//char server[] = "seat-skomobo.massey.ac.nz";

// returns a boolean allowing it to function like a async function if it fails it returns false
boolean send_next(const __FlashStringHelper *command){
  
  // make sure to only continue if OK is received after each command
  if(Serial.find("OK")){
    Serial.println(command);
    return true;
  }
  else{
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

// setup this macro to tidy up lines
//#define CMD( arg ) "AT+"arg
void WIFI_setup(){

  // consider setting the timeout to something smaller
  
  // see if its there using AT
  // if it says OK then continue else keep trying 5 times
    
  Serial.println(F("AT"));
  try_again(F("AT"), 4);

  // when ok send AT+RST to restart it
  // means that if any settings are still stored then it will start fresh

  // tidy this up by sending a array with all these commands in it to one function that iterates them and sends next each one
  send_next(F("AT+RST"));

  // Send ATE0 to stop the esp from echoing back the commands again
  
  send_next(F("AT+E0"));
   
  // Send AT+CIPMUX=1 to set multiple connections to 1
  send_next(F("AT+CIPMUX=1"));

  // Send AT+CWAUTOCONN=0 to prevent autoconnecting? apparently it causes issues
  send_next(F("AT+CWAUTOCONN=0"));

  // Send AT+CWHDCP=1,1 to enable DHCP for dynamic IP addresses from the hotspot
  send_next(F("AT+CWHDCP=0"));

  // Send AT+GMR to put in wireless client mode
  send_next(F("AT+GMR")); 
  
  // Send AT+CWJAP_CUR="ssid""password" to connect to the wifi
  // TODO make these login details more secure
  send_next(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"1234567890\""));

  // Send AT+CIPSTATUS to see the ip address etc -- we shouldnt need this but for testing could be useful
  send_next(F("AT+CIPSTATUS"));
  

  /// first num is id of channel I dont think this is necessary cus this is a one channel only connection
  // Send AT+CIPSTART=3, "TCP", "server", servers_http_port

  // Send AT+CIPSEND=3,55 to say the serial content will have X length I think where x in the example is 55

  // to wait for ok just use if(Serial.find("OK")){}

  // Send GET /"path" HTTP:1/1 to prep request

  // Send AT+CIPSEND=3,23 last number is the length of the data so length of path??

  // Send AT+CIPCLOSE=3 to end the tcp connection

  // if we encounter ERROR we should probably cancel what we are doing somehow

  // may need to create my own find function to get the above working so maybe leave out for now
}

void WIFI_send(){
  
}

