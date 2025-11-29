#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Anonym Bureaucrat"), grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	(void)other;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
}

const std::string& Bureaucrat::getName() const{
	return (name);
}

int Bureaucrat::getGrade() const{
	return(grade);
}
void Bureaucrat::increment(){
	grade -= 1;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement(){
	grade += 1;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& object){
	int n = object.getGrade();
	std::stringstream ss;
	ss << n;
	std::string s = object.getName() + ", bureaucrat grade " + ss.str() + ".";
	output << s;
	return (output);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}

void Bureaucrat::signForm(Form& carta){
	try
	{
		if (carta.beSigned(*this))
			std::cout << this->getName() << " signed " << carta.getName() << std::endl;
		else
			throw Form::FormAlreadySignedException();
	}
	catch(const std::exception& e)
	{
		std::cout <<  this->getName() << " couldn't sign " << carta.getName() << " because: ";
		std::cout << e.what() << std::endl;
	}	
}
