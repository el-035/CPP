#include"HumanA.hpp"

HumanA::HumanA(std::string n, Weapon gun)
{
	weapon = gun;
	name = n;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their" << weapon.get_Type() << std::endl;
}
