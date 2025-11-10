#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
	protected:
	static const int HP = 100;
	static const int EP = 50;
	static const int AD = 20;
	
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	
	void guardGate();
	void attack(const std::string& target);
};