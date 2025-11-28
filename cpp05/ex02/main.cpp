#include "Bureaucrat.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"


int main (void)
{
	{
		std::cout << S_RED << "TEST CONSTRUCTORS" << E_RED << std::endl;
		ShrubberyCreationForm a("Burocrazia");
		std::cout << "a: " << a << std::endl;
		ShrubberyCreationForm b = a;
		std::cout << "b: " << b << std::endl;
		ShrubberyCreationForm c;
		c = a;
		std::cout << "c: " << c << std::endl;
	}
	//int i = 0;
	
	// std::cout << S_RED << "TEST " << i++ << E_RED << std::endl;	// 0
	// try
	// {
	// 	Bureaucrat j("Juan", 140);
	// 	AForm c ("MoreCoffeBreaks", 140, 100);
	// 	j.decrement();
	// 	std::cout << j << std::endl;
	// 	//first exception in the sign form function
	// 	j.signForm(c);
	// 	std::cout << c << std::endl;
	// 	//second exception here
	// 	AForm d("WorkMoreChatLess", 160, 1);
	// }
	// catch(const std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	

	// std::cout << std::endl << S_RED << "TEST " << i++ << E_RED << std::endl; //1
	// try
	// {
	// 	Bureaucrat j("Juan", 1);
	// 	AForm c ("MoreCoffeBreaks", 140, 100);
	// 	j.signForm(c);
	// 	std::cout << c << std::endl;
	// 	//cannot increment
	// 	j.increment();
	// 	std::cout << j << std::endl;
	// }
	// catch(const std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	

	// std::cout << std::endl << S_RED << "TEST " << i++ << E_RED << std::endl; //2
	// try
	// {
	// 	Bureaucrat j("Juan", 150);
	// 	//form sign too high
	// 	AForm c ("MoreCoffeBreaks", 160, 100);
	// 	std::cout << j << std::endl;
	// }
	// catch(const std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }


	// std::cout << std::endl << S_RED << "TEST " << i++ << E_RED << std::endl; //3
	// try
	// {
	// 	Bureaucrat j("Juan", 150);
	// 	AForm c ("MoreCoffeBreaks", 100, 0);
	// 	j.decrement();
	// 	std::cout << j << std::endl;
	// }
	// catch(const std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }


	// std::cout << std::endl << S_RED << "TEST " << i++ << E_RED << std::endl; //4
	// try
	// {
	// 	Bureaucrat j("Juan", 100);
	// 	AForm c ("MoreCoffeBreaks", 100, 1);
	// 	j.signForm(c);
	// 	std::cout << c << std::endl;
	// 	j.decrement();
	// 	AForm d ("MoreCiggieBreaks", 100, 1);
	// 	j.signForm(d);
	// 	std::cout << c << std::endl;
	// 	std::cout << j << std::endl;
	// }
	// catch(const std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }


	// std::cout << std::endl << S_RED << "TEST " << i++ << E_RED << std::endl; // 5
	// try
	// {
	// 	Bureaucrat j("Juan", 100);
	// 	std::cout << j << std::endl;
	// 	Form c ("MoreCoffeBreaks", 100, 1);
	// 	j.signForm(c);
	// 	std::cout << c << std::endl;
	// 	j.decrement();
	// 	std::cout << j << std::endl;
	// 	AForm d ("MoreCiggieBreaks", 100, 1);
	// 	j.signForm(d);
	// 	std::cout << c << std::endl;

	// }
	// catch(const std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
}