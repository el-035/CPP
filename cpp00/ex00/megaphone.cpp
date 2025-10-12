#include <iostream>

void print_louder(const std::string &word)
{
	for (int i = 0; i < word.size(); i++)
		std::cout << (char)std::toupper(word[i]);
}

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			print_louder(argv[i]);
	}
	std::cout << std::endl;
}