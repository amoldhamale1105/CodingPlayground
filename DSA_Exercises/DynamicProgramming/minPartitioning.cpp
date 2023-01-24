#include <vector>
#include <iostream>

static int findMinHelper(const std::vector<int>& input, std::vector<int>& output, int inputIndex, int outputIndex, const int& total, std::vector<std::vector<int>>& minDiffMem)
{
    if (inputIndex >= input.size()){
        output[outputIndex] = -1;
        auto itr = output.begin();
        int subsetSum{0};
        while (*itr != -1)
        {
            subsetSum += *itr++;
        }
        return std::abs(2*subsetSum - total);
    }

    if (minDiffMem[inputIndex][outputIndex])
        return minDiffMem[inputIndex][outputIndex];

    output[outputIndex] = input[inputIndex];

    int incMinDiff = findMinHelper(input, output, inputIndex+1, outputIndex+1, total, minDiffMem);
    int excMinDiff = findMinHelper(input, output, inputIndex+1, outputIndex, total, minDiffMem);

    return minDiffMem[inputIndex][outputIndex] = std::min(incMinDiff, excMinDiff);
}

int findMin(const std::vector<int>& arr)
{
    int n = arr.size();
    std::vector<int> output(n+1, 0);
    std::vector<std::vector<int>> minDiffMem(n, std::vector<int>(n+1, 0));
    int total{0};
    for(const int& num : arr)
    {
        total += num;
    }
    
    return findMinHelper(arr, output, 0, 0, total, minDiffMem);
}

int main()
{
    std::vector<int> set = {1,6,11,5};
    std::cout<<"Min partitioning sum: "<<findMin(set)<<std::endl;
    return 0;
}