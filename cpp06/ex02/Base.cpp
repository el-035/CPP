#include"Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


Base::~Base() {}

Base * generate(void){
	int r = rand() % 3;

	Base *base;

	if (r == 0)
		base = new A();
	else if (r == 1)
		base = new B();
	else if (r == 2)
		base = new C();
	/* std::cout << r << std::endl; */
	return base;
	/* It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation. */
}

void identify(Base* p){
	A *a;
	B *b;
	C *c;
	a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "Type: A" << std::endl;
	b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "Type: B" << std::endl;
	c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "Type: C" << std::endl;
}

void identify(Base& p){
	try{
		dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	try{
		dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	try{
		dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}