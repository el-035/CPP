#include <fstream>
#include <iostream>
#include <string>

bool CheckInput(std::string &filename, std::string &s1, std::string &s2)
{
	std::ifstream file(filename);

	if (!file.is_open())
		return false;
	if (s1.empty())
		return false;
	return true;
}

void replace(std::string& line, std::string& s1, std::string& s2)
{
	std::string* r;

	while(true){
		r = std::find(line, line.size(), s1);

	}
}

void ReadWrite(std::string &filename, std::string &s1, std::string &s2)
{
	std::string line;
	while(true){
		std::ifstream file(filename);
		/* if (!file.is_open())			has been checked already
			return ; */
		std::getline(file, line);	//check eof?
		if (line.empty())
			break ;
		
	}
}

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Input error *_*" << std::endl;
		return -1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	//check input
	if (!CheckInput(filename, s1, s2)){
		std::cout << "Input error *_*" << std::endl;
		return -1;
	}

	
	//read file loop

		//readline

		//modify string

		//put to file
}