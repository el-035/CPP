#include "phonebook.hpp"

bool PhoneBook::check_input(std::string &input)
{
	if (input == "ADD")
		add_contact();
	else if (input == "SEARCH")
		search_contact();
	else if (input == "EXIT")
		return false;
	return true;
}

void PhoneBook::search_contact()
{

}

void PhoneBook::add_contact()
{
	static int index = 0;

	agenda[index].set_first(index);
	agenda[index].set_last();
	agenda[index].set_nickname();
	agenda[index].set_secret();
	//agenda[index].set_number();

	index++;
	if (index == 8)
		index = 0;
}



int main(void)
{
	std::string input;
	PhoneBook agenda;

	while(true && std::cin) //why?
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): "; // enter and ctrl d
		std::getline(std::cin, input);
		//std::cin >> input;
		/* if (std::cin.eof())
			break; */
			//std::cout<< "here\n";
		//std::cin.ignore();
		if (agenda.check_input(input) == false)
			break;
	}
}
