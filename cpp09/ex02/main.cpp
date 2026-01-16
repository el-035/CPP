#include"PmergeMe.hpp"

int comparisons;

size_t findJack(bool start){ //starts by returing 3, change double prev to 0 if 1 needed
	static size_t prev = 1;
	static size_t doublePrev = 0;
	if (start){
		prev = 1;
		doublePrev = 0;
	}
	size_t j = prev + (2 * doublePrev);
	doublePrev = prev;
	prev = j;
	return j - 1;
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


void printBlocks(const std::vector<int> &v, size_t bSize)
{
	size_t blockSize = bSize * 2;

	//std::cout << "BLOCK SIZE: " << bSize << std::endl;
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];

		if ((i + 1) % blockSize == 0 && i + 1 < v.size())
			std::cout << " | ";
		else if ((i + 1) % bSize == 0)
				std::cout << " - ";
		else
			std::cout << " ";
	}

	std::cout << std::endl;
}

void sortPairs(size_t &bSize, std::vector<int> &v){
	size_t index = 0;
	if (bSize * 2 >= v.size()){
		bSize /= 2;
		return ;
	}
	std::cout << "BLOCK SIZE: " << bSize << std::endl;
	printBlocks(v, bSize);
	while (index + (bSize * 2) <= v.size()){	//double check this condition
		size_t first = index + bSize -1;
		size_t second = index + 2 * bSize - 1;

		comparisons++;	//testing
		if (v[first] > v[second])
			std::swap_ranges(v.begin() + index, v.begin() + index + bSize, v.begin() + index + bSize);

		index += (2 * bSize);
	}

	printBlocks(v, bSize);
	std::cout << std::endl;

	bSize *=2;
	sortPairs(bSize, v);	
}

size_t binSearch(std::vector<int> &v, size_t bSize, size_t maxIndex, int search){
	size_t minIndex = bSize - 1;

	while (minIndex < maxIndex){
		size_t midIndex = (minIndex + maxIndex) / 2 * bSize - 1;

		comparisons++;
		if (search < v[midIndex])
			maxIndex = midIndex;
		else
			minIndex = midIndex + bSize;
	}
	
	return (minIndex);
}

void mergeInsert(size_t &bSize, std::vector<int> &v){
	size_t nBlocks = v.size() / bSize;
	std::cout << "num of blocks: " << nBlocks << std::endl;
	std::cout << "BLOCK SIZE: " << bSize << std::endl;
	printBlocks(v, bSize);
	std::cout << std::endl;
	
	if (nBlocks > 2){
		findJack(true);

		//move smaller blocks to low vector
		std::vector<int> low;
		std::vector<int> main;
		std::vector<int> left;
		size_t i = 0;
		while(i + bSize <= v.size()){
			size_t block =  i / bSize;
			if (block < 2)
				main.insert(main.end(), v.begin() + i, v.begin() + i + bSize);
			else if (block % 2 == 0)
				low.insert(low.end(), v.begin() + i, v.begin() + i + bSize);
			else
				main.insert(main.end(), v.begin() + i, v.begin() + i + bSize);
			i += bSize;
		}
		left.insert(left.end(), v.begin() + i, v.end());

		v.swap(main);
		
		std::cout << "LOW: " << bSize << std::endl;
		printBlocks(low, bSize);
		std::cout << "MAIN: " << bSize << std::endl;
		printBlocks(v, bSize);
		std::cout << "LEFT: " << bSize << std::endl;
		printBlocks(left, bSize);
		
		//do insertion of low into v
		while(!low.empty()){
			//find int in low that needs to be compared
			size_t curIndex = findJack(false);
			curIndex = curIndex * bSize - 1;
			if (!low.empty() && curIndex >= low.size())
				curIndex = low.size() - 1;
			std::cout << "index of n to be compared " << curIndex << std::endl;
		

			//FIND RANGE FOR BINARY INSERTION
				//min starts from bSize always
				//max is 
				//low index
			size_t maxIndex = (((curIndex + 1) / bSize + 1) * bSize) - 1;
			size_t minIndex = bSize - 1;
			
			std::cout << "index of max comp " << maxIndex << std::endl;
			std::cout << "index of min comp " << minIndex << std::endl;
			return ;
		}


		//add tmp at the end of v
		v.insert(v.end(), left.begin(), left.end());


	}
	
	if (bSize == 1)
		return ;
	bSize /= 2;
	//mergeInsert(bSize, v);
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
	std::cout << std::endl << std::endl;
	/* ------------------------ */

	//sorting pairs
	size_t bSize = 1;
	sortPairs(bSize, v);

	//std::cout << bSize << std::endl;
	//merge vectors
	bSize /= 2;
	mergeInsert(bSize, v);

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