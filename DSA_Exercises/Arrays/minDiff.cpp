#include <iostream>
#include <vector>
#include <algorithm>
#include <ComplexObjectStream.hpp>

static std::pair<int,int> minDifference(std::vector<int> a, std::vector<int> b)
{
    std::pair<int,int> minDiffPair;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int minDiff = std::abs(a[0]-b[0]);
    int minSize = std::min(a.size(), b.size());
    int j = 0;
    for(int i = 1; i < minSize;)
    {
        int diff = std::abs(a[i] - b[j]);
        if (diff < minDiff){
            minDiff = diff;
            minDiffPair = std::make_pair(a[i], b[j]);
            j++;
        }
        else{
            i++;
        }
    }

    return minDiffPair;
}

int main()
{
    std::vector<int> arr1 = {23, 5, 10, 17, 30};
    std::vector<int> arr2 = {26, 134, 135, 14, 19};
    std::cout<<"Min difference pair: "<<minDifference(arr1, arr2)<<std::endl;
    return 0;
}