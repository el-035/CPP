#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Unknown"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSigGrade(), other.getExeGrade()), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other)
		this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
	std::ofstream ShrubberyFile((target + "_shrubbery").c_str(), std::ios::trunc);
	if (!ShrubberyFile.is_open())
		throw std::runtime_error("Failed: Could not open file");
	ShrubberyFile << "   /\\\n  /**\\\n /****\\\n   ||\n   ||\n";
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


