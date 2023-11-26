#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

// Expected Optimal Complexity O(n) Time, O(1) Space
std::pair<int,int> subarraySorting(const std::vector<int>& a)
{
    int currMax = a[0];
    int subArrMin{INT32_MAX};
    int s{-1}, e{-1};

    for(int i = 1; i < a.size(); i++)
    {
        if (a[i] < currMax){
            subArrMin = std::min(subArrMin, a[i]);
            e = i;
            continue;
        }
        currMax = a[i];
    }
    if (e > -1)
        while (a[++s] <= subArrMin);
    
    return {s,e};
}

int main()
{
    std::vector<int> arr = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
    std::cout<<"subarray bounds to be sorted: "<<subarraySorting(arr)<<std::endl;
    return 0;
}