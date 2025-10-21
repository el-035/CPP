#include <fstream>
#include <iostream>
#include <string>

bool CheckInput(std::string &filename, std::string &s1)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open()){
		std::cerr << "Error opening file" << std::endl;
		return false;
	}

	file.seekg(0, std::ios::end);
	if (file.tellg() == 0){
		std::cerr << "Empty file" << std::endl;
		return false;
	}
	file.seekg(0, std::ios::beg);

	if (s1.empty()){
		std::cerr << "No string to be replaced" << std::endl;
		return false;
	}
	return true;
}

void replaceStr(std::string& line, std::string& s1, std::string& s2)
{
	size_t pos;
	std::string newLine = line;

	while(true){
		pos = line.find(s1);
		if (pos == std::string::npos)
			break;
		newLine = line.substr(0, pos) + s2 + line.substr(pos + s1.size());
		line = newLine;
	}
}

void ReadWrite(std::string &filename, std::string &s1, std::string &s2)
{
	std::string line;
	std::ofstream newFile((filename + ".replace").c_str(), std::ios::trunc);
	std::ifstream file(filename.c_str());

	while(std::getline(file, line)){
		replaceStr(line, s1, s2);
		newFile << line;
		if (!file.eof())
			newFile << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr << "Input error" << std::endl;
		return -1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (!CheckInput(filename, s1))
		return -1;
	ReadWrite(filename, s1, s2);
}