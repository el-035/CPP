#pragma once

#include<iostream>
#include"AForm.hpp"

class Intern{
	public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	
	AForm* makeForm(const std::string& form, const std::string& target);
	static AForm* Shrubbery(const std::string& target);
	static AForm* Robotomy(const std::string& target);
	static AForm* Presidential(const std::string& target);

	class FormNameNotFound : public std::exception{
		const char *what() const throw();
	};

};