#include"Zombie.hpp"

int main(void)
{
	//create zombie on the stack
	randomChump("Junkie");

	std::cout << std::endl;

	//create zombie on the heap
	Zombie *z = newZombie("Zombie");
	z->announce();
	delete z;
}