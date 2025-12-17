#include "easyfind.hpp"

const char* NotFound::what() const throw(){
	return ("Value not found");
}

template<typename T>
typename T::const_iterator easyfind(const T& t, int n){
	for (typename T::const_iterator i = t.begin(); i != t.end(); ++i)
		if (*i == n)
			return (i);
	throw NotFound();
}