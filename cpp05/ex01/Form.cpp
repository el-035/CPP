#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("form"), sig(false), sigGrade(50), exeGrade(10){}

Form::Form(std:: string name, const int sigGrade, const int exeGrade) : name(name), sig(false), sigGrade(sigGrade), exeGrade(exeGrade){
	if (exeGrade > 150 || sigGrade > 150)
		throw Form::GradeTooLowException();
	if (exeGrade <= 0 || sigGrade <= 0)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), sig(false), sigGrade(other.sigGrade), exeGrade(other.exeGrade) {
	if (exeGrade > 150 || sigGrade > 150)
		throw Form::GradeTooLowException();
	if (exeGrade <= 0 || sigGrade <= 0)
		throw Form::GradeTooHighException();
}

Form& Form::operator=(const Form& other){
	(void)other;
	return (*this);
}

Form::~Form(){}

const std::string& Form::getName() const{
	return (name);
}

bool Form::getSig() const{
	return(sig);
}

int Form::getSigGrade() const{
	return (sigGrade);
}

int Form::getExeGrade() const{
	return (exeGrade);
}

bool Form::beSigned(const Bureaucrat& lento){
	if (sig == true)
		return false;
	if (lento.getGrade() <= this->getSigGrade())
	{
		sig = true;
		return (true);
	}
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}

/* const char* Form::FormNotSigned ::what() const throw(){	
	return ("Form has not been signed yet!");
} */

const char* Form::FormAlreadySigned ::what() const throw(){
	return ("Form has already been signed!");
}

std::ostream& operator<<(std::ostream& output, const Form& object){
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