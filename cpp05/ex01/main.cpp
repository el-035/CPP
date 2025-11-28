#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	int i = 0;
	
	std::cout << "Test " << i++ << std::endl;	// 0
	try
	{
		Bureaucrat j("Juan", 140);
		Form c ("MoreCoffeBreaks", 140, 100);
		j.decrement();
		std::cout << j << std::endl;
		//first exception in the sign form function
		j.signForm(c);
		std::cout << c << std::endl;
		//second exception here
		Form d("WorkMoreChatLess", 160, 1);
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	

	std::cout << std::endl << "Test " << i++ << std::endl; //1
	try
	{
		Bureaucrat j("Juan", 1);
		Form c ("MoreCoffeBreaks", 140, 100);
		j.signForm(c);
		std::cout << c << std::endl;
		//cannot increment
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
		//form sign too high
		Form c ("MoreCoffeBreaks", 160, 100);
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << "Test " << i++ << std::endl; //3
	try
	{
		Bureaucrat j("Juan", 150);
		Form c ("MoreCoffeBreaks", 100, 0);
		j.decrement();
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << "Test " << i++ << std::endl; //4
	try
	{
		Bureaucrat j("Juan", 100);
		Form c ("MoreCoffeBreaks", 100, 1);
		j.signForm(c);
		std::cout << c << std::endl;
		j.decrement();
		Form d ("MoreCiggieBreaks", 100, 1);
		j.signForm(d);
		std::cout << c << std::endl;
		std::cout << j << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << "Test " << i++ << std::endl; // 5
	try
	{
		Bureaucrat j("Juan", 100);
		Bureaucrat k("Anonym", 50);
		std::cout << k << std::endl;
		std::cout << j << std::endl;
		Form c ("MoreCoffeBreaks", 100, 1);
		j.signForm(c);
		std::cout << c << std::endl;
		j.decrement();
		std::cout << j << std::endl;
		Form d ("MoreCiggieBreaks", 50, 1);
		j.signForm(d);
		k.signForm(d);
		k.signForm(c);
		std::cout << c << std::endl;
		std::cout << d << std::endl;
	}
	catch(const std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
}