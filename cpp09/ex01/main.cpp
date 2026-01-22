#include "RPN.hpp"

bool validExpr(std::string& input){
	int depth = 0;
	for (size_t i = 0; i < input.length(); i++){
		if (i % 2 == 0 && (!isdigit(input[i]) && !Operation::isOperand(input[i])))
			return(std::cerr << "Error" << std::endl, false);
		if (i % 2 != 0 && input[i] != ' ')
			return(std::cerr << "Error" << std::endl, false);
		if (isdigit(input[i]))
			depth++;
		else if (Operation::isOperand(input[i]) && depth < 2)
			return(std::cerr << "Error" << std::endl, false);
		else if (Operation::isOperand(input[i]))
			depth--;
	}
	if (depth != 1)
		return(std::cerr << "Error" << std::endl, false);
	return true;
}

void execExpr(std::string& expr){
	std::stack <long long> rpn;
	int b;
	for (size_t i = 0; i < expr.length(); i++){
		if(isdigit(expr[i]))
			rpn.push(expr[i] - 48);
		else if (Operation::isOperand(expr[i])){
			b = rpn.top();
			rpn.pop();
			Operation data(rpn.top(), b, expr[i]);
			rpn.pop();
			rpn.push(data.operation());
		}
		else if (expr[i] == ' ')
			continue ;
	}
	std::cout << rpn.top() << std::endl;
}

int main(int argc, char **argv){
	if (argc != 2)
		return(std::cerr << "Error" << std::endl, -1);
	std::string expr = argv[1];
	if (!validExpr(expr))
		return -1;
	execExpr(expr);	
}
