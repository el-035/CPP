#include"PmergeMe.hpp"

template <typename Container>	//TODO: DELETE
void printBlocks(const Container &v, size_t bSize) // TODO: delete this
{
	size_t blockSize = bSize * 2;
	size_t i = 0;
	//std::cout << "BLOCK SIZE: " << bSize << std::endl;
	for ( typename Container::const_iterator it = v.begin(); it != v.end(); ++it, ++i)
	{
		std::cout << *it;

		if ((i + 1) % blockSize == 0 && i + 1 < v.size())
			std::cout << " | ";
		else if ((i + 1) % bSize == 0)
				std::cout << " - ";
		else
			std::cout << " ";
	}

	std::cout << std::endl;
}

void sortPairsList(std::list<int>& l, size_t bSize){
	if (bSize * 2 > l.size()){
		bSize /= 2;
		return ;
	}

	printBlocks(l, bSize);
	
	size_t nBlocks = l.size() / (2 * bSize);
	
	std::list<int>::iterator insPos = l.begin();

	for (size_t block = 0; block < nBlocks; ++block){
		std::list<int>::iterator cmpLow = insPos;
		std::advance(cmpLow, bSize - 1);
		
		std::list<int>::iterator cmpHigh = cmpLow;
		std::advance(cmpHigh, bSize);

		// std::cout << "ins " << *insPos << std::endl;
		// std::cout << "cmp1 " << *cmpLow << std::endl;
		// std::cout << "cmp2 " << *cmpHigh << std::endl << std::endl;

		std::list<int>::iterator start = cmpLow;
		std::advance(start, 1);
		std::list<int>::iterator end = cmpHigh;
		std::advance(end, 1);
		std::list<int>::iterator nextPos = insPos;
  		std::advance(nextPos, 2 * bSize);
		
		if (*cmpHigh < *cmpLow)
			l.splice(insPos, l, start, end);
		insPos = nextPos;
	}

	printBlocks(l, bSize);
	std::cout << std::endl;
	
	bSize *= 2;
	sortPairsList(l, bSize);	

}

bool algTwo(char **argv, int argc){
	//start timing
	long long startT = startTime();

	//fill the list
	std::list<int> l;
	for (int i = 1; i < argc; ++i){
		std::stringstream ss(argv[i]);
		int value;
		ss >> value;
		if (ss.fail() || !ss.eof())
			return (std::cerr << "Error" << std::endl, false);
		l.push_back(value);
	}

	//sort pairs
	size_t bSize = 1;
	sortPairsList(l, bSize);

	//merge and insert

	//final time
	long long endT = finalTime(startT);
	std::cout << "Time to process a range of " << l.size() << " elements with std::list: " << endT << " us" << std::endl;
	
	return true;
}