#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;


	{//COMPARISONS
		Fixed a(15.15f);
		Fixed b(12.12f);
		std::cout << "COMPARISONS" << std::endl;
		std::cout << "a > b " << (a > b) << std::endl;
		std::cout << "a < b " << (a < b) << std::endl;
		std::cout << "a >= b " << (a >= b) << std::endl;
		std::cout << "a <= b " << (a <= b) << std::endl;
		std::cout << "a == b " << (a == b) << std::endl;
		std::cout << "a != b " << (a != b) << std::endl << std::endl;

	}
	{//ADDITION
		std::cout << "ADDITION" << std::endl;
		Fixed a(10.5f);
		Fixed b(2.7f);
		std::cout << "10.5 + 2.7 = " << (10.5 + 2.7) << std::endl;
		std::cout << "a = " << a.getRawBits() << std::endl;
		std::cout << "b = " << b.getRawBits() << std::endl;
		Fixed res = a + b;
		std::cout << "a + b = " << res.getRawBits() << std::endl;

		std::cout << "a + b = " << res.toFloat() << std::endl;
	}

	{	//SUB
		std::cout << std::endl << "SUB" << std::endl;
		Fixed a(10.5f);
		Fixed b(2.7f);
		std::cout << "10.5 - 2.7 = " << (10.5 - 2.7) << std::endl;
		std::cout << "a = " << a.getRawBits() << std::endl;
		std::cout << "b = " << b.getRawBits() << std::endl;
		Fixed res = a - b;
		std::cout << "a - b = " << res.getRawBits() << std::endl;

		std::cout << "a - b = " << res.toFloat() << std::endl;
	}

	{	//MULT
		std::cout << std::endl << "MULT" << std::endl;
		Fixed a(10.5f);
		Fixed b(2.7f);
		std::cout << "10.5 * 2.7 = " << (10.5 * 2.7) << std::endl;
		std::cout << "a = " << a.getRawBits() << std::endl;
		std::cout << "b = " << b.getRawBits() << std::endl;
		Fixed res = a * b;
		std::cout << "a * b = " << res.getRawBits() << std::endl;

		std::cout << "a * b = " << res.toFloat() << std::endl;
	}

	{	//DIV
		std::cout << std::endl << "DIV" << std::endl;
		Fixed a(10.5f);
		Fixed b(2.7f);
		std::cout << "10.5 / 2.7 = " << (10.5 / 2.7) << std::endl;
		std::cout << "a = " << a.getRawBits() << std::endl;
		std::cout << "b = " << b.getRawBits() << std::endl;
		Fixed res = a / b;
		std::cout << "a / b = " << res.getRawBits() << std::endl;

		std::cout << "a / b = " << res.toFloat() << std::endl;
	}

	{//INCREMENT DECREMENT
		std::cout << std::endl << "INCREMENT / DECREMENT" << std::endl;
		Fixed a(10);
		Fixed b(15.15f);
		std::cout << "a = " << a.toInt() << std::endl << "b = " << b.toFloat() << std::endl; 
		std::cout << "a++ " << a++ << std::endl;
		std::cout << "b++ " << b++ << std::endl;
		std::cout << "a-- " << a-- << std::endl;
		std::cout << "b-- " << b-- << std::endl;
		std::cout << std::endl;
		std::cout << "++a " << ++a << std::endl;
		std::cout << "++b " << ++b << std::endl;
		std::cout << "--a " << --a << std::endl;
		std::cout << "--b " << --b << std::endl;
	}

	

}	