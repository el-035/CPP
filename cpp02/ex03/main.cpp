#include "Point.hpp"

void printmsg(Point const a, Point const b, Point const c, Point const p)
{
	if (bsp(a, b, c, p))
		std::cout << "INSIDE!" << std::endl;
	else
		std::cout << "OUTSIDE!" << std::endl;
}

int main( void ) {
	{	//outside
		Point a;
		Point b(9, 7);
		Point c(8, 2);
		Point p(3, 4);
		printmsg(a, b, c, p);
	}

	{	//inside
		Point a(3, 4);
		Point b(9, 7);
		Point c(8, 2);
		Point p(8, 4);
		printmsg(a, b, c, p);
	}
	{	//on a
		Point a;
		Point b(9, 7);
		Point c(8, 2);
		Point p;
		printmsg(a, b, c, p);
	}
	{	//outside
		Point a(1, 5);
		Point b(9, 7);
		Point c(8, 2);
		Point p(3, 4);
		printmsg(a, b, c, p);
	}
}