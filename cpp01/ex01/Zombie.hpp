#pragma once

#include <iostream>

class Zombie{
	std::string name;

	public:
	~Zombie();

	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);