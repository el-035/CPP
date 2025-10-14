#include"Weapon.hpp"

const std::string &Weapon::get_Type()
{
	return (type);
}

void Weapon::setType(std::string value)
{
	type = value;
}