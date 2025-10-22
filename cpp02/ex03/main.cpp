#include "Point.hpp"

int main( void ) {
	{
	Point a(3, 4);
	Point b(9, 7);
	Point c(8, 2);
	Point p(5, 7);
	if (bsp(a, b, c, p))
		std::cout << "ITS INSIDE!" << std::endl;
	else
		std::cout << "ITS outside!" << std::endl;
	}
	{
		Point a(3, 4);
		Point b(9, 7);
		Point c(8, 2);
		Point p(8, 4);
		if (bsp(a, b, c, p))
			std::cout << "ITS INSIDE!" << std::endl;
		else
			std::cout << "ITS outside!" << std::endl;
	}
}