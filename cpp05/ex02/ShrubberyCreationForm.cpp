#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Unknown"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSigGrade(), other.getExeGrade()), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other)	//TEST HERE, ARE ALL DATA CORRECT??
		this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!this->getSig() || executor.getGrade() > this->getExeGrade())
	/* Creates a file <target>_shrubbery in the working directory and writes ASCII trees
	inside it. */

}

std::string ShrubberyCreationForm::getTarget() const{
	return (target);
}


std::ostream& operator<<(std::ostream& output, const ShrubberyCreationForm& object){
	std::string sig;
	if (object.getSig())
		sig = " has been signed. Grade to sign: ";
	else
		sig = " has not been signed. Grade to sign: ";
	int s = object.getSigGrade();
	std::stringstream ss;
	ss << s;
	int e = object.getExeGrade();
	std::stringstream ee;
	ee << e;
	std::string msg = object.getName() + sig + ss.str() + ". Grade to execute: " + ee.str() + ". Target: " + object.getTarget();
	output << msg;
	return (output);
}


