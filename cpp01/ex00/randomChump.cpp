#include"Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	//create zombie?
	Zombie *test;

	//name it
	Name = name;

	//make it announce
	announce();
}