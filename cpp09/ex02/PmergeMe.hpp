#ifndef PMM
#define PMM

#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<sys/time.h>
#include<list>

// #define GREEN "\033[32m"
// #define RED "\033[31m"
// #define STD "\033[0m"

//helpers
bool		duplicates(int argc, char **argv);
long long	finalTime(long long start);
long long	startTime();
bool		validateDigit(const std::string& input);
size_t		findJack(bool start);

//vector
void	printVector(std::vector<int>& v, bool sorted);
void	sortPairs(size_t &bSize, std::vector<int> &v);
void	mergeInsert(size_t &bSize, std::vector<int> &v);
bool	algOne(char **argv, int argc);

//list
bool algTwo(char **argv, int argc);
void mergeList(std::list<int>& l, size_t& bSize);
void sortPairsList(std::list<int>& l, int bSize);

template <typename Container>
size_t binSearch(Container &c, size_t bSize, size_t minBlock, size_t maxBlock, int search){
	while (minBlock < maxBlock){
		size_t midBlock = (minBlock + maxBlock) / 2;
		size_t midIndex = (midBlock) * bSize - 1;
		
		if (midIndex >= c.size())
    		midIndex = c.size() - 1;

		typename Container::iterator it = c.begin();
		std::advance(it, midIndex);
		if(search < *it)
			maxBlock = midBlock;
		else
			minBlock = midBlock + 1;
	}
	return (minBlock - 1);
}

/* template <typename Container>
bool is_sorted(Container& c){
	
	typename Container::iterator it = c.begin();
	typename Container::iterator next = it;
	next++;
	while (next != c.end()){
		if (*it > *next)
			return false;
		next++;
	}
	return true;
} */

#endif
