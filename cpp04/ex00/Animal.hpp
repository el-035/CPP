#pragma once

#include<iostream>

class Animal{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();

	virtual void makeSound() const;
	std::string getType() const;
};