#include"PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc == 1)
		return (std::cerr << "Error" << std::endl, -1);
	else if (argc == 2) //TODO: only one number
		return (std::cerr << "Error: not enough numbers" << std::endl, -1);
	for (int i = 1; i < argc; i++){
		if (!validateDigit(argv[i]))
			return -1;
	}
	if (duplicates(argc, argv))
		return (std::cerr << "Error: no duplicates allowed" << std::endl, -1);
	algOne(argv, argc);
	algTwo(argv, argc);
}