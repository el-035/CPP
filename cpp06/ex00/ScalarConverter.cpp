#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	(void) other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return (*this);
}
ScalarConverter::~ScalarConverter(){}


bool ScalarConverter::loop(const std::string& s, int (*ft)(int))
{
	for (size_t i = 0; i < s.length(); i++){
		if (!ft(s[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isChar(const std::string& s)
{
	if (s.size() == 1 && !isdigit(s[0]))		//only 1 char
		return true;
	return (false);
}

bool ScalarConverter::isInt(const std::string& s)
{
	std::string cut = s;
	if (s.size() == 1 && isdigit(s[0])) 	//only 1 num int
		return true;
	if (s[0] == '+' || s[0] == '-') //SKIP + OR -
		cut = s.substr(1);
	if (loop(cut, isdigit))
		return true;
	return false;
}

bool ScalarConverter::isFloat(const std::string& s){
	std::string cut = s;
	int dot = 0;
	if (s[0] == '+' || s[0] == '-') //SKIP + OR -
		cut = s.substr(1);
	if (cut.length() == 0)
		return false;
	if (loop(cut, isalpha))
	{
		if (cut == "nanf" || cut == "inff")
			return true;
		else
			return false;
	}
	for (size_t i = 0; i < cut.length() - 1; i++)
	{
		if (cut[i] == '.')
			dot++;
		if (dot > 1)
			return false;
		if (cut[i] != '.' && !isdigit(cut[i]))
			return false;
	}
	if (cut[cut.size() - 1] == 'f')
		return true;
	return false;
}

bool ScalarConverter::isDouble(const std::string& s)
{
	std::string cut = s;
	int dot = 0;
	if (s[0] == '+' || s[0] == '-') //SKIP + OR -
		cut = s.substr(1);
	if (cut.length() == 0)
		return false;
	if (loop(cut, isalpha))
	{
		if (cut == "nan" || cut == "inf")
			return true;
		else
			return false;
	}
	for (size_t i = 0; i < cut.length(); i++)
	{
		if (cut[i] == '.')
			dot++;
		if (dot > 1)
			return false;
		if (cut[i] != '.' && !isdigit(cut[i]))
			return false;
	}
	size_t pos = s.find('.');
	if (pos != std::string::npos)
	{
		size_t digits = s.length() - pos - 1;
		if (digits > 17)
			return false;
	}
	return true;
}


int ScalarConverter::toInt(int *type, const std::string& s){
	int n = 0;
	float f = 0.0f;
	double d = 0.0;

	if (*type == INT)
	{
		long l = strtol(s.c_str(), NULL, 10);
		if (errno == ERANGE || l > INT_MAX || l < INT_MIN)
			*type = IMP;
		if (l == 0 && !isZero(s))
			*type = IMP;
		n = static_cast<int>(l);
	}

	d = strtod(s.c_str(), NULL);
	if (d > INT_MAX || d < INT_MIN)
		*type = IMP;

	if (*type == FLOAT)
	{
		f = strtof(s.c_str(), NULL);
		if (f == 0.0 && !isZero(s))
			*type = IMP;
		else if (s.find("nanf") != std::string::npos || s.find("inff") != std::string::npos)
			*type = IMP;
		else
			n = static_cast<int>(f);
	}

	if (*type == DOUBLE)
	{
		d = strtod(s.c_str(), NULL);
		if (d == 0.0 && !isZero(s))
			*type = IMP;
		else if (s.find("nan") != std::string::npos || s.find("inf") != std::string::npos)
			*type = IMP;
		else
			n = static_cast<int>(d);
	}
	return n;
}

float ScalarConverter::toFloat(int *type, const std::string& s){
	float f;
	double d;

	if (*type == FLOAT)
	{
		f = strtof(s.c_str(), NULL);
		if (f == 0.0f && !isZero(s))
			*type = IMP;
	}

	if (*type == DOUBLE)
	{
		d = strtod(s.c_str(), NULL);
		if (d == 0.0 && !isZero(s))
			*type = IMP;
		else
			f = static_cast<float>(d);
	}
	return f;
}

double ScalarConverter::toDouble(int *type, const std::string& s){
	float f;
	double d;
	
	if (*type == FLOAT)
	{
		f = strtof(s.c_str(), NULL);
		if (f == 0.0f && !isZero(s))
			*type = IMP;
		else
			d = static_cast<double>(f);
	}

	if (*type == DOUBLE)
	{
		d = strtod(s.c_str(), NULL);
		if (d == 0.0 && !isZero(s))
			*type = IMP;
	}
	return d;
}

bool ScalarConverter::isZero(const std::string& s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.length(); i++){
		if (s[i] != '0' && s[i] != '.' && s[i] != 'f')
			return false;
	}
	return true;
}

void ScalarConverter::printChar(int type, const std::string& s){
	char c;
	int n;

	std::cout << "char: ";

	if (type == CHAR)
	{
		if ((s[0] >= 0 && s[0] < 32) || s[0] == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << s[0] << "'" << std::endl;
		return ;
	}

	if (type != IMP)
		n = toInt(&type, s);

	if (type == IMP || n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		c = n;
		if ((n >= 0 && n < 32 )|| n == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
}


void ScalarConverter::printInt(int type, const std::string& s){
	int n;

	std::cout << "int: ";

	if (type == CHAR)
		n = s[0];

	if (type != CHAR && type != IMP)
		n = toInt(&type, s);

	if (type == IMP)
		std::cout << "impossible" << std::endl;
	else
		std::cout << n << std::endl;
}

void ScalarConverter::printFloat(int type, const std::string& s){
	float n;

	std::cout << "float: ";
	if (type == CHAR)
		n = s[0];
	
	if (type == FLOAT || type == DOUBLE)
		n = toFloat(&type, s);

	if (type == INT)
		n = toInt(&type, s);
	
	if (type == IMP)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << n << "f" << std::endl;
}

void ScalarConverter::printDouble(int type, const std::string& s){
	double n;

	std::cout << "double: ";
	if (type == CHAR)
		n = s[0];
	
	if (type == FLOAT || type == DOUBLE)
		n = toDouble(&type, s);

	if (type == INT)
		n = toInt(&type, s);

	if (type == IMP)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << n << std::endl;
}

int ScalarConverter::findType(const std::string& s){
	if (s.empty())
		return IMP;
	if (!loop(s, isascii))
		return IMP;
	if (isChar(s))
		return CHAR;
	else if (isInt(s))
		return INT;
	else if (isDouble(s))
		return DOUBLE;
	else if (isFloat(s))
		return FLOAT;
	return IMP;
}

void ScalarConverter::convert(const std::string& s){
	printChar(findType(s), s);
	printInt(findType(s), s);
	printFloat(findType(s), s);
	printDouble(findType(s), s);
	
}
