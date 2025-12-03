#include "Serialize.hpp"

int main(void){
	Data *str = new Data();
	uintptr_t ptr;

	str->i = 3;
	str->j = 6;
	str->s = "jj";
	std::cout << "OG address:	" << str << std::endl;

	ptr = Serializer::serialize(str);
	Data *test = Serializer::deserialize(ptr);

	std::cout << "Deserialised:	" << test << std::endl;

	std::cout << test->i << std::endl;
	std::cout << test->j << std::endl;
	std::cout << test->s << std::endl;

	delete str;
}