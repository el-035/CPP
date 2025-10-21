#pragma once

#include <iostream>

class Fixed{
	int value;
	static const int fract;

	public:
	Fixed();
	Fixed(Fixed& other); //?
	Fixed& operator=(Fixed& other);
	~Fixed();

	int getRawBits(void);
	void setRawBits(int const raw);
};


/*
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
 */