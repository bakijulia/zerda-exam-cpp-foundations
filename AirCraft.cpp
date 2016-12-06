#include "AirCraft.h"
#include <iostream>
#include <string>

AirCraft::AirCraft() {
  max_ammo = 0;
  base_damage = 0;
  actual_ammo = 0;
  all_damage = 0;
  needed_ammo = max_ammo - actual_ammo;
}

AirCraft::~AirCraft() {}

int AirCraft::get_max_ammo(){
  return max_ammo;
}

int AirCraft::get_base_damage(){
  return base_damage;
}

int AirCraft::get_actual_ammo(){
  return actual_ammo;
}

std::string AirCraft::get_type(){
  return type;
}

std::string AirCraft::get_status(){
  return "Type: " + get_type() + " " + "Actual ammo: " + std::to_string(actual_ammo) + " " + "Max ammo: " + std::to_string(max_ammo) + " "
      + " " + "Base Damage: " + std::to_string(base_damage) + " " + "All Damage: " + std::to_string(all_damage);
}

void AirCraft::set_all_damage(){
  all_damage = base_damage * actual_ammo;
}

int AirCraft::fight(){
  actual_ammo = 0;
  return all_damage;
}

void AirCraft::refill(int &number){
  int ideal_refill = actual_ammo + number;
  if(ideal_refill > max_ammo){
    int susbtarct = ideal_refill - max_ammo;
    actual_ammo = max_ammo;
    number -= susbtarct;
    set_all_damage();
  } else {
    actual_ammo = ideal_refill;
    number -= ideal_refill - actual_ammo;
    set_all_damage();
  }
}
