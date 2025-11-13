#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "Wrong Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "Wrong Animal makes no sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return(type);
}
