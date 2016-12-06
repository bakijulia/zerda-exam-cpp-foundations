#include "F16.h"
#include "F35.h"
#include "Carrier.h"
#include <iostream>

int main (){
  Carrier carrier_1(100);
  carrier_1.add_air_craft("F16");

  std::cout << carrier_1.get_status();

  return 0;
}
