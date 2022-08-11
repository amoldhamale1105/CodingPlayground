#include <iostream>
#include <vector>

std::pair<int,int> closestSum(const std::vector<int>& arr, const int& x)
{
    int n = arr.size();
	int smallestDiff = std::abs(x - (arr[0] + arr[n-1]));
	std::pair<int,int> closestPair = std::make_pair(arr[0], arr[n-1]);

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if (std::abs(x - (arr[i] + arr[j])) < smallestDiff)
			{
				smallestDiff = x - (arr[i] + arr[j]);
				closestPair = std::make_pair(arr[i], arr[j]);
			}
		}
	}
	return closestPair;
}

int main()
{
    std::vector<int> vec = {10, 22, 28, 29, 30, 40};
    std::pair<int,int> closetPair = closestSum(vec, 54);
    std::cout<<"closet sum pair: "<<"{"<<closetPair.first<<","<<closetPair.second<<"}"<<std::endl;
    return 0;
}