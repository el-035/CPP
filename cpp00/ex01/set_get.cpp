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
	std::cout << "first name added: " << FirstName << " contact n: " << Index << std::endl;
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
	std::cout << "last name added: " << LastName << std::endl;
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
	std::cout << "nickname added: " << Nickname << std::endl;
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
	std::cout << "secret added: " << DarkestSecret << std::endl;
}

void Contact::set_number()
{
	std::string input;
	unsigned int number;

	while (input.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		//convert to unsigned int
		std::cout << number << std::endl;
	}
}