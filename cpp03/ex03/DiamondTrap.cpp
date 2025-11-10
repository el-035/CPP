#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Nameless_clap_name"), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	/* this->name = "Nameless";
	hitPoints = FragTrap::HP;
	energyPoints = ScavTrap::EP;
	attackDamage = FragTrap::AD; */
	DiamondTrap::setVar("Nameless");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
/* 	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30; */
	DiamondTrap::setVar(name);

}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
/* 	this->name = other.name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30; */
	DiamondTrap::setVar(other.name);

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	std::cout << "Diamond copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return(*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Diamond destructor called" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "my name is " << DiamondTrap::name << " and my Clap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::setVar(std::string name){
	this->name = name;
	hitPoints = FragTrap::HP;
	energyPoints = ScavTrap::EP;
	attackDamage = FragTrap::AD;
}
