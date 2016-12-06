
#ifndef CARRIER_H_
#define CARRIER_H_

#include <vector>
#include <string>
#include <iostream>
#include "AirCraft.h"
#include "F16.h"
#include "F35.h"

class Carrier {
private:
  std::vector<AirCraft*> air_crafts;
  int store_of_ammo;
  int health_point;
public:
  Carrier(int ammos);
  ~Carrier();

  void add_air_craft(std::string);
  std::string get_status();
};

#endif /* CARRIER_H_ */
