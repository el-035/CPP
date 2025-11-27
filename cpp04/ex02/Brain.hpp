#pragma once

#include <iostream>

class Brain{
	std::string ideas[100];
	
	public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void setIdeas(int i, std::string idea);
	std::string getideas(int i);
};