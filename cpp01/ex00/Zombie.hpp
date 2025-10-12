#pragma once

#include <iostream>
//#include <sstream>
//#include <string>
//#include <iomanip>

class Zombie{
	std::string Name; //or name?

	public:
	void announce(void);

	Zombie* newZombie(std::string name);
	void randomChump(std::string name);
	
};

//destructor