#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


int main(void){
	std::srand(std::time(NULL));

	Base *a = new A();
	Base *b = new B();
	Base *c = new C();


	identify(a);
	identify(b);
	identify(c);

	std::cout << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);

	delete a;
	delete b;
	delete c;

	std::cout << std::endl << std::endl;

	Base *x = generate();
	Base *g = generate();
	Base *f = generate();

	identify(x);
	identify(g);
	identify(f);
	std::cout << std::endl;

	identify(*x);
	identify(*g);
	identify(*f);

	delete x;
	delete g;
	delete f;
}