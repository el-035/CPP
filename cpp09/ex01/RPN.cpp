#include "RPN.hpp"

Operation::Operation(long long a, long long b, char s) : a(a), b(b), sign(s) {}

Operation::Operation(const Operation& other) : a(other.a), b(other.b), sign(other.sign){}
	
Operation& Operation::operator=(const Operation& other){
	if (this != &other){
		a = other.a;
		b = other.b;
		sign = other.sign;
	}
	return (*this);
}

Operation::~Operation() {}

bool Operation::isOperand(char c){
	if (c == '+' || c == '*' || c == '/' || c == '-')
		return true;
	return false;
}

long long Operation::operation(){
	if (sign == '+')
		return (a + b);
	else if (sign == '-')
		return (a - b);
	else if (sign == '/')
		return (a / b);
	else
		return (a * b);
}

