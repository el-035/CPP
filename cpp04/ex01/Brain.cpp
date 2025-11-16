#include"Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other){
	std::cout << "Brain copy constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdeas(int i, std::string idea){
	ideas[i] = idea;
}

std::string Brain::getideas(int i){
	return (ideas[i]);
}
