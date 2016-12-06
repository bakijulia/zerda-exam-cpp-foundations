#include "AirCraft.h"
#include <iostream>

AirCraft::AirCraft() {
  max_ammo = 0;
  base_damage = 0;
  actual_ammo = 0;
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

void AirCraft::print_status(){
  std::cout << "Type: " << get_type() << " ";
  std::cout << "Max ammo: " << get_max_ammo() << " ";
  std::cout << "Actual ammo: " << get_actual_ammo() << " ";
  std::cout << "Base damage: " << get_base_damage() << " ";
}
