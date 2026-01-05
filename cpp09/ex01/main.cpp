#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2)
		return(std::cerr << "Error" << std::endl, -1);
	std::string expr = argv[1];
	if (!validExpr(expr))
		return -1;
	execExpr(expr);	
}
