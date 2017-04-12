
#include <SoftwareSerial.h>
SoftwareSerial dustport(8,9);

void DUST_setup() {
  //mega
  //Serial2.begin(9600);
  dustport.begin(9600);
  
}


void show(String environment, String particle_size){
  Serial.print(environment + ", PM " + particle_size + " = ");
  Serial.print(calc_pm());
  Serial.println(" ug/m3");
}

unsigned char c;
  
long calc_pm(){ 
  return 256 *( 2 * c);
}


long pm1;

//pm 2.5
long pm25;

//pm 10
long pm10;

// look into difference between atmosphere and the cm values

String DUST_loop() {

  int count = 0;

  //mega
//  while (Serial2.available()) {
//    
//    c = Serial2.read();

 while (dustport.available()) {
    c = dustport.read();
    if((count==0 && c!=0x42) || (count==1 && c!=0x4d)){
      Serial.println("check failed");
      break;
    }

    if(count == 5){
      show("CF = 1", "1");
    }
    else if(count == 7){
      show("CF = 1", "2.5");
    }
    else if(count == 9){
      show("CF = 1", "10");
    }
    else if(count == 11){
      show("atmosphere", "1.0");
      pm1 = calc_pm();
    }
    else if(count == 13){
      show("atmosphere", "2.5");
      pm25 = calc_pm();
    }
    else if(count == 15){
      show("atmosphere", "10");
      pm10 = calc_pm();

      display_heading();
          
      display.print("PM: ");

      display.print(calc_pm());
      display.setTextSize(1);
      display.println("ug/m3");
      display.println(" ");
      display.println(" 10");
      display.display();
    }
    if(count > 15){
      Serial.println("complete");
      return String(pm1) + " " + String(pm25) +  " " + String(pm10);
    }

    count++;
  }
  //mega
  //while(Serial2.available()) Serial2.read();
  while(dustport.available()) dustport.read();
  Serial.println();
  delay(2000);
}


