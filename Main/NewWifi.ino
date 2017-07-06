//char ssid[] = "4G UFI_8B8";           // your network SSID (name)
//char pass[] = "1234567890";        // your network password

//char ssid[] = "DESKTOP-73HN8ON 5011";           // your network SSID (name)
//char pass[] = "u65879Q0"; 

//char server[] = "192.168.100.100";
//char server[] = "seat-skomobo.massey.ac.nz";

// returns a boolean allowing it to function like a async function if it fails it returns false

bool Connected = false;

boolean send_next(const __FlashStringHelper *command){
//  Serial.println(Serial.readString());
  // make sure to only continue if OK is received after each command
  if(Serial.find("OK")){
    Serial.println(command);
    return true;
  }
  else{
    
//    Serial.println(Serial.readString());
    Connected = false;
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


// refer to this link for what each AT command does 
//https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf

// setup this macro to tidy up lines
//#define CMD( arg ) "AT+"arg

void WIFI_setup(){

  Serial.println(F("AT"));
  // Serial.println(Serial.readString());
  
  if(!Serial.find("OK")){
    try_again(F("AT"), 4);
    Serial.println(F("WIFI module not connected"));

    Connected = false;
  }
  else{

    //restart 
    Serial.println(F("AT+RST"));

    //disable echo
    send_next(F("ATE0"));
    send_next(F("AT+CWMODE=1"));
    send_next(F("AT+CIPMUX=1"));
    send_next(F("AT+CIPDINFO=1"));
    send_next(F("AT+CWAUTOCONN=0"));
    send_next(F("AT+CWDHCP=1,1"));
//    send_next(F("AT+GMR"));
//    delay(3000);
    // will send version num not ok
    //
//    Serial.println(F("AT+CIPSTATUS"));
    delay(3000);
   
    // set to 0 by default?
//    send_next(F("AT+CIPMUX=0"));
    
    // set to client mode
//    AT+CIPMUX=1
//AT+CIPDINFO=1
//AT+CWAUTOCONN=0
//AT+GMR
//AT+CIPSTATUS
  
    // default seems to be 0 but not sure use this to debug if necessary
    // send_next(F("AT+CWAUTOCONN=0"));

    // defaults to 3 for some reason
//    send_next(F("AT+CWDHCP=1,1"));
    // TODO make these login details more secure

//    send_next(F("AT+CWJAP=\"4G UFI_8B8\",\"1234567890\""));
    Serial.println(F("AT+CWJAP_CUR=\"DESKTOP-73HN8ON5011\",\"u65879Q0\""));
//    send_next(F("AT+CWJAP_CUR=\"DESKTOP-73HN8ON5011\",\"u65879Q0\""));
    delay(3000);
//    pause_print(1000);
//    inspect();
    if(Serial.find("OK")){
      Connected = true;
//      Serial.println(F("AT+CIFSR"));
//      inspect();
    }
    else{
      Serial.println(F("No AP connection"));
    }
 
    // assign to status variable to say we are ready, if not ready then try 5 times
  }
  
}

void WIFI_send(String Time, bool PIR, String Temp, int CO2, String Dust){
  
  /// first num is id of channel I dont think this is necessary cus this is a one channel only connection
  // Send AT+CIPSTART=3, "TCP", "server", servers_http_port

  // need to put check in to see if we have connection to hostpot if not retry

  if(Connected){
    Serial.println(F("AT+CIPSTART=\"TCP\", \"192.168.100.100\", 81"));
    if(Serial.find("OK")){
      // Send AT+CIPSEND=3,55 to say the serial content will have X length I think where x in the example is 55

      // may need to set to length of url
      send_next(F("AT+CIPSEND=55"));

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
      
      send_next(F("AT+CIPSEND=23"));

      send_next(F("AT+CIPCLOSE"));

    }
  }
  

  // if no connection skip rest

  // maybe should retry 5 times?? see how we go we can probs afford to miss out on server data maybe ask Alfred

}

