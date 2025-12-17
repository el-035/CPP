#include "Span.hpp"

/* int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	//sp.addNumber(11);
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
} */

/* int main(void){
	std::vector<int> v;
	for (int i = 0; i <= 77; ++i)
	    v.push_back(i);
	Span sp = Span(77);
	sp.addNumber(v.begin(), v.end());
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
	for (int i = 0; i <= 10000; ++i)
	    v.push_back(i);
	Span sp = Span(10000);
	sp.addNumber(v.begin(), v.end());
	try{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
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