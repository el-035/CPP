#include "ScalarConverter.hpp"

//PUT BACK THE FLAGSSSS

/* int main (void)
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

} */
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


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>


struct TestCase {
    std::string input;
    std::string expected_output;
};

int main() {
    std::vector<TestCase> tests = {
        // Normal cases
        {"0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"},
        {"42", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"},
        {"a", "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n"},
        {"A", "char: 'A'\nint: 65\nfloat: 65.0f\ndouble: 65.0\n"},
        {"3.14", "char: Non displayable\nint: 3\nfloat: 3.1f\ndouble: 3.14\n"},
        {"-7", "char: Non displayable\nint: -7\nfloat: -7.0f\ndouble: -7.0\n"},
        {"127", "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0\n"},
        {"32", "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0\n"},
        {"33", "char: '!'\nint: 33\nfloat: 33.0f\ndouble: 33.0\n"},
        {"255", "char: impossible\nint: 255\nfloat: 255.0f\ndouble: 255.0\n"},

        // Edge cases
        {"nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"},
        {"+inf", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"},
        {"-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"},
        {"", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"2147483647", "char: Non displayable\nint: 2147483647\nfloat: 2147483647.0f\ndouble: 2147483647.0\n"},
        {"-2147483648", "char: Non displayable\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0\n"},
        {"1e10", "char: impossible\nint: impossible\nfloat: 10000000000.0f\ndouble: 10000000000.0\n"},
        {"-1e10", "char: impossible\nint: impossible\nfloat: -10000000000.0f\ndouble: -10000000000.0\n"},
        {"42.0", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"},
        {"0.0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n"},
        {"-0.0", "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n"},
        {"a1", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"!", "char: '!'\nint: 33\nfloat: 33.0f\ndouble: 33.0\n"},
        {"~", "char: '~'\nint: 126\nfloat: 126.0f\ndouble: 126.0\n"},
        {"\n", "char: Non displayable\nint: 10\nfloat: 10.0f\ndouble: 10.0\n"},
        {" ", "char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0\n"},
        {"\t", "char: Non displayable\nint: 9\nfloat: 9.0f\ndouble: 9.0\n"},
        {"999999999999", "char: impossible\nint: impossible\nfloat: 1000000000000.0f\ndouble: 999999999999.0\n"},
        {"-999999999999", "char: impossible\nint: impossible\nfloat: -1000000000000.0f\ndouble: -999999999999.0\n"},
        {"2.71828", "char: Non displayable\nint: 2\nfloat: 2.7f\ndouble: 2.71828\n"},
        {"1.0f", "char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.0\n"},
        {"-1.0f", "char: Non displayable\nint: -1\nfloat: -1.0f\ndouble: -1.0\n"},
        {"+42", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"},
        {"-42", "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n"},
        {"0x2A", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"077", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"abc", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"++1", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"--1", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"123abc", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"},
        {"42.", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n"},
        {".42", "char: Non displayable\nint: 0\nfloat: 0.4f\ndouble: 0.42\n"},
        {"0.0001", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0001\n"},
        {"-0.0001", "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0001\n"},
        {"3.4028235e38", "char: impossible\nint: impossible\nfloat: 3.40282e+38f\ndouble: 3.4028235e+38\n"},
        {"-3.4028235e38", "char: impossible\nint: impossible\nfloat: -3.40282e+38f\ndouble: -3.4028235e+38\n"},
        {"1.7976931348623157e308", "char: impossible\nint: impossible\nfloat: impossible\ndouble: 1.7976931348623157e+308\n"},
        {"-1.7976931348623157e308", "char: impossible\nint: impossible\nfloat: impossible\ndouble: -1.7976931348623157e+308\n"},
        {"inf", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"},
        {"-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n"},
        {"nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n"},
        {"7e-10", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 7e-10\n"},
        {"-7e-10", "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -7e-10\n"},
        {"127.0", "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0\n"},
        {"128.0", "char: impossible\nint: 128\nfloat: 128.0f\ndouble: 128.0\n"},
        {"31.0", "char: Non displayable\nint: 31\nfloat: 31.0f\ndouble: 31.0\n"},
        {"126.0", "char: '~'\nint: 126\nfloat: 126.0f\ndouble: 126.0\n"},
        {"-128", "char: impossible\nint: -128\nfloat: -128.0f\ndouble: -128.0\n"},
        {"non-numeric", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n"}
    };

    int i = 1;
    for (auto &t : tests) {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); // redirect cout

        ScalarConverter::convert(t.input); // call your convert

        std::cout.rdbuf(old); // restore cout
        std::string output = buffer.str();

        if (output == t.expected_output)
            std::cout << "test " << i << " OK\n";
        else {
            std::cout << "test " << i << " KO\n";
            std::cout << "Input: \"" << t.input << "\"\n";
            std::cout << "Expected:\n" << t.expected_output;
            std::cout << "Got:\n" << output;
        }
        i++;
    }
    return 0;
}
