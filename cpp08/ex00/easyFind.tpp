#include "easyFind.hpp"

const char* NotFound::what() const throw(){
	return ("Value not found");
}

template<typename T>
typename T::const_iterator easyFind(const T& t, int n){
	typename T::const_iterator i = std::find(t.begin(), t.end(), n);
	if (i == t.end())
		throw NotFound();
	return i;
}