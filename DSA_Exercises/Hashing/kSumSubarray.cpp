#include <vector>
#include <iostream>
#include <unordered_map>

int longestSubarrayKSum(const std::vector<int>& arr, const int& k)
{
    std::unordered_map<int,int> prefixArrElements;
    std::vector<int> prefixSumArr;

    for(const int& num : arr)
    {
        if (prefixSumArr.empty()){
            prefixSumArr.emplace_back(num);
            prefixArrElements.insert({num,1});
            continue;
        }
        int currSum = num+prefixSumArr.back();
        prefixSumArr.emplace_back(currSum);
        prefixArrElements[currSum] = prefixSumArr.size();
    }

    int maxLen{0};
    for(const int& num : prefixSumArr)
    {
        int len{0};
        if (num-k == 0)
            len = prefixArrElements[num];
        else if (prefixArrElements.find(num - k) != prefixArrElements.end())
            len = std::abs(prefixArrElements[num-k] - prefixArrElements[num]);
        
        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter target sum as program arg"<<std::endl;
        return -1;
    }

    int targetSum = std::stoi(argv[1]);
    std::vector<int> vec = {0,-2,1,2,3,4,5,15,10,5};
    std::cout<<"Longest subarray size with sum "<<targetSum<<" is "<<longestSubarrayKSum(vec, targetSum)<<std::endl;
    
    return 0;
}