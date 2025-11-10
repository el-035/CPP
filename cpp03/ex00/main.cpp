#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elf("Elf");
	elf.printPoints();

	ClapTrap human("human");
	human = elf;
	elf.printPoints();

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