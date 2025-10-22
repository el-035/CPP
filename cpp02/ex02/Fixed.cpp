#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}
	
Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (&other == this)
		return (*this);
	this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" <<std::endl;

	value = n << fractBits;
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called" <<std::endl;
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

bool Fixed::operator>(const Fixed& other) const
{
	if (this->value > other.value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->value < other.value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->value >= other.value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->value <= other.value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->value == other.value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->value != other.value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	int res = this->value + other.value;
	Fixed add;
	add.setRawBits(res);
	return(add);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	int res = this->value - other.value;
	Fixed sub;
	sub.setRawBits(res);
	return(sub);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	long long res = (long long)this->value * other.value;
	res = res >> 8;
	Fixed mult;
	mult.setRawBits(res);
	return(mult);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	long long res = (long long)(this->value << 8) / other.value;
	Fixed div;
	div.setRawBits(res);
	return(div);
}

Fixed& Fixed::operator++() //pre
{
	value += 1;
	return(*this);
}

Fixed& Fixed::operator--() //pre
{
	value -= 1;
	return(*this);
}

Fixed Fixed::operator++(int) //post
{
	Fixed temp = *this;
	value += 1;
	return(temp);
}

Fixed Fixed::operator--(int) //post
{
	Fixed temp = *this;
	value -= 1;
	return(temp);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first.value <= second.value)
		return (first);
	return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first.value >= second.value)
		return (first);
	return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.value <= second.value)
		return (first);
	return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.value >= second.value)
		return (first);
	return (second);
}
