#pragma once

#include <iostream>
#include <string>

enum Level{
	DEBUG,
    INFO,
    WARNING,
    ERROR,
	UNKNOWN
};

class Harl{
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	public:
	void complain(std::string level);
	Level GetLevel(std::string level);
};