#include "F16.h"
#include "F35.h"
#include "Carrier.h"
#include <iostream>

int main (){
  Carrier carrier_1(0);
  carrier_1.add_air_craft("F16");

  std::cout << carrier_1.get_status();

  try{
    carrier_1.fill();
  } catch(const char* status){
    std::cout << "Can't refill. The store of ammo is " << status;
  }

  return 0;
}
