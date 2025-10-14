#pragma once

#include <iostream>
//#include <string>

class Weapon{
	std::string type;

	public:
	const std::string &get_Type();
	void setType(std::string value);
};