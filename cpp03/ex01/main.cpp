#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elf("Elf");
/* 	ClapTrap human(elf);
	ClapTrap rosa=human;
	
	human.takeDamage(9);
	human.printPoints();

	rosa.takeDamage(9);
	rosa.printPoints(); */

	elf.attack("Human");
	elf.printPoints();

	elf.beRepaired(5);
	elf.printPoints();

	elf.attack("Human");
	elf.printPoints();

	elf.takeDamage(7);
	elf.printPoints();

	elf.attack("Human");
	elf.printPoints();

	elf.takeDamage(7);
	elf.printPoints();
}