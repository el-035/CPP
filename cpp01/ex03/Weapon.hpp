#pragma once

#include <iostream>
//#include <string>

class Weapon{
	std::string type;

	public:
	Weapon(std::string gun);
	const std::string &getType() const;
	void setType(const std::string &value);
};