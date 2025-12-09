#include "iter.hpp"

template <typename T> void Print(const T& t){
    std::cout << t << " ";
}

void add(int &x){
	x += 1;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, Print<int>);
    std::cout << std::endl;
	
    iter(arr, 5, add);
    iter(arr, 5, Print<int>);
    std::cout << std::endl;
	
	iter(arr, 5, add);
    iter(arr, 5, Print<int>);
    std::cout << std::endl;
	
	std::string a[] = {"hola", "culo"};
    iter(a, 2, Print<std::string>);
    std::cout << std::endl;
	
	
	
	return 0;
}