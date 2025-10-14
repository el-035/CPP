#include "PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook agenda;

	while(true && std::cin)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, input);
		if (agenda.check_input(input) == false)
			break;
	}
}
