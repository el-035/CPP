#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(){
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog copyasignment operator called" << std::endl;
	if (this != &other)
		this->type = "Dog";
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog barks: woof" << std::endl;
}