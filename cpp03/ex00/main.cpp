#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elf("Elf");

	elf.attack("Human");

	elf.beRepaired(1);
	elf.printPoints();

	elf.takeDamage(10);
	elf.printPoints();

	elf.takeDamage(7);
	elf.printPoints();

	elf.takeDamage(7);
	elf.printPoints();

	elf.beRepaired(1);
	elf.printPoints();
}