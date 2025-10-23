#include "Point.hpp"

void printmsg(Point const a, Point const b, Point const c, Point const p)
{
	if (bsp(a, b, c, p))
		std::cout << "     INSIDE!" << std::endl;
	else
		std::cout << "     OUTSIDE!" << std::endl;
}

int main( void ) {
	int i = 0;
	{	//outside	0
		std::cout << "Test n " << i++ << std::endl;
		Point a;
		Point b(9, 7);
		Point c(8, 2);
		Point p(3, 4);
		printmsg(a, b, c, p);
	}

	{	//inside	1
		std::cout << "Test n " << i++ << std::endl;
		Point a(3, 4);
		Point b(9, 7);
		Point c(8, 2);
		Point p(8, 4);
		printmsg(a, b, c, p);
	}
	{	//on a	2
		std::cout << "Test n " << i++ << std::endl;
		Point a;
		Point b(9, 7);
		Point c(8, 2);
		Point p;
		printmsg(a, b, c, p);
	}
	{	//outside	3
		std::cout << "Test n " << i++ << std::endl;
		Point a(1, 5);	
		Point b(9, 7);
		Point c(8, 2);
		Point p(3, 4);
		printmsg(a, b, c, p);
	}
	{	//inside	4
		std::cout << "Test n " << i++ << std::endl;
		Point a(0.5f, 0.5f);
		Point b(0.5f, 7.5f);
		Point c(8.5f, 2);
		Point p(0.8, 2);
		printmsg(a, b, c, p);
	}

	{	// inside	5
		std::cout << "Test n " << i++ << std::endl;
		Point a(0.5f, 0.5f);
		Point b(0.5f, 7.5f);
		Point c(8.5f, 2);
		Point p(0.8f, 2);
		printmsg(a, b, c, p);
	}

	{	// inside	6
		std::cout << "Test n " << i++ << std::endl;
		Point a(-3.0f, -1.0f);
		Point b(2.0f, -4.0f);
		Point c(-1.0f, 3.0f);
		Point p(-0.5f, -0.5f);
		printmsg(a, b, c, p);
	}

	{	// outside	7
		std::cout << "Test n " << i++ << std::endl;
		Point a(-5.0f, -2.0f);
		Point b(-1.0f, -6.0f);
		Point c(0.0f, -1.0f);
		Point p(1.0f, -4.0f);
		printmsg(a, b, c, p);
	}

	{	// inside	8
		std::cout << "Test n " << i++ << std::endl;
		Point a(-4.0f, 2.0f);
		Point b(-1.0f, 6.0f);
		Point c(3.0f, 1.0f);
		Point p(-1.5f, 3.0f);
		printmsg(a, b, c, p);
	}

	{	// on edge		9
		std::cout << "Test n " << i++ << std::endl;
		Point a(0.0f, 0.0f);
		Point b(5.0f, 0.0f);
		Point c(2.5f, 5.0f);
		Point p(2.5f, 0.0f);
		printmsg(a, b, c, p);
	}

	{	// inside	10
		std::cout << "Test n " << i++ << std::endl;
		Point a(-2.5f, -2.5f);
		Point b(-7.0f, 3.0f);
		Point c(-1.0f, 4.0f);
		Point p(-3.5f, 0.5f);
		printmsg(a, b, c, p);
	}
}