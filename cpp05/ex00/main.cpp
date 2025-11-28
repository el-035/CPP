#include "Bureaucrat.hpp"

int main (void)
{
	int i = 0;
	
	std::cout << "Test " << i++ << std::endl;	// 0
	try
	{
		Bureaucrat j("Juan", 1);
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	

	std::cout << std::endl << "Test " << i++ << std::endl; //1
	try
	{
		Bureaucrat j("Juan", 1);
		j.increment();
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	

	std::cout << std::endl << "Test " << i++ << std::endl; //2
	try
	{
		Bureaucrat j("Juan", 150);
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << "Test " << i++ << std::endl; //3
	try
	{
		Bureaucrat j("Juan", 150);
		j.decrement();
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << "Test " << i++ << std::endl; //4
	try
	{
		Bureaucrat j("Juan", 150);
		j.increment();
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << "Test " << i++ << std::endl; // 5
	try
	{
		Bureaucrat j;
		j.increment();
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}	


	std::cout << std::endl << "Test " << i++ << std::endl; // 6
	try
	{
		Bureaucrat j("JJ", 75);
		j.increment();
		j.decrement();
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
}