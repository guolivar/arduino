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
    Serial.println(F( PASSWORD ));
//    send_next(F("AT+CIFSR"));

//    Serial.println(Serial.readString());
//    show(Serial.readString());
//    inspect();

//    Serial.setTimeout(10000);
//    inspect();
//    Serial.setTimeout(1000);
    Serial.setTimeout(5000);
    if(Serial.find("WIFI CONNECTED") && Serial.find("WIFI GOT IP") && Serial.find("OK")){
      ap_connected = true;

      // find cool way to show IP
      Serial.println(F("AT+CIFSR"));
      inspect();
//      show(Serial.readString());
      show(F("Connected to hotspot"));

      //screen wires seem faulty
      
    }
    else{
      show(F("No AP connection"));
      ap_connected = false;
    }

    Serial.setTimeout(1000);
 }

void wifi_config(){

  Serial.println(F("AT"));
  
  if(!Serial.find("OK")){
//    try_again(F("AT"), 4);
    show(F("WIFI card \nnot connected"));
    
    plugged_in = false;
  }
  else{

    show(F("Configuring WIFI"));
    plugged_in = true;
    //restart 
    Serial.println(F("AT+RST"));

    //disable echo

    if(Serial.find("ready")){
      Serial.println(F("ATE0"));
    }
    send_next(F("AT+CWMODE=1"));
//    send_next(F("AT+CIPMUX=1"));
    send_next(F("AT+CIPDINFO=1"));
    send_next(F("AT+CWAUTOCONN=0"));
//    send_next(F("AT+CWDHCP=1,1"));

    if(Serial.find("OK")){
      wifi_connect();
    }else{
      show(F("Setup failure"));
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

  show(F("Checking WIFI \ncard"));
  wifi_config();
  
}

void still_plugged_in(){
  Serial.println(F("AT"));
  plugged_in = Serial.find("OK");

  
//  if(Serial.find("OK")){
//    plugged_in = true;
//  }
//  else{
//    plugged_in = false;
//  }
}

void WIFI_send(String Time, bool PIR, String Temp, int CO2, String Dust){
  
  /// first num is id of channel I dont think this is necessary cus this is a one channel only connection
  // Send AT+CIPSTART=3, "TCP", "server", servers_http_port

  // check if card was unplugged during runtime

  // doenst seem to work for some reason
  still_plugged_in();

  // troubleshoot these fail safes maybe use functional programming to remove global vars to make it clearer


  // somehow doesnt cover if the module was just plugged in during runtime????
  if(plugged_in){
    if(ap_connected){
      Serial.println(F("AT+CIPSTART=\"TCP\",\"192.168.100.100\",81"));
      //try this 
  
//      show(Serial.readString());
      inspect();
  
      // need check if wifi still connected if not just reconnect also retry connection if failed
      if(Serial.find("CONNECT") && Serial.find("OK")){
  
        show(F("Sending data \nto server"));
        // Send AT+CIPSEND=3,55 to say the serial content will have X length I think where x in the example is 55
 
        // finally send the data
  
        // use wrapper like this cus is not a flash string
//        if(Serial.find("OK")){
  
        Dust.replace(",", "_");
        Temp.replace(",", "_");
        Time.replace(":", "_");
        Time.replace("/", "_");
        Time.replace(" ", "_");

        String request = "GET /" BOX_ID "_" + Time + F("_") + Dust + F("_") + Temp + F("_") + String(CO2) + F("_") + String(PIR) + F(" HTTP/1.1");
        // may need to set to length of url

        // we have to send it blind because cipsend gives no replies and only transmits x amounts of bytes
        request = request + F("\nHOST: \"192.168.100.100\"\nConnection: close");
        Serial.println("AT+CIPSEND=" + String(request.length()));
//        Serial.println(F("AT+CIPSEND"));
        Serial.println(request);

        // stop transmission
//        Serial.println(F("+++"));

//        Serial.println();
//        send_next(F("HOST: \"192.168.100.100\""));
//        send_next(F("Connection: close"));
        
//        }
        
//        send_next(F("AT+CIPSEND=100"));
 
  
      }
       Serial.println(F("AT+CIPCLOSE"));
    }else{
      wifi_connect();
    }
  }else{
    wifi_config();
  }
}

