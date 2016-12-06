
#ifndef CARRIER_H_
#define CARRIER_H_

#include <vector>
#include <string>
#include <iostream>
#include "F16.h"
#include "F35.h"

class Carrier {
private:
  std::vector<AirCraft*> air_crafts;
  int store_of_ammo;
  int health_point;
  int total_damage;
public:
  Carrier(int ammos, int health_point);
  ~Carrier();

  void add_air_craft(std::string);
  std::string get_status();
  void fill();
  void set_total_damage();
  void figth(Carrier &carrier);
  bool is_dead();
};

#endif /* CARRIER_H_ */
