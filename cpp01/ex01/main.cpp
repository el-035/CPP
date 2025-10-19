#include "Zombie.hpp"

int main(void)
{
	Zombie *first = zombieHorde(6, "Junkies");
	for (int i = 0; i < 6; i++)
		first[i].announce();
	delete[] first;

	std::cout << std::endl;

	Zombie *second = zombieHorde(3, "More Junkiesss");
	for (int i = 0; i < 3; i++)
		second[i].announce();
	delete[] second;

}