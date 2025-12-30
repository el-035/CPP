#include"BitcoinExchange.hpp"

bool checkInput(char* input){
	std::ifstream file(input);

	if (!file.is_open())
		return (std::cerr << ERR_OPEN << std::endl, false);

	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		return (std::cerr << ERR_EMPTY << std::endl, false);
	return true;
}

bool checkLineFormat(std::string){
	
	//line by line
		//first 10 char date -- date err
			//YYYY-MM-DD (month 1-12 etc) 
		//coma
		//is double, >=0 --value err
		//anything else format error
}

bool mapData(std::map<std::string, double> &data){
	std::ifstream datafile("data.csv");
	
	//file does not exist/cannot be open
	if (!datafile.is_open())
		return (std::cerr << ERR_OPEN << std::endl, false);
	
	//file empty
	datafile.seekg(0, std::ios::end);
	if (datafile.tellg() == 0)
		return (std::cerr << ERR_EMPTY << std::endl, false);
	
	//check first line --bad header
	std::string line;
	std::getline(datafile, line);
	if (line != "date,exchange_rate")
		return (std::cerr << ERR_HEAD << std::endl, false);
	while (std::getline(datafile, line)){
		//format check

		//map
	}


	return true;
}


//check without permissions
int main(int argc, char **argv){
	if (argc != 2)
		return (std::cerr << ERR_INPUT << std::endl, -1);
	if (!checkInput(argv[1]))
		return (-1);
	std::map<std::string, double> data;
	mapData(data);
	//map data
		//open and check csv (open, empty)
		//check format while parsing

	//input check line by line
}