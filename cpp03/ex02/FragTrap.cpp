#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called!" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called!" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::highFiveguys(void){
	std::cout << "FragTrap " << name << " wants a high five!" << std::endl;
}