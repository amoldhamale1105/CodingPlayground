#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
    stream << "{";
    for(const int& num : vec)
    {
        stream << num << " ";
    }
    stream << "}";
    return stream;
}

static bool contains(const std::vector<std::vector<int>>& subset, const std::vector<int>& searchVec)
{
    for(const std::vector<int>& vec : subset)
    {
        if (vec == searchVec){
            return true;
        }
    }
    return false;
}

static void uniqueSubsetsHelper(std::vector<int>& input, std::vector<int>& output, int i, int j, std::vector<std::vector<int>>& list)
{
    //Base case
    if (i >= input.size()){
        output[j] = -1;
        std::vector<int> tempOutput = output;
        tempOutput.erase(std::find(tempOutput.begin(), tempOutput.end(), -1), tempOutput.end());
        std::sort(tempOutput.begin(), tempOutput.end());
        if (!contains(list, tempOutput))
            list.emplace_back(tempOutput);
        return;
    }

    //Rec case
    output[j] = input[i];
    //Include next number in subset
    uniqueSubsetsHelper(input, output, i+1, j+1, list);
    //Exclude next number in subset
    uniqueSubsetsHelper(input, output, i+1, j, list);
}

static std::vector<std::vector<int>> uniqueSubsets(std::vector<int>& nums)
{
    std::vector<int> output(nums.size()+1, 0);
    std::vector<std::vector<int>> subsets = {};

    uniqueSubsetsHelper(nums, output, 0, 0, subsets);
    std::sort(subsets.begin(), subsets.end());
    return subsets;
}

int main()
{
    std::vector<int> nums = {4,4,4,1,4};

    std::cout<<"Possible subsets:"<<std::endl;
    std::vector<std::vector<int>> subsets = uniqueSubsets(nums);
    for(const std::vector<int>& vec : subsets)
    {
        std::cout<<vec;
    }
    std::cout<<std::endl;
}