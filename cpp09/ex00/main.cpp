#include"BitcoinExchange.hpp"

bool checkInput(char* input){
	std::ifstream file(input);

	if (!file.is_open())
		return (std::cerr << ERR_OPEN << std::endl, false);

	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		return (std::cerr << ERR_EMPTY << std::endl, false);
	file.seekg(0, std::ios::beg);
	return true;
}

bool isLeap(int year){
	if (year % 400 == 0)
		return true;
	else if ((year % 4 == 0) && (year % 100 != 0))
		return true;
	return false;
}

int main(int argc, char **argv){
	if (argc != 2)
		return (std::cerr << ERR_INPUT << std::endl, -1);
	if (!checkInput(argv[1]))
		return (-1);
	std::map<std::string, float> data;
	if (!mapData(&data))
		return -1;
	inputValidationSearch(&data, argv[1]);
}
