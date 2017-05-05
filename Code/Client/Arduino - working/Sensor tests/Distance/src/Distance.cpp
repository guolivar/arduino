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



void loop() {

  unsigned int repetitions = 50;

  int collection[repetitions];

  for (size_t i = 0; i < repetitions; i++) {
    collection[i] = analogRead(2);
  }

  Serial.println( avg( collection, repetitions ) );
}
