#include "PmergeMe.hpp"

void printBlocks(const std::vector<int> &v, size_t bSize) // TODO: delete this
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

void debugPrint(const std::vector<int> &v, const std::vector<int> &low, const std::vector<int> &left, const std::vector<int> &max, size_t bSize){
	std::cout << "LOW: " << bSize << std::endl;
	printBlocks(low, bSize);
	std::cout << "MAIN: " << bSize << std::endl;
	printBlocks(v, bSize);
	std::cout << "LEFT: " << bSize << std::endl;
	printBlocks(left, bSize);
	std::cout << "limits: " << bSize << std::endl;
	printBlocks(max, bSize);
}

bool is_sorted(std::vector<int>& v){	//TODO: DELETE

	for (size_t i = 0; i + 1 < v.size(); i++){
		if (v[i] > v[i + 1])
			return false;
	}
	return true;
}

int F(int n)	//TODO: DELETE
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}