#pragma once

#include<iostream>

class ClapTrap{
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

	public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	ClapTrap(std::string name);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};