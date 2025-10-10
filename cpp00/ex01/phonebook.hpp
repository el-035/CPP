#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

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

	void display_line(std::string data, bool last);
	bool validate_alpha(std::string data);
	bool validate_num(std::string data);
	void set_first(int index);
	void set_last();
	void set_nickname();
	void set_secret();
	void set_number();
};

class PhoneBook{
	Contact agenda[8];
	void add_contact();
	
	public:
	void search_contact();
	bool check_input(std::string &input);
};

#endif