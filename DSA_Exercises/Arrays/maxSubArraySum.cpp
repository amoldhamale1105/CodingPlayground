#include <iostream>
#include <vector>

// Kadane's algorithm with O(n) time complexity
static int maxSubarraySum(const std::vector<int>& arr)
{
    int currSum = 0, maxSum = 0;
    
    for(const int& num : arr)
    {
        currSum += num;
        if (currSum < 0)
            currSum = 0;
        maxSum = std::max(currSum, maxSum);
    }

    return maxSum;
}

int maxSumSubarray(const std::vector<int>& A)
{
    std::vector<int> prefixSumArr;
    int n = A.size();
    int maxSum = A[0];

    for(auto i = 0; i < n; ++i)
    {
        if (i == 0){
            prefixSumArr.push_back(A[i]);
            continue;
        }
        prefixSumArr.push_back(prefixSumArr[i-1] + A[i]);
    }

    for(auto i = 0; i < n; ++i)
    {
        for(auto j = i; j < n; ++j)
        {
            int subArrSum = j == i ? prefixSumArr[j] : prefixSumArr[j] - prefixSumArr[i-1];
            if (subArrSum > maxSum)
                maxSum = subArrSum;
        }
    }

    return maxSum;
}

int main()
{
    std::vector<int> vec = {1, -2, 3, 4, 4, -2};
    //std::vector<int> vec = {-1,2,3,4,-2,6,-8,3};
    std::cout<<"max subarray sum: "<<maxSumSubarray(vec)<<std::endl;
    std::cout<<"max subarray sum (Kadane's algo): "<<maxSubarraySum(vec)<<std::endl;
    return 0;
}