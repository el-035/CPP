#pragma once

#ifndef EXC
#define EXC

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

bool checkInput(char* input);
bool isLeap(int year);


bool validateDate(std::string& date);
bool validateValue(std::string& value);
bool checkInputFormat(std::string& line);
bool mapData(std::map<std::string, float> *data);
void searchDate(std::map<std::string, float> *data, std::string line);
bool inputValidationSearch(std::map<std::string, float> *data, char *input);


#define ERR_INPUT "Error: Invalid Input"
#define ERR_OPEN "Error opening file"
#define ERR_EMPTY "Error: Empty file"
#define ERR_HEAD "Error: Invalid Header"
#define BAD_FORM "Error: Bad Format"
#define BAD_DATE "Error: Invalid Date"
#define BAD_VALUE "Error: Invalid Value"

#endif