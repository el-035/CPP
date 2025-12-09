#include "iter.hpp"

template <typename T> 
void Print(const T& t){
    std::cout << t << " ";
}
template <typename T> 
void add(T &x){
	x += 1;
}

int main()
{
	std::cout << "INT" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, Print<int>);
    std::cout << std::endl;
	
    iter(arr, 5, add<int>);
    iter(arr, 5, Print<int>);
    std::cout << std::endl;
	
	iter(arr, 5, add<int>);
    iter(arr, 5, Print<int>);
    std::cout << std::endl;
	
	std::cout << "DOUBLE" << std::endl;
	double d[] = {0.0, 2.4, 6.8, 10.0};
	iter(d, 4, Print<double>);
    std::cout << std::endl;
	iter(d, 4, add<double>);
    iter(d, 4, Print<double>);
    std::cout << std::endl;

	std::cout << "STRING" << std::endl;
	std::string a[] = {"hola", "culo"};
    iter(a, 2, Print<std::string>);
    std::cout << std::endl;
	
	return 0;
}