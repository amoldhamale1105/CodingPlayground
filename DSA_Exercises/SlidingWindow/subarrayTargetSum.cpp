#include <iostream>
#include <vector>
#include <unordered_map>

int cntSubarrays(std::vector<int>& arr, int k)
{
    std::unordered_map<int,int> prefixSumFreq;
    int sum{0}, idx{0}, count{0};

    while (idx < arr.size())
    {
        sum += arr[idx];
        if (sum == k)
            count++;
        /* This checks if there has been any prefix sum so far for current sum where target sum could be reached
           By subtracting that prefix sum, we are looking at a slice from current element to previous sum index
           where the difference is equal to the target sum thus qualifying as a valid subarray */
        if (prefixSumFreq.find(sum-k) != prefixSumFreq.end())
            count += prefixSumFreq[sum-k];
        prefixSumFreq[sum]++;
        idx++;
    }
    
    return count;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter target sum as program arg"<<std::endl;
        return 1;
    }
    std::vector<int> arr = {10, 2, -2, -20, 10};
    std::cout<<"Number of subarrays with target sum is "<<cntSubarrays(arr, std::stoi(argv[1]))<<std::endl;
    return 0;
}