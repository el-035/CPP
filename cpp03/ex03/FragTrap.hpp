#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	protected:
	static const int HP = 100;
	static const int EP = 100;
	static const int AD = 30;
	
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void highFiveguys(void);
};