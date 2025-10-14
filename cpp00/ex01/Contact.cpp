#include "PhoneBook.hpp"

void Contact::display_line(std::string data, bool last)
{
	if (data.empty())
		return ;
	if (data.size() > 10)
		std::cout << data.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << data;
	if (!last)
		std::cout <<  "|";
	else
		std::cout << std::endl;
}

bool Contact::validate_alpha(std::string data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		if (!std::isalpha(data[i]))
			return false;
	}
	return true;
}

bool Contact::validate_num(std::string data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		if (!std::isdigit(data[i]))
			return false;
	}
	return true;
}

void Contact::set_first()
{
	std::string input;

	while (input.empty() && std::cin)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (!validate_alpha(input))
		{
			std::cout << "Only letters allowed. ";
			input.clear();
		}
	}
	FirstName = input;
}

void Contact::set_last()
{
	std::string name;

	while (name.empty() && std::cin)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, name);
		if (!validate_alpha(name))
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

	while (name.empty() && std::cin)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, name);
		if (!validate_alpha(name))
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

	while (secret.empty() && std::cin)
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

	while (input.empty() && std::cin)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (!validate_num(input))
		{
			std::cout << "Only digits allowed. ";
			input.clear();
			continue;
		}
		std::stringstream ss(input);
		if (!(ss >> number) || !ss.eof())
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