#include "Arduino.h"


void setup(){
    Serial.begin(9600);
}


int sum(int * nums, size_t size){

  int result = 0;
  for (size_t i = 0; i < size; i++) {
    result += nums[i];
  }

  return result;
}


int avg(int * nums, size_t repetitions){
  return sum(nums, repetitions) / repetitions;
}

// try this to see if it works properly as a map functuib
// template<typename CONT, typename FUNC>
// auto map(CONT const& in, FUNC f) -> mapresult<CONT, FUNC>
// {
//     return mapresult<CONT, FUNC>(in, f);
// }

int * collect_distances(unsigned int pin, size_t ammount){

  int collection[ammount];
  
  for (size_t i = 0; i < ammount; i++) {
    collection[i] = analogRead(pin);
  }

  return collection;
}

float to_percent(int num){
  Serial.println(num);
  float percent = num / float(500);
  Serial.println(percent);
  if (percent > 1){
    return 1;
  }

  return percent;
}

String format_percent(float percent){

  //multiply by 100 then rount to the nearest integer
  int percent_num = round(percent * 100);
  Serial.println(percent_num);
  return String(percent_num) + "%";
}

void loop() {

  unsigned int repetitions = 50;
  
  Serial.println( format_percent( to_percent( avg( collect_distances(2, repetitions), repetitions ) )));
  delay(1000);
}
