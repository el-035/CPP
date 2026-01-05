#include "RPN.hpp"

bool isOperand(char c){
	if (c == '+' || c == '*' || c == '/' || c == '-')
		return true;
	return false;
}

bool validExpr(std::string& input){
	int depth = 0;
	for (size_t i = 0; i < input.length(); i++){
		if (i % 2 == 0 && (!isdigit(input[i]) && !isOperand(input[i])))
			return(std::cerr << "Error" << std::endl, false);
		if (i % 2 != 0 && input[i] != ' ')
			return(std::cerr << "Error" << std::endl, false);
		if (isdigit(input[i]))
			depth++;
		else if (isOperand(input[i]) && depth < 2)
			return(std::cerr << "Error" << std::endl, false);
		else if (isOperand(input[i]))
			depth--;
	}
	if (depth != 1)
		return(std::cerr << "Error" << std::endl, false);
	return true;
}

int operation(std::stack<int> *rpn, char o, int x){
	if (o == '+')
		return (rpn->top() + x);
	else if (o == '-')
		return (rpn->top() - x);
	else if (o == '/')
		return (rpn->top() / x);
	else
		return (rpn->top() * x);
}

void execExpr(std::string& expr){
	std::stack <int> rpn;
	int x;
	for (size_t i = 0; i < expr.length(); i++){
		if(isdigit(expr[i]))
			rpn.push(expr[i] - 48);
		else if (isOperand(expr[i])){
			x = rpn.top();
			rpn.pop();
			x = operation(&rpn, expr[i], x);
			rpn.pop();
			rpn.push(x);
		}
		else if (expr[i] == ' ')
			continue ;
	}
	std::cout << rpn.top() << std::endl;
}