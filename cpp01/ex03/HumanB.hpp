#pragma once

#include"Weapon.hpp"
#include <iostream>

class HumanB{
	std::string name;
	Weapon weapon;

	public:
	HumanB(std::string name);

	void setWeapon(std::string type);
	void attack();
};