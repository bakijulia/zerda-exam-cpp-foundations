#include "Carrier.h"

Carrier::Carrier(int ammos, int health_point) {
  this->store_of_ammo = ammos;
  this->health_point = health_point;
  this->total_damage = 0;
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
    set_total_damage();
  } else if (type.compare("F35")) {
    F35* f35 = new F35;
    air_crafts.push_back(f35);
    set_total_damage();
  } else {
    std::cout << "Don't have this type of aircraft.";
  }
}

void Carrier::set_total_damage() {
  for (unsigned int i = 0; i < air_crafts.size(); i++) {
    total_damage += air_crafts[i]->all_damage;
  }
}

std::string Carrier::get_status() {
  std::string status;
  if(is_dead()){
    status += "It's dead Jim :(";
  }
  status = "Aircraft count: " + std::to_string(air_crafts.size())
      + " Ammo Storage: " + std::to_string(store_of_ammo) + " Total damage: "
      + std::to_string(total_damage) + '\n' + "Aircrafts:" + '\n';
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
        set_total_damage();
      }
    } else if (full_needed_ammo > store_of_ammo) {
      for (unsigned int i = 0; i < air_crafts.size(); i++) {
        if (air_crafts[i]->type == "F35") {
          air_crafts[i]->refill(store_of_ammo);
          set_total_damage();
        }
      }
    }
  } else {
    throw "empty";
  }
}

void Carrier::figth(Carrier &carrier) {
  int damage = 0;
  for (unsigned int i = 0; i < air_crafts.size(); i++) {
    damage += air_crafts[i]->fight();
    carrier.health_point -= damage;
  }
  store_of_ammo = 0;
}

bool Carrier::is_dead(){
  return health_point <= 0;
}
