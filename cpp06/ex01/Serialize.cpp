#include"Serialize.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other){
	(void) other;
}

Serializer& Serializer::operator=(const Serializer& other){
	(void) other;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data* Serializer::deserialize(uintptr_t raw){
	Data *test = reinterpret_cast<Data *>(raw);
	return (test);
}