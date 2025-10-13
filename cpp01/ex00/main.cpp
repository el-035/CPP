#include"Zombie.hpp"

int main(void)
{
	//create zombie on the stack
	randomChump("Junkie");

	std::cout << std::endl;

	//create zombie on the heap
	Zombie *z = newZombie("Gumpi");
	z->announce();
	delete z;
}