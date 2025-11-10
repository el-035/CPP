#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Nameless"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.hitPoints), attackDamage(other.attackDamage) {
	std::cout << "Copy constructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0 || this->attackDamage == 0){
		std::cout << name << " does not have enough points to attack!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " has been attacked, ";
	if (hitPoints == 0)
	{
		std::cout << "but " << name << " is already dead *_* " << std::endl;
		return ;
	}
	if (amount <= hitPoints)
		hitPoints -= amount;
	else
	{
		amount = hitPoints;
		hitPoints = 0;
	}
	std::cout << name << " lost " << amount << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0){
		std::cout << name << " does not have enough points to be repaired!" << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << name << " regained " << amount << " hit points!" << std::endl;
}

void ClapTrap::printPoints(void)
{
	std::cout << name << ": hitPoints = " << hitPoints << std::endl;
	std::cout << name <<": energyPoints = " << energyPoints << std::endl;
	std::cout << name <<": attackDamage = " << attackDamage << std::endl << std::endl;
}
