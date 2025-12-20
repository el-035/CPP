#include "Span.hpp"

/* int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
} */

/* int main(void){
	Span sp = Span(77);
	//empty so it fails
	try{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	//add one by one and works untill last added
	for (int i = 0; i <= 77; ++i)
	    sp.addNumber(i);
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
} */

int main(void){
	std::vector<int> v;
	for (int i = 0; i < 20000; ++i)
	    v.push_back(i);
	Span sp = Span(20000);
	//add from vector instead of manually
	sp.addNumber(v.begin(), v.end());
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	//testing constructors
	Span test;
	test = sp;
	try{
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}