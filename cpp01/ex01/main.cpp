#include "Zombie.hpp"

int main(void)
{
	Zombie *first = zombieHorde(6, "Gumpis");
	for (int i = 0; i < 6; i++)
		first[i].announce();
	delete[] first;

	std::cout << std::endl;

	Zombie *second = zombieHorde(3, "Berliners");
	for (int i = 0; i < 3; i++)
		second[i].announce();
	delete[] second;

}