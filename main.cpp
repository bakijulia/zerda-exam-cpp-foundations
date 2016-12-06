#include "AirCraft.h"
#include "F16.h"
#include "F35.h"
#include <iostream>

int main (){
  F16 f16;
  F35 f35;

  f16.print_status();
  std::cout << std::endl;
  f35.print_status();

  return 0;
}
