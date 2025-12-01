#include<iostream>

class Bureaucrat;

class Form{
	const std::string name;
	bool sig;
	const int sigGrade;
	const int exeGrade;

	public:
	Form();
	Form(std:: string name, const int sigGrade, const int exeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

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

	class FormAlreadySignedException : public std::exception{
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& output, const Form& object);
