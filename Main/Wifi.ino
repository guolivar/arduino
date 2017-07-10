//char ssid[] = "4G UFI_8B8";           // your network SSID (name)
//char pass[] = "1234567890";        // your network password

//char server[] = "192.168.100.100";
//char server[] = "seat-skomobo.massey.ac.nz";

// returns a boolean allowing it to function like a async function if it fails it returns false


// display relies on ascii text library


bool plugged_in = false;
bool ap_connected = false;

boolean send_next(const __FlashStringHelper *command){

  // make sure to only continue if OK is received after each command
  if(Serial.find("OK")){
    Serial.println(command);
    return true;
  }
  else{
    
//    Serial.println(Serial.readString());
    plugged_in = false;
    return false;
  }
}

// FIx this so that it actually retrys
//void try_again(const __FlashStringHelper *command, int num_retrys){
//  for(int i = 0; i < num_retrys; i++){
//    if(send_next(command)){
//      break;
//    }
//  }
//}

void wifi_connect(){
  
    // waiy for linked on tcp
   
    // TODO make these login details more secure

    //DESKTOP-73HN8ON5011 u65879Q0 for laptop
    // for dongle 4G UFI_8B8 123456790
    Serial.println(F("AT+CWJAP_CUR=\"4G UFI_8B8\",\"123456790\""));

    delay(6000);

//    send_next(F("AT+CIFSR"));
    

    if(Serial.find("OK")){
      ap_connected = true;
      show(Serial.readString());
      show(F("Connected to hotspot"));

      //screen wires seem faulty
      
    }
    else{
      show(F("No AP connection"));
      ap_connected = false;
    }
 }

void wifi_config(){

  Serial.println(F("AT"));
  
  if(!Serial.find("OK")){
//    try_again(F("AT"), 4);
    show(F("WIFI module \n not connected"));
    
    plugged_in = false;
  }
  else{
    plugged_in = true;
    //restart 
    Serial.println(F("AT+RST"));

    //disable echo
    send_next(F("ATE0"));
    send_next(F("AT+CWMODE=1"));
    send_next(F("AT+CIPMUX=1"));
    send_next(F("AT+CIPDINFO=1"));
    send_next(F("AT+CWAUTOCONN=0"));
    send_next(F("AT+CWDHCP=1,1"));
    
    delay(3000);

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

  show(F("Checking WIFI \n module"));
  wifi_config();
  
}

void WIFI_send(String Time, bool PIR, String Temp, int CO2, String Dust){
  
  /// first num is id of channel I dont think this is necessary cus this is a one channel only connection
  // Send AT+CIPSTART=3, "TCP", "server", servers_http_port

  // need to put check in to see if we have connection to hostpot if not retry

  if(plugged_in){
    if(ap_connected){
      Serial.println(F("AT+CIPSTART=3,\"TCP\",\"192.168.100.100\",81"));

      delay(10000);
      //try this 
  
      show(Serial.readString());
  //    inspect();
  
      // need check if wifi still connected if not just reconnect also retry connection if failed
      if(Serial.find("OK")){
  
        show(F("Sending data to server"));
        // Send AT+CIPSEND=3,55 to say the serial content will have X length I think where x in the example is 55
  
        // may need to set to length of url
        Serial.println(F("AT+CIPSEND=3,55"));
  
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
        
        send_next(F("AT+CIPSEND=3,100"));
  
        send_next(F("AT+CIPCLOSE=3"));
  
      }
    }else{
      wifi_connect();
    }
  }else{
    wifi_config();
  }
}

