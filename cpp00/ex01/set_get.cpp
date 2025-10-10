#include "phonebook.hpp"

bool Contact::validate_input(std::string data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		if (!std::isalpha(data[i]))
			return false;
	}
	return true;
}

void Contact::set_first(int index)
{
	std::string input;

	while (input.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (!validate_input(input))
		{
			std::cout << "Only letters allowed. ";
			input.clear();
		}
	}
	FirstName = input;
	Index = index;
}

void Contact::set_last()
{
	std::string name;

	while (name.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, name);
		if (!validate_input(name))
		{
			std::cout << "Only letters allowed. ";
			name.clear();
		}
	}
	LastName = name;
}

void Contact::set_nickname()
{
	std::string name;

	while (name.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, name);
		if (!validate_input(name))
		{
			std::cout << "Only letters allowed. ";
			name.clear();
		}
	}
	Nickname = name;
}

void Contact::set_secret()
{
	std::string secret;

	while (secret.empty())
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, secret);
	}
	DarkestSecret = secret;
}

void Contact::set_number()
{
	std::string input;
	unsigned int number;

	while (input.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		std::stringstream ss(input);
		if (!(ss >> number) || !ss.eof())	//shoule i check for negatives?
		{
			input.clear();
			number = 0;
			std::cout << "Number invalid or too long. ";
		}
	}
	PhoneNumber = number;
}

std::string Contact::get_first()
{
	return (FirstName);
}
std::string Contact::get_last()
{
	return (LastName);
}
std::string Contact::get_nickname()
{
	return (Nickname);
}
std::string Contact::get_secret()
{
	return (DarkestSecret);
}
unsigned int Contact::get_number()
{
	return (PhoneNumber);
}