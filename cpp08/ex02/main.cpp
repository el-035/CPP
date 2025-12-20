#include"MutantStack.hpp"
#include<list>
#include<algorithm>

/* int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
} */

/* int main()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
	return 0;
} */

int main(void){
	MutantStack<std::string> test;

	test.push("wtf");
	test.push("culo");
	test.push("hola");
	test.push("como");
	test.push("42");
	test.push("stupid");
	test.push("tests");

	//print in order
	for (MutantStack<std::string>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	//sort and print in alpha order
	std::cout << std::endl;
	std::sort(test.begin(), test.end());
	for (MutantStack<std::string>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	//sort and print in reverse order
	std::reverse(test.begin(), test.end());
	for (MutantStack<std::string>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
}