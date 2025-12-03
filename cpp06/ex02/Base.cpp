#include"Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


Base::~Base() {}

Base * generate(void){
	int r = rand() % 3;

	Base *base = NULL;

	if (r == 0)
	{
		std::cout << "Generated type A" << std::endl;
		base = new A();
	}
	else if (r == 1)
	{
		std::cout << "Generated type B" << std::endl;
		base = new B();
	}
	else if (r == 2)
	{
		std::cout << "Generated type C" << std::endl;
		base = new C();
	}
	return base;
}

void identify(Base* p){
	A *a;
	B *b;
	C *c;
	a = dynamic_cast<A *>(p);
	if (a != NULL){
		std::cout << "Type: A" << std::endl;
		return ;
	}
	b = dynamic_cast<B *>(p);
	if (b != NULL){
		std::cout << "Type: B" << std::endl;
		return ;
	}
	c = dynamic_cast<C *>(p);
	if (c != NULL){
		std::cout << "Type: C" << std::endl;
		return ;
	}
	std::cout << "Wrong type" << std::endl;
}

void identify(Base& p){
	A a;
	B b;
	C c;
	try{
		a = dynamic_cast<A&>(p);
		std::cout << "Type: A	" << std::endl;
		return ;
	}
	catch(...) {}

	try{
		b = dynamic_cast<B&>(p);
		std::cout << "Type: B	" << std::endl;
		return ;
	}
	catch(...) {}

	try{
		c = dynamic_cast<C&>(p);
		std::cout << "Type: C	" << std::endl;
		return ;
	}
	catch(...) {}
	std::cout << "Wrong type" << std::endl;
}