#include"Span.hpp"

Span::Span(): N(0){}

Span::Span(unsigned int n) : N(n) {
	numb.reserve(n);
}

Span::Span(const Span& other) : N(other.getMaxSize()), numb(other.numb){}

Span& Span::operator=(const Span& other){
	if (this != &other){
		N = other.N;
		numb = other.numb;
	}
	return (*this);
}

Span::~Span(){}

unsigned int Span::getMaxSize() const{
	return (N);
}

void Span::addNumber(int num){
	try{
		if (numb.size() >= N)
			throw FullSpan();
		numb.push_back(num);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan(){
	if(numb.size() < 2)
		throw SpanNotFound();
	std::vector<int> temp(numb);
	std::sort(temp.begin(), temp.end());
	int prev = this->longestSpan();
	for(std::vector<int>::const_iterator it = temp.begin(); it != (temp.end() - 1); it++){
		int diff = *(it + 1) - *it;
		prev = std::min(diff, prev);
	}
	return (prev);
}

int Span::longestSpan(){
	if(numb.size() < 2)
		throw SpanNotFound();
	std::vector<int>::const_iterator highest = std::max_element(numb.begin(), numb.end());
	std::vector<int>::const_iterator lowest = std::min_element(numb.begin(), numb.end());
	int res = *highest - *lowest;
	return (res);
}

void Span::addNumber(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end){
	try{
		for (std::vector<int>::const_iterator it = start; it != end; ++it){
			if (numb.size() >= N)
				throw FullSpan();
			numb.push_back(*it);
		}
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

const char* Span::FullSpan::what() const throw(){
	return ("Cannot add number to a full span");
}

const char* Span::SpanNotFound::what() const throw(){
	return ("Span could not be found");
}

