#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}
	
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other == this)
		return (*this);
	this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" <<std::endl;

	value = n << fractBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" <<std::endl;
	int p = 1 << fractBits;
	value = roundf(n * p);
}

float Fixed::toFloat(void) const
{
	int p = 1 << fractBits;
	float res = (float)value / (float)p;
	return(res);
}

int Fixed::toInt(void) const
{
	int res = value >> fractBits;
	return (res);
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" <<std::endl;
	return(value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
	float f = fixed.toFloat();
	output << f;
	return (output);
}