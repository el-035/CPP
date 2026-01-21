#include"PmergeMe.hpp"

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

bool validateDigit(const std::string& input){
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









long long startTime(){
	struct timeval time;
	long long startTime;

	gettimeofday(&time, NULL);
	startTime = (time.tv_sec * 1000000LL + time.tv_usec);
	return (startTime);
}

long long finalTime(long long start){
	struct timeval time;
	long long endTime;

	gettimeofday(&time, NULL);
	endTime = (time.tv_sec * 1000000LL + time.tv_usec) - start;
	return (endTime);
}




bool duplicates(int argc, char **argv){
	std::vector<int> tmp;
	for (int i = 1; i < argc; ++i){
		std::stringstream ss(argv[i]);
		int value;
		ss >> value;
		if (ss.fail() || !ss.eof())
			return (std::cerr << "Error" << std::endl, false);
		tmp.push_back(value);
	}
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i + 1 < tmp.size(); i++){
		if (tmp[i] == tmp[i + 1])
			return true;
	}
	return false;
}

template <typename Container>
size_t binSearch(Container &c, size_t bSize, size_t minBlock, size_t maxBlock, int search){
	while (minBlock < maxBlock){
		size_t midBlock = (minBlock + maxBlock) / 2;
		size_t midIndex = (midBlock) * bSize - 1;
		
		if (midIndex >= c.size())
    		midIndex = c.size() - 1;

//		comparisons++;
		Container::iterator it = c.begin() 
		std::advance(it, midIndex);
		//if (search < c[midIndex])
		if(search < *it)
			maxBlock = midBlock;
		else
			minBlock = midBlock + 1;
	}
	return (minBlock - 1);
}