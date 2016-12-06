#include "AirCraft.h"
#include "F16.h"
#include "F35.h"
#include <iostream>

int main (){
  F16 f16;
  F35 f35;

  std::cout << f16.get_status();
  std::cout << std::endl;
  std::cout << f35.get_status();
  std::cout << std::endl;

  f16.refill(10);
  std::cout << f16.get_status();
  std::cout << std::endl;
  f16.fight();
  std::cout << f16.get_status();

  return 0;
}
