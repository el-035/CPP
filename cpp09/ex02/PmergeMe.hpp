#ifndef PMM
#define PMM

#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<sys/time.h>
#include<list>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define STD "\033[0m"

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


template <typename Container>
size_t binSearch(Container &c, size_t bSize, size_t minBlock, size_t maxBlock, int search);

//list
bool algTwo(char **argv, int argc);
void sortPairsList(std::list<int>& l, int bSize);

#endif

