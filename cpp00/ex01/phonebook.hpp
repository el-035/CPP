#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class Contact{
	int Index;
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	unsigned int PhoneNumber;
	std::string DarkestSecret;

	public:
	std::string get_first();
	std::string get_last();
	std::string get_nickname();
	std::string get_secret();
	unsigned int get_number();

	void set_first(int index);
	void set_last();
	void set_nickname();
	void set_secret();
	void set_number();
};

class PhoneBook{
	Contact agenda[8];
	void add_contact();
	void search_contact();

	public:
	bool check_input(std::string &input);
};

#endif