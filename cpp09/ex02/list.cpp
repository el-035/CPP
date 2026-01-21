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

void sortPairsList(std::list<int>& l, size_t& bSize){
	if (bSize * 2 > l.size()){
		bSize /= 2;
		return ;
	}

	//////////////////////////////////////////////////////////////
	std::cout <<"BLOCK SIZE: " << bSize << std::endl;
	printBlocks(l, bSize);
	//////////////////////////////////////////////////////////////
	
	size_t nBlocks = l.size() / (2 * bSize);
	
	std::list<int>::iterator insPos = l.begin();

	for (size_t block = 0; block < nBlocks; ++block){
		std::list<int>::iterator cmpLow = insPos;
		std::advance(cmpLow, bSize - 1);
		
		std::list<int>::iterator cmpHigh = cmpLow;
		std::advance(cmpHigh, bSize);

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

	//////////////////////////////////////////////////////////////
	printBlocks(l, bSize);
	std::cout << std::endl;
	//////////////////////////////////////////////////////////////

	bSize *= 2;
	sortPairsList(l, bSize);
}

void mergeList(std::list<int>& l, size_t& bSize){
	size_t nBlocks = l.size() / bSize;
	size_t prevJ = 0;
	

	if (nBlocks > 2){
		findJack(true);
		//move smaller blocks to low list

		std::list<int> low;
		std::list<int> left;
		std::list<int> main;
		std::list<int> maxPos;

		std::list<int>::iterator bStart = l.begin();
		
		size_t block = 0;
		int lim = 3;
		while(block < nBlocks){
			std::list<int>::iterator bEnd = bStart;
			std::advance(bEnd, bSize);

			if (block < 2)
				main.insert(main.end(), bStart, bEnd);
			else if (block % 2 == 0){
				low.insert(low.end(), bStart, bEnd);
				maxPos.push_back(lim);
				lim++;
			}
			else
				main.insert(main.end(), bStart, bEnd);
			std::advance(bStart, bSize);
			
			block++;
		}

		left.insert(left.end(), bStart, l.end());
		l.swap(main);

		//////////////////////////////////////////////////////////////
		std::cout << "LOW:" <<bSize << std::endl;
		printBlocks(low, bSize);
		std::cout << "MAIN: " <<bSize << std::endl;
		printBlocks(l, bSize);
		std::cout << "LEFT:" <<bSize << std::endl;
		printBlocks(left, bSize);
		std::cout << "LIMITS:" <<bSize << std::endl;
		printBlocks(maxPos, bSize);
		//////////////////////////////////////////////////////////////

		//insert low into main list
		while(!low.empty()){
			size_t jack = findJack(false);
			size_t curBlock = jack - prevJ;
			prevJ = jack;
			size_t minBlock = 1;
					
			if (!low.empty() && curBlock > (low.size() / bSize))
				curBlock = low.size() / bSize;
			
			std::list<int>::iterator maxBlock = maxPos.begin();
			std::advance(maxBlock, curBlock - 1);
			std::list<int>::iterator search = low.begin();
			std::advance(low, (curBlock * bSize) -1);


			while(curBlock > 0){
				size_t insBlock = binSearch(l, bSize, minBlock, *maxBlock, *search);

				//insert low into main
				std::list<int>::iterator lowBeg = low.begin();
				std::list<int>::iterator lowEnd = ;


			}
		}



		//put left back
		l.insert(l.end(), left.begin(), left.end());
	}
	

	if (bSize == 1)
		return ;
	bSize /= 2;
	//mergeList(l, bsize);
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
	mergeList(l, bSize);

	//final time
	long long endT = finalTime(startT);
	std::cout << "Time to process a range of " << l.size() << " elements with std::list: " << endT << " us" << std::endl;
	
	return true;
}