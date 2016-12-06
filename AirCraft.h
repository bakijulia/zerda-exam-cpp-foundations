#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include <string>

class AirCraft {
public:
  int max_ammo;
  int base_damage;
  int actual_ammo;
  std::string type;
  AirCraft();
  virtual ~AirCraft();
  int get_max_ammo();
  int get_base_damage();
  int get_actual_ammo();
  std::string get_type();
  void print_status();
};

#endif /* AIRCRAFT_H_ */
