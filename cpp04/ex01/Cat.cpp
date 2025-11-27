#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return(*this);
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound() const {
	std::cout << "Cat meows: meow" << std::endl;
}

Brain* Cat::getBrain() const{
	return (this->brain);
}