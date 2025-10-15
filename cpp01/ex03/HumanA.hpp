#pragma once

#include"Weapon.hpp"
#include <iostream>

class HumanA{
	std::string name;
	Weapon weapon;

	public:
	HumanA(std::string name, Weapon weapon);

	void attack();
};