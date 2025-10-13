#pragma once

#include <iostream>
//#include <string>

class Zombie{
	std::string name;

	public:
	//Zombie(std::string n);	
	~Zombie();

	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);