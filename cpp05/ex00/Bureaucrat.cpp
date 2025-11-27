#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(75){	//wjat should i set?
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){
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
}

void Bureaucrat::decrement(){
	grade += 1;
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& object){
	int n = object.getGrade();
	std::stringstream ss;
	ss << n;
	std::string s = object.getName() + ", bureaucrat grade " + ss.str() + ".";
	output << s;
	return (output);
}