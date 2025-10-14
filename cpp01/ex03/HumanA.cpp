#include"HumanA.hpp"

void HumanA::attack()
{
	std::cout << name << " attacks with their" << weapon.get_Type() << std::endl;
}
