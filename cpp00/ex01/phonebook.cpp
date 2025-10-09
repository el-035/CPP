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
	std::string input;
	
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	
	agenda[index].set_first(input, index);

	if (index++ == 8) //segfaukt :(
		index = 0;
}

void Contact::set_first(std::string &name, int index)
{
	FirstName = name;
	Index = index;
	std::cout << "first name added: " << FirstName << " contact n: " << Index << std::endl;
}

int main(void)
{
	std::string input;
	PhoneBook agenda;

	while(true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): "; // enter and ctrl d
		//std::getline(std::cin, input);
		std::cin >> input;
		std::cin.ignore();
		if (agenda.check_input(input) == false)
			break;
	}
}