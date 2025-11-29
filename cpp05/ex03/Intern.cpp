#include"Intern.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return (*this);
}
Intern::~Intern(){}

AForm* Intern::Shrubbery(const std::string& target){
	AForm *shr = new ShrubberyCreationForm(target);
	return(shr);
}

AForm* Intern::Robotomy(const std::string& target){
	AForm *rob = new RobotomyRequestForm(target);
	return(rob);
}

AForm* Intern::Presidential(const std::string& target){
	AForm *pre = new PresidentialPardonForm(target);
	return(pre);
}


AForm* Intern::makeForm(const std::string& form, const std::string& target){
	AForm* (*createForms[3])(const std::string&) = {Shrubbery, Robotomy, Presidential};
	std::string name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++){
		if (name[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (createForms[i](target));
		}
	}
	throw(FormNameNotFound());
}

const char *Intern::FormNameNotFound::what() const throw(){
	return ("Given form name does not exist!");
}
