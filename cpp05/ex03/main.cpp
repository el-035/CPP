#include "Bureaucrat.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"Intern.hpp"

int main (void)
{
	Intern anonym;
	std::string formA = "shrubbery creation";
	std::string formB = "robotomy request";
	std::string formC = "presidential pardon";
	std::string formD = "wrong form";
	std::string target = "target";

	try{
		AForm* createdA = anonym.makeForm(formA, target);
		std::cout << *(createdA) << std::endl;
		delete createdA;
		
		AForm* createdB = anonym.makeForm(formB, target);
		std::cout << *(createdB) << std::endl;
		delete createdB;

		AForm* createdC = anonym.makeForm(formC, target);
		std::cout << *(createdC) << std::endl;
		delete createdC;
		
		
		AForm* createdD = anonym.makeForm(formD, target);
		std::cout << *(createdD) << std::endl;
		delete createdD;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *(rrf) << std::endl;
		delete rrf;
	}
}