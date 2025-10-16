#include"HumanA.hpp"

/* HumanA::HumanA(std::string human, Weapon gun)
{

	weapon = gun;
	name = human;
} */
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
