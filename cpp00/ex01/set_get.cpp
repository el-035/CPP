#include "phonebook.hpp"

void Contact::set_first(int index)
{
	std::string input;

	while (input.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		//CHECK INPUT ALPHA
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
		//CHECK INPUT ALPHA
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
		//CHECK INPUT ALPHA
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
		//CHECK INPUT ALPHA
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
		//if ()
		std::stringstream ss(input);
		ss >> number;
		std::cout << number << std::endl;
	}
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
/* unsigned int Contact::get_number()
{
	return (PhoneNumber);
} */