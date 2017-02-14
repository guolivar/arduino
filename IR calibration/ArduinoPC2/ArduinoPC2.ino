

//void setup() {
  //Serial.begin(9600);
  //Serial.println(analogRead(0));
  //Serial.println("<Arduino is ready>");
//}

//const byte buffSize = 40;
//char messageFromPC[buffSize] = {0};
//boolean newDataFromPC = false;

//void replyToPC() {

  //if (newDataFromPC) {
    //newDataFromPC = false;
    //Serial.print("<Msg ");
    //Serial.print(messageFromPC);
    //Serial.println(">");
  //}
//}

//void receivedCommand() {
  
  //if (strcmp(messageFromPC, "RECORD") == 0) {
    // Record();
  //}
//}

// we need to send back the raw data that we sense on the arduino and process it in python
//void Record() {
  //Serial.print("adc: " + analogRead(0));
//}



/// new code :) 

// send the letter R to the arduino to record saves us the trouble of having to use buffers

// arduino then sends back its raw adc value for the sensor

// we then process the adc convert it to volts and use it to measure the distance

//void loop() { 
  //getDataFromPC();
  //receivedCommand();
  //replyToPC();
//}

//byte bytesRecvd = 0;
//boolean read_now = false;

//void isStart( char letter ){
    //if (letter == '<') { 
      //bytesRecvd = 0; 
      //read_now = true;
    //}
//}

//char inputBuffer[buffSize];
//void getDataFromPC() {

    // receive data from PC and save it into inputBuffer
    
  //if(Serial.available() > 0) {

   // char letter = Serial.read();

      // the order of these IF clauses is significant

    //isStart(letter);
    
    //if(read_now) {
     // inputBuffer[bytesRecvd] = letter;
     // bytesRecvd ++;
     // if (bytesRecvd == buffSize) {
     //  bytesRecvd = buffSize - 1;
     // }
    //}

   // isEnd(letter);
 
  //}
//}


void isEnd( char letter ){
    if (letter == '>') {
      read_now = false;
      newDataFromPC = true;
      inputBuffer[bytesRecvd] = 0;
      parseData();
    }
}

void parseData() {

    // split the data into its parts
    
  char * strtokIndx; // this is used by strtok() as an index
  
  strtokIndx = strtok(inputBuffer,",");      // get the first part - the string
  strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
  
  //strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  //int newFlashInterval = atoi(strtokIndx);     // convert this part to an integer
  
  //strtokIndx = strtok(NULL, ","); 
  //float fraction = atof(strtokIndx);     // convert this part to a float

}


