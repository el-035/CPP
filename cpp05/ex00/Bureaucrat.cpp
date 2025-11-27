#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150){	//wjat should i set?
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
}
Bureaucrat::Bureaucrat(const Bureaucrat& other){
	//
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other){
	if (this != &other)
	{
		//
	}

}

Bureaucrat::~Bureaucrat(){}

// const std::string& getName() const;
// int getGrade() const;
// void increment();
// void decrement();