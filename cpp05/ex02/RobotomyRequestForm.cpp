#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other.getName(), other.getSigGrade(), other.getExeGrade()), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other)
		this->target = other.target;
	return (*this);
	
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	//do smt
	(void)executor;

}

std::string RobotomyRequestForm::getTarget() const{
	return (target);
}

std::ostream& operator<<(std::ostream& output, const RobotomyRequestForm& object){
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{

}
