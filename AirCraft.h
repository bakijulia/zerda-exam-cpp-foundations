#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include <string>

class AirCraft {
public:
  int max_ammo;
  int base_damage;
  int actual_ammo;
  int all_damage;
  int needed_ammo;
  std::string type;

  AirCraft();
  virtual ~AirCraft();

  int get_max_ammo();
  int get_base_damage();
  int get_actual_ammo();

  std::string get_type();
  std::string get_status();

  int fight();
  void refill(int &number);
};

#endif /* AIRCRAFT_H_ */
