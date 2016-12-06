#include "Carrier.h"

Carrier::Carrier(int ammos) {
  this->store_of_ammo = ammos;
  this->health_point = 0;
}

Carrier::~Carrier() {
  for (unsigned int i = 0; i < air_crafts.size(); i++) {
    delete air_crafts[i];
  }
}

void Carrier::add_air_craft(std::string type) {
  if (type.compare("F16")) {
    F16* f16 = new F16;
    air_crafts.push_back(f16);
  } else if (type.compare("F35")) {
    F35* f35 = new F35;
    air_crafts.push_back(f35);
  } else {
    std::cout << "Don't have this type of aircraft.";
  }
}

std::string Carrier::get_status() {
  std::string status;
  status = "Aircraft count: " + std::to_string(air_crafts.size())
      + " Ammo Storage: " + std::to_string(store_of_ammo) + " Total damage: "
      + '\n' + "Aircrafts:" + '\n';
  for (unsigned int i = 0; i < air_crafts.size(); i++) {
    status += air_crafts[i]->get_status() + '\n';
  }
  return status;
}

void Carrier::fill() {
  if (store_of_ammo > 0) {
    int full_needed_ammo;
    for (unsigned int i = 0; i < air_crafts.size(); i++) {
      full_needed_ammo += air_crafts[i]->needed_ammo;
    }
    if (full_needed_ammo <= store_of_ammo) {
      for (unsigned int i = 0; i < air_crafts.size(); i++) {
        air_crafts[i]->refill(store_of_ammo);
      }
    } else if (full_needed_ammo > store_of_ammo) {
      for (unsigned int i = 0; i < air_crafts.size(); i++) {
        if (air_crafts[i]->type == "F35") {
          air_crafts[i]->refill(store_of_ammo);
        }
      }
    }
  } else {
    throw "empty";
  }
}
