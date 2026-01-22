#ifndef RPN
#define RPN

#include"iostream"
#include<stack>

bool validExpr(std::string& input);
void execExpr(std::string& expr);

class Operation{
	long long a;
	long long b;
	char sign;

	public:
	Operation(long long a, long long b, char s);
	Operation(const Operation& other);
	Operation& operator=(const Operation& other);
	~Operation();

	long long operation();
	static bool isOperand(char c);
};

#endif