#include <iostream>
#include <vector>
#include <algorithm>
#include <ComplexObjectStream.hpp>

std::vector<int> optimizedBubbleSort(const std::vector<int>& v)
{
    std::vector<int> sortedVec = v;
    int n = v.size();

	for(int times = 1; times <= n-1; times++)
	{
		if(v[n-times-1] < v[n-times]){
			if (times == n-1)
				break;
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
    std::cout<<"sorted: "<<optimizedBubbleSort(input)<<std::endl;
    return 0;
}