#pragma once

#include<iostream>

class Bureaucrat{
	const std::string name;
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void increment();
	void decrement();
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& object);
