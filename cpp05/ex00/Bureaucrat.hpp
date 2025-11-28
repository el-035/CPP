#pragma once

#include<iostream>
#include<sstream>
#include<exception>

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

	class GradeTooHighException : public std::exception{	
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& object);
