#include"HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name) {}

void HumanB::setWeapon(Weapon &type)
{
	weapon = &type;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

