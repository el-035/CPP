#include <iostream>

int main(void)
{
	std::string stringSTR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringSTR;
	std::string& stringREF = stringSTR;

	std::cout << "stringSTR address: " << &stringSTR << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "stringSTR value: " << stringSTR << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;

}