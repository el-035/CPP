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

bool validateDate(std::string& date){
	for(int i = 0; i < 10; i++){
		if ((i == 4 || i == 7) && date[i] != '-')
			return (std::cerr << BAD_FORM << std::endl, false);
		else
			continue;
		if (!isdigit(date[i]))
			return (std::cerr << BAD_FORM << std::endl, false);
	}

	std::string m = date.substr(5, 6);

	int month = atoi(m.c_str());
//	std::cout << "month" << month << std::endl;
	if (month > 12 || month == 0)
		return (std::cerr << BAD_DATE << std::endl, false);
	
	std::string d = date.substr(8, 9);
//	std::cout << "day" << d << std::endl;

	int day = atoi(d.c_str());
//	std::cout << day << std::endl;
	if (day > 31 || day == 0)
		return (std::cerr << BAD_DATE << std::endl, false); //
	if (month == 2 && day > 29)
		return (std::cerr << BAD_DATE << std::endl, false);
	else if ((month == 11 || month == 4 || month == 6 || month == 9) && day > 30)
		return (std::cerr << BAD_DATE << std::endl, false);
	return true;
}

bool validateValue(std::string& value){
	int dot = 0;
	for (size_t i = 0; i < value.length(); i++){
		if (value[i] == '.' && i != value.length() - 1)
			dot++;
		else if (!isdigit(value[i]))
			return (std::cerr << BAD_FORM << std::endl, false);
	}
	if (dot > 1)
		return (std::cerr << BAD_FORM << std::endl, false);
	return true;

}

bool checkLineFormat(std::string& line){
	std::string temp;
	temp = line.substr(0, 10);
	if (!validateDate(temp))
		return false;
	if (line[10] != ',')
		return (std::cerr << BAD_FORM << std::endl, false);
	temp = line.substr(11);
	if (!validateValue(temp))
		return false;
	return true;
}

bool mapData(std::map<std::string, double> *data){
	std::ifstream datafile("data.csv");
	
	//file does not exist/cannot be open
	if (!datafile.is_open())
		return (std::cerr << ERR_OPEN << std::endl, false);
	
	//file empty
	datafile.seekg(0, std::ios::end);
	if (datafile.tellg() == 0)
		return (std::cerr << ERR_EMPTY << std::endl, false);
	datafile.seekg(0, std::ios::beg);

	//check first line --bad header
	std::string line;
	std::getline(datafile, line);

	if (line != "date,exchange_rate")
		return (std::cerr << ERR_HEAD << std::endl, false);
	
	//check rest
	std::string value;
	while (std::getline(datafile, line)){
		//format check
		if (!checkLineFormat(line))
			return false;
		//map
		value = line.substr(11);
		data->insert(std::pair<std::string, double>(line.substr(0, 10), atof(value.c_str())));
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
	if (!mapData(&data))
		return -1;
	
	//test print
	std::map<std::string, double>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it){
		std::cout << it->first << "," << it->second << std::endl;
	}

	//input check line by line
}