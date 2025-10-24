#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap elf("Elf");
	
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