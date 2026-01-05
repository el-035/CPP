#ifndef RPN
#define RPN

#include"iostream"
#include<stack>

bool isOperand(char c);
bool validExpr(std::string& input);
int operation(std::stack<int> *rpn, char o, int x);
void execExpr(std::string& expr);


#endif