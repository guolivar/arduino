////char server[] = "192.168.100.100";
////char server[] = "seat-skomobo.massey.ac.nz";
//
//// returns a boolean allowing it to function like a async function if it fails it returns false
//
//
//// display relies on ascii text library
//
//
//bool plugged_in = false;
//bool ap_connected = false;
//
//boolean send_next(const __FlashStringHelper *command){
//
//  // make sure to only continue if OK is received after each command
//  if(Serial.find("OK")){
//    Serial.println(command);
//    return true;
//  }
//  else{
//    plugged_in = false;
//    return false;
//  }
//}
//
//// FIx this so that it actually retrys
////void try_again(const __FlashStringHelper *command, int num_retrys){
////  for(int i = 0; i < num_retrys; i++){
////    if(send_next(command)){
////      break;
////    }
////  }
////}
//
//void wifi_connect(){
//    show(F("Connecting \nto hotspot"));
//    
////    Serial.println(F( PASSWORD ));
//    Serial.println(F("AT+CWJAP_CUR=\"DESKTOP-73HN8ON5011\",\"u65879Q0\""));
//    
//    Serial.setTimeout(5000);
//    if(Serial.find("WIFI CONNECTED") && Serial.find("WIFI GOT IP") && Serial.find("OK")){
//      ap_connected = true;
//      
//      Serial.setTimeout(1000);
//      // find cool way to show IP
//      Serial.println(F("AT+CIFSR"));
//      inspect();
//      show(F("Connected to hotspot"));
//    }
//    else{
//      
//      Serial.setTimeout(1000);
//      show(F("No AP connection"));
//      ap_connected = false;
//    }
// }
//
//void wifi_config(){
//
//  Serial.println(F("AT"));
//  
//  if(!Serial.find("OK")){
////    try_again(F("AT"), 4);
//    show(F("WIFI card \nnot connected"));
//    
//    plugged_in = false;
//  }
//  else{
//
//    show(F("Configuring WIFI"));
//    plugged_in = true;
//    //restart 
//    Serial.println(F("AT+RST"));
//
//    //disable echo
//
//    if(Serial.find("ready")){
//      Serial.println(F("ATE0"));
//    }
//    send_next(F("AT+CWMODE=1"));
//    send_next(F("AT+CIPMUX=1"));
//    send_next(F("AT+CIPDINFO=1"));
//    send_next(F("AT+CWAUTOCONN=0"));
////    send_next(F("AT+CWDHCP=1,1"));
//
//    if(Serial.find("OK")){
//      wifi_connect();
//    }else{
//      show(F("Setup failure"));
//    }
//  }
//} 
//
//void inspect(){
//  Serial.println(Serial.readString());
//}
//
////typedef void (*Function)();
//
////Function cat = inspect;
//
//void after(char* message, void (*callback)() ){
//
//  if(Serial.find(message)){
//    callback();
//  }
//  
//} 
//
//void pause_print(int num){
//  delay(num);
//  inspect();
//}
//
//
//// refer to this link for what each AT command does 
////https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf
//
//// setup this macro to tidy up lines
////#define CMD( arg ) "AT+"arg
//
//
//
//// check if still connected to hotspot if not reconnect
//
//
//void WIFI_setup(){
//
//  show(F("Checking WIFI \ncard"));
//  wifi_config();
//
//
//    // fix this retry 
////  delay(1000);
////  wifi_connect();
//  
//}
//
//void still_plugged_in(){
//  Serial.println(F("AT"));
//  plugged_in = Serial.find("OK");
//}
//
//void WIFI_send(String Time, bool PIR, String Temp, int CO2, String Dust){
//  
//  /// first num is id of channel I dont think this is necessary cus this is a one channel only connection
//  // Send AT+CIPSTART=3, "TCP", "server", servers_http_port
//
//  // check if card was unplugged during runtime
//
//  // doenst seem to work for some reason
//  still_plugged_in();
//
//  // troubleshoot these fail safes maybe use functional programming to remove global vars to make it clearer
//
//
//  // somehow doesnt cover if the module was just plugged in during runtime????
//  if(plugged_in){
//    if(ap_connected){
//      show(F("Connecting \nto server IP"));
////      Serial.println(F("AT+CIPSTART=\"TCP\",\"192.168.100.100\",81"));
////      Serial.println(F("AT+CIPSTART=\"TCP\",\"arduino.cc\",80"));
//      Serial.println(F("AT+CIPSTART=3,\"TCP\",\"seat-skomobo.massey.ac.nz\",80")); 
//      //try this 
//  
////      show(Serial.readString());
////      inspect();
//  
//      // need check if wifi still connected if not just reconnect also retry connection if failed
//      if(Serial.find("CONNECT") && Serial.find("OK")){
//  
//        show(F("Sending data \nto server"));
//
//        // Send AT+CIPSEND=3,55 to say the serial content will have X length I think where x in the example is 55
// 
//        // finally send the data
//  
//        // may need to set to length of url
////        show(String(request.length()));
//
////        String meta = " HTTP/1.1\nHOST: \"192.168.100.100\"\nConnection: close";
//
//
//        // set the length to 51 + request length
//
//        
//        // we have to send it blind because cipsend gives no replies and only transmits x amounts of bytes
////        request = request + F("");
//
//
//        /// straight through connection to send get request and debug it 
//
//        // probably trying to send get request which is taking a while to process and AT command is still being sent
//
//        // to go to unvarnished transmission mode enter AT+CIPMODE=1 first 
//
//        // please note to end connection you need to send "+++" with quotations and no new line or return characters 
//        // then send your AT+CIPCLOSE command to close the connection 
//
//        // 51 is meta length
//        
////        if(Serial.find(">")){
//
//          
//        Dust.replace(",", "_");
//
//        // replace fullstops in CO2 and temp and humidity
//        Temp.replace(",", "_");
//        
//        Time.replace(":", "_");
//        Time.replace("/", "_");
//        Time.replace(" ", "_");
//
////        show(String(meta.length()));
////        String request = "GET /" BOX_ID "_" + Time + "_" + Dust + "_" + Temp + "_" + String(CO2) + "_" + String(PIR);
//        String request = "GET /";
//        Serial.println("AT+CIPSEND=3," + String(51 + request.length()));
//        Serial.print(request);
//        Serial.println(F(" HTTP/1.1"));
////        Serial.println(F("HOST:192.168.100.100"));
//       Serial.println(F("HOST: seat-skomobo.massey.ac.nz"));
//       Serial.println(F("Connection: close"));
////        Serial.println(F("AT+CIPSEND=29"));
////        delay(1000);
//////        Serial.println(F("GET /asciilogo.txt HTTP/1.1"));
////        delay(1000);
////        Serial.println(F("AT+CIPSEND=21"));
//////        Serial.println(F("AT+CIPSEND=18"));
////        delay(1000);
////        Serial.println(F("HOST: 192.168.100.100"));
//////        Serial.println(F("Host: arduino.cc"));
////        delay(1000);
////        Serial.println(F("AT+CIPSEND=17"));
////        delay(1000);
////        Serial.println(F("Connection: close"));
////
////        Serial.setTimeout(10000);
////        Serial.println(Serial.readStringUntil("CLOSED"));
////        Serial.setTimeout(1000);
//        
////        }
////        else{
////          show(F("Failed to send data"));
////          Serial.println(F("AT+CIPCLOSE"));
////        }
//
//        delay(5000);
//  
//      }else{
//        show(F("Failed to \nconnect to server"));
//      }
//
//    }else{
//      wifi_connect();
//    }
//  }else{
//    wifi_config();
//  }
//}

