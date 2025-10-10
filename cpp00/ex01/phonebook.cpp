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

void Contact::display_line(std::string data, bool last)
{
	if (data.empty())
		return ;
	if (data.size() > 10)
		std::cout << data.substr(0, 9) << ".";
	else
	{
		for (size_t i = 0; i < 10 - data.size(); i++)
			std::cout << ' ';
		std::cout << data;
	}
	if (!last)
		std::cout <<  "|";
	else
		std::cout << std::endl;
}

void PhoneBook::search_contact()
{
	int index = 0;

	if (agenda[index].get_first().empty())
	{
		std::cout << "Agenda is empty, add contacts first!" << std::endl;
		return ;
	}
	//display contacts
	agenda[index].display_line("INDEX", false);
	agenda[index].display_line("FIRST NAME", false);
	agenda[index].display_line("LAST NAME", false);
	agenda[index].display_line("NICKNAME", true);

	while(index < 8)
	{
		if (!agenda[index].get_first().empty())
			std::cout << "         " << index << "|";
		agenda[index].display_line(agenda[index].get_first(), false);
		agenda[index].display_line(agenda[index].get_last(), false);
		agenda[index].display_line(agenda[index].get_nickname(), true);
		index++;
	}

	//ask for index
	std::string input;
	std::cout << "Enter contact index for more info: ";
	std::getline(std::cin, input);
	std::stringstream ss(input);

	if (!(ss >> index) || !ss.eof() || (index < 0 || index > 7) || agenda[index].get_first().empty())
	{
		std::cout << "Invalid or empty contact info requested" << std::endl;
		return;
	}

	//show contact
	std::cout << "First name: " << agenda[index].get_first() << std::endl << "Last Name: " << agenda[index].get_last() << std::endl;
	std::cout << "Nickname: " << agenda[index].get_nickname() << std::endl << "Phone number: " << agenda[index].get_number() << std::endl;
	std::cout << "Darkest Secret: " << agenda[index].get_secret() << std::endl;
}

void PhoneBook::add_contact()
{
	static int index = 0;

	agenda[index].set_first(index);
	agenda[index].set_last();
	agenda[index].set_nickname();
	agenda[index].set_secret();
	agenda[index].set_number();

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
		if (agenda.check_input(input) == false)
			break;
	}
}
