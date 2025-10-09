#include <iostream>

void print_louder(std::string word)
{
	for (int i = 0; word[i]; i++)	//check if not ascii input not valid Ü
		std::cout << (char)std::toupper(word[i]);
}

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; i++)
			print_louder(argv[i]);
	}
	std::cout << std::endl;
}