
#include <Wire.h>

void wire_write(int * nums){
  
//  for(int i = 0; i < sizeof(nums); ++i){
//    Wire.write(nums[i]);
//  }

  fun_map(Wire.write, nums);
  
}

