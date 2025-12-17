#include"easyfind.hpp"
#include<vector>
#include<list>


int main(void){
	int arr[] = {1, 6, 5, 2, 7, 4, 9, 3};
	std::vector<int> test(arr, arr + 8);
	std::list<int> lis(arr, arr + 8);
	try{
		std::vector<int>::const_iterator i = easyfind(test, 6);
		std::cout << *i << std::endl;
		std::list<int>::const_iterator it = easyfind(lis, 1);
		std::cout << *it << std::endl;
		it = easyfind(lis, 66);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}