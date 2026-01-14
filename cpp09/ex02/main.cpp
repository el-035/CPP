#include"PmergeMe.hpp"

int comparisons;

int findJack(){ //starts by returing 3, change double prev to 0 if 1 needed
	static int prev = 1;
	static int doublePrev = 1;
	int j = prev + (2 * doublePrev);
	doublePrev = prev;
	prev = j;
	return j;
}

bool validateDigit(const std::string& input){ 	//duplicates????
	if (input.empty())
		return (std::cerr << "Error" << std::endl, false);
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it){
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return (std::cerr << "Error" << std::endl, false);
	}
	std::stringstream ss(input);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof())
		return (std::cerr << "Error" << std::endl, false);
	return true;
}

void swap(int index, size_t pSize, std::vector<int> &v){
	std::vector<int> first(v.begin() + index, v.begin() + index + pSize);
	std::vector<int> second(v.begin() + index + pSize, v.begin() + index + 2 * pSize);

	v.erase(v.begin() + index, v.begin() + index + 2 * pSize);

	v.insert(v.begin() + index, second.begin(), second.end());
	v.insert(v.begin() + index + pSize, first.begin(), first.end());
}

void sortPairs(size_t &pSize, std::vector<int> &v){
	size_t index = 0;
	if (pSize * 2 >= v.size())
		return ;

	while (index + pSize < v.size()){
		size_t first = index + pSize -1;
		size_t second = index + 2 * pSize - 1;

		comparisons++;
		if (v[first] > v[second])
			std::swap_ranges(v.begin() + index, v.begin() + index + pSize, v.begin() + index + pSize);

		//	swap(index, pSize, v);

		index += (2 * pSize);
	}

	/* ------------------------ */
	std::cout << "AFTER:" << std::endl;
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << (*it) << " ";
	std::cout << std::endl;
	/* ------------------------ */

	pSize *=2;
	sortPairs(pSize, v);	
}


bool algOne(char **argv, int argc){

	//fill the vector
	std::vector<int> v;
	for (int i = 1; i < argc; ++i){
		std::stringstream ss(argv[i]);
		int value;
		ss >> value;
		if (ss.fail() || !ss.eof())
			return (std::cerr << "Error" << std::endl, false);
		v.push_back(value);
	}

	/* ------------------------ */
	std::cout << "BEFORE:" << std::endl;
	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << (*it) << " ";
	std::cout << std::endl;
	/* ------------------------ */

	//sorting pairs
	size_t pSize = 1;
	sortPairs(pSize, v);

	std::cout << pSize << std::endl;
	//merge vectors
	std::cout << "TOT COMPARISONS: " << comparisons << std::endl;
	return true;
}

int main(int argc, char **argv){
	if (argc == 1)
		return (std::cerr << "Error" << std::endl, -1);
	for (int i = 1; i < argc; i++){
		if (!validateDigit(argv[i]))
			return -1;
	}
	comparisons = 0;
	algOne(argv, argc);
}