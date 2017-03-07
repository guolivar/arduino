
// aggregating all the setup code to one file to ensure no overlaps are taking place

// Oh shit I just realised that we I have deleted old code so if there were lines that have been declared in multiple places that were important they may be gone

// I think most of them were serial starts though so dont worry too much just double check the file history on gitlab website / local repo commit history


void co2setup() {

   Wire.begin ();
   pinMode(13, OUTPUT); // address of the Arduino LED indicator

   //println("Application Note AN-102: Interface Arduino to K-30");
}

void DUST_setup() {
  Serial2.begin(9600);
}

void PIR_setup(){
  pinMode(MOTION_PIN, INPUT_PULLUP);
}

void setupTemp(){
  
 //Serial.begin(115200);  // start serial for output
 //Wire.begin();
 
 Serial.println("Amphenol Advanced Sensors");
 Serial.println("Arduino T9602 Monitor");

 ScanI2CBus();
}
