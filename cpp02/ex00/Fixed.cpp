#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;

}
	
Fixed& Fixed::operator=(Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}

int getRawBits(void)
{
	std::cout << "getRawBits member function called" <<std::endl;
}

void setRawBits(int const raw)
{
	
}