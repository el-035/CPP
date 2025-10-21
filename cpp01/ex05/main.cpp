#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		harl.complain(levels[i]);
		std::cout << std::endl;
	}

	harl.complain(levels[2]);
	std::cout << std::endl;

	harl.complain("HOLA");
}