#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("form"), sig(false), sigGrade(50), exeGrade(10){}

AForm::AForm(std:: string name, const int sigGrade, const int exeGrade) : name(name), sig(false), sigGrade(sigGrade), exeGrade(exeGrade){
	if (exeGrade > 150 || sigGrade > 150)
		throw AForm::GradeTooLowException();
	if (exeGrade <= 0 || sigGrade <= 0)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), sig(false), sigGrade(other.sigGrade), exeGrade(other.exeGrade) {
	if (exeGrade > 150 || sigGrade > 150)
		throw AForm::GradeTooLowException();
	if (exeGrade <= 0 || sigGrade <= 0)
		throw AForm::GradeTooHighException();
}

AForm& AForm::operator=(const AForm& other){
	(void)other;
	return (*this);
}

AForm::~AForm(){}

const std::string& AForm::getName() const{
	return (name);
}

bool AForm::getSig() const{
	return(sig);
}

int AForm::getSigGrade() const{
	return (sigGrade);
}

int AForm::getExeGrade() const{
	return (exeGrade);
}

bool AForm::beSigned(const Bureaucrat& lento){
	if (sig == true)
		return false;
	if (lento.getGrade() <= this->getSigGrade())
	{
		sig = true;
		return (true);
	}
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}

const char* AForm::FormNotSignedException ::what() const throw(){	
	return ("Form has not been signed yet!");
}

const char* AForm::FormAlreadySignedException ::what() const throw(){
	return ("Form has already been signed!");
}

std::ostream& operator<<(std::ostream& output, const AForm& object){
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
	std::string msg = "Form: " + object.getName() + sig + ss.str() + ". Grade to execute: " + ee.str();
	output << msg;
	return (output);
}

void AForm::execute(Bureaucrat const & executor) const{
	if (!this->getSig())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();
}