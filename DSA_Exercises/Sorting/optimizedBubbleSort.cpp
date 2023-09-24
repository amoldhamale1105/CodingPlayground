#include <iostream>
#include <vector>
#include <algorithm>
#include <ComplexObjectStream.hpp>

// Best case time complexity will be O(n) when array is sorted
std::vector<int> optimizedBubbleSort(const std::vector<int>& v)
{
    std::vector<int> sortedVec = v;
    int n = v.size();
	bool sorted = true;

	for(int times = 1; times <= n-1; times++)
	{
		if (sorted){
			if (v[times] < v[times-1]){
				sorted = false;
				times = 1;
			}
			else
				continue;
		}
		for(int j = 0; j <= n - times - 1; j++)
		{
			if(sortedVec[j] > sortedVec[j+1])
				std::swap(sortedVec[j], sortedVec[j+1]);
		}
	}

	return sortedVec;
}

int main()
{
	std::vector<int> input = {1, 3, 5, 7, 9};
    //std::vector<int> input = {1, 9, 3, 5, 7};
    std::cout<<"sorted: "<<optimizedBubbleSort(input)<<std::endl;
    return 0;
}