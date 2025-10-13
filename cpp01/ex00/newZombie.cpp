#include"Zombie.hpp"

Zombie* newZombie(std::string name)
{
	//create zombie?
	Zombie *z = new Zombie(name);
	
	//return pointer to zombie
	return (z);
}