#include "RPN.hpp"

Operation::Operation(int a, int b, char s) : a(a), b(b), sign(s) {}

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

int Operation::operation(){
	if (sign == '+')
		return(a + b);
	else if (sign == '-')
		return(a - b);
	else if (sign == '/')
		return(a / b);
	else
		return(a * b);
}


bool Operation::checkOp(){
	int res;
	long long check;
	if (sign == '+'){
		res = a + b;
		check = static_cast<long long>(a) + static_cast<long long>(b);
	}
	else if (sign == '-'){
		res = a - b;
		check = static_cast<long long>(a) - static_cast<long long>(b);
	}
	else if (sign == '/'){
		res = a / b;
		check = static_cast<long long>(a) / static_cast<long long>(b);
	}
	else{
		res = a * b;
		check = static_cast<long long>(a) * static_cast<long long>(b);
	}
	if (static_cast<long long>(res) != check)
		return (std::cerr << "Error: int overflow" << std::endl, false);
	return true;
}
