#include "ScalarConverter.hpp"


int main (void)
{
	std::string cv;

	cv = "0";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "-2147483648";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "2147483647";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "2147483648";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "hallo";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "x";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "-15";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "41";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "41.41";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "41.41f";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "0";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "0.0f";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "0.0";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "nan";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "+inf";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

	cv = "-inff";
	std::cout << "convert: " << cv << std::endl;
	ScalarConverter::convert(cv);
	std::cout << std::endl;

}
/* int main(int argc, char **argv){
	if (argc != 2)
	{
		std::cout << "Input error" << std::endl;
		return -1;
	}
	ScalarConverter::convert(argv[1]);

} */

/* int main(void)
{
	std::string input;

	while(true && std::cin)
	{
		std::cout << "Enter string to convert: ";
		std::getline(std::cin, input);
		ScalarConverter::convert(input);
	}
} */