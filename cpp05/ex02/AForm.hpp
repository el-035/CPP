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

	bool beSigned(const Bureaucrat& lento);

	class GradeTooHighException : public std::exception{	
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception{	
		const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception{
		const char* what() const throw();
	};

	virtual void execute(Bureaucrat const & executor) const  = 0;
};

std::ostream& operator<<(std::ostream& output, const AForm& object);
