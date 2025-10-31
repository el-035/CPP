#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Nameless"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called!" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other){
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0 || this->attackDamage == 0){
		std::cout << "ClapTrap " << name << " does not have enough points to attack!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= hitPoints)
		hitPoints -= amount;
	else
	{
		amount = hitPoints; // or not
		hitPoints = 0;
	}
	std::cout << name << " was attacked! " << name << " lost " << amount << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0){
		std::cout << name << "does not have enough points to be repaired!" << std::endl;
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
