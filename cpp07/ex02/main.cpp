#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750
#define GREEN "\033[32m"
#define STD "\033[0m"

int main(void){

	std::cout << GREEN << "EMPTY" << STD << std::endl;
	//empty array
	//this throws exception
	Array<double> random;
	try{
		std::cout << random[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "array with size and out of range exception" << STD << std::endl;

	Array<std::string> tt(2);
	try{
		std::string striiing = "this works";
		tt[0] = striiing;
		std::cout << tt[0] << std::endl;
		tt[1] = "this also works",
		std::cout << tt[1] << std::endl;
		tt[2] = "this throws exception",
		std::cout << tt[2] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << GREEN << "CONST ARRAY" << STD << std::endl;
	const Array<int> constant(5);
	for (unsigned int i = 0; i < constant.size(); i++)
    	std::cout << constant[i] << std::endl;



	std::cout << GREEN << "INT: operator[]" << STD << std::endl;
	Array<int> test(20);
	// int j = 20;
	for (unsigned int i = 0; i < test.size(); i++)
	{
		test[i] = i;
		std::cout << "i: " << i << "	arr:	" << test[i] << std::endl;
		//j++;
	}

	std::cout << GREEN << "CHAR: operator[]" << STD << std::endl;

	Array<char> abc(20);
	char a = 'a';
	for (unsigned int i = 0; i < abc.size(); i++)
	{
		abc[i] = a;
		std::cout << "i: " << i << "	arr:	" << abc[i] << std::endl;
		a++;
	}

	std::cout << GREEN << "STRING: operator[]" << STD << std::endl;

	Array<std::string> str(15);
	std::string ss = "a";
	char c = 'a';
	for (unsigned int i = 0; i < str.size(); i++)
	{
		str[i] = ss;
		std::cout << "i: " << i << "	arr:	" << abc[i] << std::endl;
		c++;
		a = a + c;
	}

}


/* 
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = i; //rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    Array<int> tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		if (test[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		if (tmp[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		std::cout << numbers[25 - 1] << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout << numbers[MAX_VAL - 1] << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */