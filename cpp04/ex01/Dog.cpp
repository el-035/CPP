#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other){
	std::cout << "Dog copy constructor called" << std::endl;
	//this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog barks: woof" << std::endl;
}

Brain* Dog::getBrain() const{
	return (this->brain);
}
