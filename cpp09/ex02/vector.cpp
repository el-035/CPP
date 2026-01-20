#include"PmergeMe.hpp"

void printVector(std::vector<int>& v, bool sorted){
	if (!sorted)
		std::cout << "Before:	";
	else if (sorted)
		std::cout << "After:	";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it){
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

void sortPairs(size_t &bSize, std::vector<int> &v){
	size_t index = 0;
	
	if (bSize * 2 > v.size()){
		bSize /= 2;
		return ;
	}
//	std::cout << "BLOCK SIZE: " << bSize << std::endl; //TODO: COMMENT OUT
//	printBlocks(v, bSize);

	while (index + (bSize * 2) <= v.size()){	//double check this condition
		size_t first = index + bSize -1;
		size_t second = index + 2 * bSize - 1;

//		comparisons++;	//testing
		if (v[first] > v[second])
			std::swap_ranges(v.begin() + index, v.begin() + index + bSize, v.begin() + index + bSize);

		index += (2 * bSize);
	}
//	printBlocks(v, bSize); //TODO: COMMENT OUT
//	std::cout << std::endl;

	bSize *=2;
	sortPairs(bSize, v);	
}

size_t binSearch(std::vector<int> &v, size_t bSize, size_t minBlock, size_t maxBlock, int search){
	while (minBlock < maxBlock){
		size_t midBlock = (minBlock + maxBlock) / 2;
		size_t midIndex = (midBlock) * bSize - 1;
		
		if (midIndex >= v.size())
    		midIndex = v.size() - 1;

//		comparisons++;
		if (search < v[midIndex])
			maxBlock = midBlock;
		else
			minBlock = midBlock + 1;
	}
	return (minBlock);
}

void mergeInsert(size_t &bSize, std::vector<int> &v){
	size_t nBlocks = v.size() / bSize;
	size_t prevJ = 0;

//	std::cout << "num of blocks: " << nBlocks << std::endl;
//	std::cout << "BLOCK SIZE: " << bSize << std::endl;
//	printBlocks(v, bSize);
//	std::cout << std::endl;

	if (nBlocks > 2){
		findJack(true);
		//move smaller blocks to low vector
		std::vector<int> low;
		std::vector<int> main;
		std::vector<int> left;
		std::vector<int> max;
		size_t i = 0;
		int lim = 3;
		while(i + bSize <= v.size()){
			size_t block =  i / bSize;
			if (block < 2)
				main.insert(main.end(), v.begin() + i, v.begin() + i + bSize);
			else if (block % 2 == 0){
				low.insert(low.end(), v.begin() + i, v.begin() + i + bSize);
				if (max.empty())
					max.push_back(lim);
				else
					max.push_back(lim);
				lim++;
			}
			else
				main.insert(main.end(), v.begin() + i, v.begin() + i + bSize);
			i += bSize;
		}
		left.insert(left.end(), v.begin() + i, v.end());
		v.swap(main);
		
//		debugPrint(v, low, left, max, bSize);	//TODO: comment out
		
		//do insertion of low into v
		while(!low.empty()){
			//find int in low that needs to be compared
			size_t Jack = findJack(false);
			size_t curBlock = Jack - prevJ;
			prevJ = Jack;
			size_t minBlock = 1;

			if (!low.empty() && curBlock > (low.size() / bSize))		//double ckeck
				curBlock = low.size() / bSize;

			while(curBlock > 0){
				size_t insBlock = binSearch(v, bSize, minBlock, max[curBlock - 1], low[curBlock * bSize - 1]);
				insBlock -= 1;

				//INSERT FROM LOW TO MAIN
				v.insert(v.begin() + (insBlock * bSize), low.begin() +  (curBlock -1) * bSize, low.begin() +  (curBlock - 1) * bSize  + bSize);
				low.erase(low.begin() +  (curBlock -1) * bSize, low.begin() +  (curBlock - 1) * bSize  + bSize);
				
				for (size_t i = 0; i < max.size(); i++)
					max[i] += 1;
			
				max.erase(max.begin() + curBlock  - 1, max.begin() + curBlock);	//

//				debugPrint(v, low, left, max, bSize); //TODO: comment out

				curBlock--;
			}
		}
		//add tmp at the end of v
		v.insert(v.end(), left.begin(), left.end());

	}
	if (bSize == 1)
		return ;
	bSize /= 2;
	mergeInsert(bSize, v);
}

bool algOne(char **argv, int argc){
	//start timing
	long long startT = startTime();

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
	printVector(v, false);

	/* ------------------------ */
//	std::cout << "BEFORE:" << std::endl;
//	for(std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
//		std::cout << (*it) << " ";
//	std::cout << std::endl << std::endl;
	/* ------------------------ */

	//sorting pairs
	size_t bSize = 1;
	sortPairs(bSize, v);

	//merge vectors
	mergeInsert(bSize, v);

	printVector(v, true);

	//final time
	long long endT = finalTime(startT);
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << endT << " us" << std::endl;

	// TODO: DELETE!
/* 	int maxCmp = F(v.size());
	std::cout << "MAX COMPARISONS: " << maxCmp << std::endl;
	std::cout << "TOT COMPARISONS: " << comparisons << std::endl;
	if (is_sorted(v))
		std::cout << GREEN << "SORTED" << std::endl;
	else
		std::cout << RED << "NOT SORTED" << STD << std::endl;
	if (maxCmp < comparisons)
		std::cout << RED << "TOO MANY COMPARISONS" << STD << std::endl; */

	return true;
}