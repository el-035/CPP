#include "Serialize.hpp"

int main(void){
	Data *str = new Data();
	uintptr_t ptr;

	std::cout << str << std::endl;
	ptr = Serializer::serialize(str);
	Data *test = Serializer::deserialize(ptr);

	std::cout << test << std::endl;

	delete str;
}