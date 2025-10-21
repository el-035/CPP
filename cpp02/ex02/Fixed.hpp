#pragma once

#include <iostream>
#include <cmath>

class Fixed{
	int value;
	static const int fractBits = 8;

	public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	Fixed(const int n);
	Fixed(const float n);

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& first, Fixed& second);
	static const Fixed& min(const Fixed& first, const Fixed& second);

	static Fixed& max(Fixed& first, Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);


};

std::ostream& operator<<(std::ostream& output, const Fixed& object);


/*
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/