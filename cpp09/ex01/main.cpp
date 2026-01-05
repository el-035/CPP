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
		else if (isOperand(input[i]))
			depth--;
	}
	if (depth != 1)
		return(std::cerr << "Error" << std::endl, false);
	return true;
}

void execExpr(std::string& expr){
	
}

int main(int argc, char **argv){
	if (argc != 2)
		return(std::cerr << "Error" << std::endl, -1);
	std::string expr = argv[1];
	if (!validExpr(expr))
		return -1;
		
}
