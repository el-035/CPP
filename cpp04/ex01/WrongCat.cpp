#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = other.type;
}
WrongCat& WrongCat::operator=(const WrongCat& other){
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return(*this);
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}
