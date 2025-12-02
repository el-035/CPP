#pragma once

#include<iostream>
#include<stdint.h>

struct Data{
	int i;
	int j;
	std::string s;
};

class Serializer{
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();

	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

