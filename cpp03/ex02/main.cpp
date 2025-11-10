#include "FragTrap.hpp"

int main(void)
{
	FragTrap frog("Frog");
	FragTrap nameless;
	FragTrap jj(frog);

	jj.highFiveguys();
	std::cout << std::endl;

	std::cout << std::endl;
	nameless.attack("Human");
	nameless.printPoints();


	std::cout << std::endl;
	frog.attack("Robot");
	frog.printPoints();

	frog.highFiveguys();
	std::cout << std::endl;

	frog.beRepaired(5);
	frog.printPoints();
	std::cout << std::endl;

	frog.takeDamage(70);
	frog.printPoints();
	std::cout << std::endl;

	frog.attack("Human");
	frog.printPoints();
	std::cout << std::endl;

	frog.takeDamage(35);
	frog.printPoints();
}