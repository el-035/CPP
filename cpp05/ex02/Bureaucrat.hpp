#pragma once

#include<iostream>
#include<sstream>
#include<exception>
//#include"Form.hpp"

#define S_RED "\033[31m"
#define E_RED "\033[0m"


class AForm;

class Bureaucrat{
	const std::string name;
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void increment();
	void decrement();
	void signForm(AForm& carta);

	class GradeTooHighException : public std::exception{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char* what() const throw();
	};

	//NEW STUFF
	void executeForm(AForm const & form) const; //return type?
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& object);
