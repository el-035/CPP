#pragma once

#include"Weapon.hpp"
#include <iostream>

class HumanB{
	std::string name;
	Weapon* weapon;

	public:
	HumanB(const std::string &name);

	void setWeapon(Weapon &type);
	void attack();
};