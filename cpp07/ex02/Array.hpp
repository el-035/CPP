#pragma once

#ifndef ARRAY
#define ARRAY

#include<iostream>

template <typename T>

class Array{
	T *arr;
	unsigned int s;

	public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T& operator[](unsigned int n);

	unsigned int size() const;

	class OutOfRange : public std::exception{
		const char* what() const throw();};
};

#include "Array.tpp"

#endif