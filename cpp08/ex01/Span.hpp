#pragma once

#ifndef SPAN
#define SPAN

#include<iostream>
#include<vector>
#include<algorithm>

class Span{
	unsigned int N;
	std::vector<int> numb;

	public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	void addNumber(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);

	class FullSpan : public std::exception{
		const char* what() const throw();
	};
	class SpanNotFound : public std::exception{
		const char* what() const throw();
	};
};

#endif