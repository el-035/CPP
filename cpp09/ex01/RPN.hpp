#ifndef RPN
#define RPN

#include"iostream"
#include<stack>

//bool isOperand(char c);
bool validExpr(std::string& input);
//int operation(std::stack<int> *rpn, char o, int x);
void execExpr(std::string& expr);

class Operation{
	int a;
	int b;
	char sign;

	public:
	Operation(int a, int b, char s);
	Operation(const Operation& other);
	Operation& operator=(const Operation& other);
	~Operation();

	int operation();
	static bool isOperand(char c);
};

#endif