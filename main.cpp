#include "F16.h"
#include "F35.h"
#include "Carrier.h"
#include <iostream>

int main (){
  Carrier carrier_1(100, 100);
  carrier_1.add_air_craft("F16");
  carrier_1.add_air_craft("F35");

  std::cout << carrier_1.get_status();

  try{
    carrier_1.fill();
  } catch(const char* status){
    std::cout << "Can't refill. The store of ammo is " << status << std::endl;
  }
  std::cout << std::endl;
  std::cout << carrier_1.get_status() << std::endl;

  Carrier carrier_2(200, 50);
  carrier_2.add_air_craft("F16");
  carrier_2.add_air_craft("F35");

  carrier_1.figth(carrier_2);

  std::cout << carrier_1.get_status() << std::endl;
  std::cout << carrier_2.get_status() << std::endl;

  return 0;
}
