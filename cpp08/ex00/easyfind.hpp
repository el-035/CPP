#pragma once

#ifndef EASY
#define EASY

#include<iostream>

class NotFound : public std::exception{
	const char* what() const throw();
};

//PUT SOMEWHER ELSE
const char* NotFound::what() const throw(){
	return ("Value not found");
}


template<typename T>
typename T::const_iterator easyfind(const T& t, int n){
	for (typename T::const_iterator i = t.begin(); i != t.end(); ++i)
		if (*i == n)
			return (i);
	throw NotFound();
}




#include"easyfind.tpp"


#endif