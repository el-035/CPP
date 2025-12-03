#pragma once

#ifndef BASE
#define BASE

#include<iostream>

class Base{
	public:
	virtual ~Base();
} ;

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif