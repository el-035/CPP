#include"Zombie.hpp"

void randomChump(std::string name)
{
	//create zombie?
	Zombie z(name);

	//make it announce
	z.announce();
}