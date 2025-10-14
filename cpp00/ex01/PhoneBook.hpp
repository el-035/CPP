#pragma once

#include "Contact.hpp"

class PhoneBook{
	Contact agenda[8];
	void add_contact();
	void search_contact();
	
	public:
	bool check_input(std::string &input);
};
