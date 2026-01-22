#include"BitcoinExchange.hpp"

bool validateDate(std::string& date){
	for(int i = 0; i < 10; i++){
		if ((i == 4 || i == 7) && date[i] != '-')
			return (std::cerr << BAD_FORM << std::endl, false);
		else
			continue;
		if (!isdigit(date[i]))
			return (std::cerr << BAD_FORM << std::endl, false);
	}
	std::string y = date.substr(0, 4);
	int year = atoi(y.c_str());
	if (year < 2009 || year > 2022)
		return (std::cerr << BAD_DATE << std::endl, false);

	std::string m = date.substr(5, 2);
	int month = atoi(m.c_str());
	if (month > 12 || month == 0)
		return (std::cerr << BAD_DATE << std::endl, false);
	
	std::string d = date.substr(8, 2);
	int day = atoi(d.c_str());
	if (day > 31 || day == 0)
		return (std::cerr << BAD_DATE << std::endl, false);
	if (month == 2 && isLeap(year) && day > 29)
		return (std::cerr << BAD_DATE << std::endl, false);
	else if (month == 2 && !isLeap(year) && day > 28)
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
	if (dot == 0 && value.length() > 4)
		return (std::cerr << BAD_VALUE << std::endl, false);

	float n = atof(value.c_str());
	if (n > 1000)
		return (std::cerr << BAD_VALUE << std::endl, false);
	double nn = atof(value.c_str());
	if (nn > 1000.0)
		return (std::cerr << BAD_VALUE << std::endl, false);
	return true;
}

bool checkInputFormat(std::string& line){
	std::string date = line.substr(0, 10);
	if (!validateDate(date))
		return false;
	
	std::string sep = line.substr(10, 3);
	if (sep != " | ")
		return (std::cerr << BAD_FORM << std::endl, false);
	
	std::string value = line.substr(13);
	if (!validateValue(value))
		return false;

	std::cout << date << " -> " << value << " = ";
	return true;
}

bool mapData(std::map<std::string, float> *data){
	std::ifstream datafile("data.csv");
	
	//file does not exist/cannot be open
	if (!datafile.is_open())
		return (std::cerr << ERR_OPEN << std::endl, false);
	
	//file empty
	datafile.seekg(0, std::ios::end);
	if (datafile.tellg() == 0)
		return (std::cerr << ERR_EMPTY << std::endl, false);
	datafile.seekg(0, std::ios::beg);

	//check first line
	std::string line;
	std::getline(datafile, line);

	//check rest
	std::string value;
	while (std::getline(datafile, line)){
		value = line.substr(11);
		data->insert(std::pair<std::string, float>(line.substr(0, 10), atof(value.c_str())));
	}
	return true;
}

void searchDate(std::map<std::string, float> *data, std::string line){
	std::string date = line.substr(0, 10);
	std::string value = line.substr(13);
	float n = atof(value.c_str());

	std::map<std::string, float>::const_iterator it = data->find(date);
	if (it != data->end()){
		std::cout << it->second * n << std::endl;
	}
	else{
		for(it = data->begin(); it != data->end(); it++){
			if (date < it->first){
				it--;
				std::cout << it->second * n << std::endl;
				break ;
			}
		}
	}
}

bool inputValidationSearch(std::map<std::string, float> *data, char *input){
	std::ifstream file(input);
	std::string line;
	std::getline(file, line);
	
	if (line != "date | value")
		return (std::cerr << ERR_HEAD << std::endl, false);
	while(std::getline(file, line)){
		if (!checkInputFormat(line))
			continue ;
		searchDate(data, line);
	}
	return true;
}