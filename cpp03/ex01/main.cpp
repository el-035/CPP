#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap robot("Robot");
	ScavTrap nameless;

	std::cout << std::endl;
	nameless.attack("Human");
	nameless.printPoints();


	std::cout << std::endl;
	robot.attack("Human");
	robot.printPoints();

	robot.guardGate();
	std::cout << std::endl;

	robot.beRepaired(5);
	robot.printPoints();
	std::cout << std::endl;

	robot.takeDamage(70);
	robot.printPoints();
	std::cout << std::endl;

	robot.attack("Human");
	robot.printPoints();
	std::cout << std::endl;

	robot.takeDamage(35);
	robot.printPoints();
}