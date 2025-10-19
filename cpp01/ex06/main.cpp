#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2){
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return -1;
	}
	std::string input = argv[1];

	harl.complain(input);
}