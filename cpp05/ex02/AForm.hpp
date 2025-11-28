#pragma once

#include<iostream>
#include <sstream>

class Bureaucrat;

class AForm{
	const std::string name;
	bool sig;
	const int sigGrade;
	const int exeGrade;

	public:
	AForm();
	AForm(std:: string name, const int sigGrade, const int exeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool getSig() const;
	int getSigGrade() const;
	int getExeGrade() const;

	void beSigned(const Bureaucrat& lento);

	class GradeTooHighException : public std::exception{	
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char* what() const throw();
	};

	class FormNotSigned : public std::exception{	
		const char* what() const throw();
	};

	class FormAlreadySigned : public std::exception{
		const char* what() const throw();
	};

	//NEW STUFF
	virtual void execute(Bureaucrat const & executor) const  = 0; //return type?

	/*  implement a function to execute the form’s action in the concrete
	classes. You must check that the form is signed and that the grade of 
	the bureaucrat attempting to execute the form is high enough. 
	Otherwise, throw an appropriate exception */
};

std::ostream& operator<<(std::ostream& output, const AForm& object);
