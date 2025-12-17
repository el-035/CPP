#pragma once

#ifndef EASY
#define EASY

#include<iostream>
#include<algorithm>

class NotFound : public std::exception{
	const char* what() const throw();
};

#include"easyfind.tpp"

#endif