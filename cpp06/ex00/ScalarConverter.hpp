#pragma once

#include<iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cerrno>


#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define IMP 4


class ScalarConverter{
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool loop(const std::string& s, int (*ft)(int));
	static bool isChar(const std::string& s);
	static bool isInt(const std::string& s);
	static bool isFloat(const std::string& s);
	static bool isDouble(const std::string& s);
	static bool isZero(const std::string& s);

	static int findType(const std::string& s);

	static void printChar(int type, const std::string& s);
	static void printInt(int type, const std::string& s);
	static void printDouble(int type, const std::string& s);
	static void printFloat(int type, const std::string& s);


	static int toInt(int *type, const std::string& s);
	static float toFloat(int *type, const std::string& s);
	static double toDouble(int *type, const std::string& s);

	public:
	static void convert(const std::string& s);
};