#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

class SubsetCompare
{
public:
    bool operator()(const std::vector<int>& vec1, const std::vector<int>& vec2)
    {
        return vec1.size() > vec2.size();
    }
};

static void uniqueSubsets(const std::vector<int>& input, std::vector<int>& output, int i, int j, std::vector<std::vector<int>>& subsets)
{
    //Base case
    if (i >= input.size()){
        output[j] = -1;
        std::vector<int> subset;
        for(auto itr = output.begin(); *itr != -1; ++itr)
        {
            subset.emplace_back(*itr);
        }
        if (!subset.empty()){
            std::sort(subset.begin(), subset.end());
            subsets.emplace_back(subset);
        }
        return;
    }

    //Rec case
    output[j] = input[i];

    uniqueSubsets(input, output, i+1, j+1, subsets);
    uniqueSubsets(input, output, i+1, j, subsets);
}

static int getMatchCount(const std::vector<int>& sortedSubset, const std::vector<int>& sortedArr)
{
    int count{0}, subIndex{0};
    int subsetSize = sortedSubset.size();

    for(const int& element : sortedArr)
    {
        if (element == sortedSubset[subIndex])
            count++;
        else if (element > sortedSubset[subIndex]){
            subIndex++;
            if (subIndex >= subsetSize)
                break;
            if (element == sortedSubset[subIndex])
                count++;
        }
    }

    return count;
}

static int minSetSize(const std::vector<int>& arr)
{
    std::set<int> uniqueElements;
    std::vector<int> uniqueArr;
    for(const int& num : arr)
    {
        uniqueElements.insert(num);
    }
    for(const int& num : uniqueElements)
    {
        uniqueArr.emplace_back(num);
    }

    std::vector<int> output(arr.size()+1, 0);
    std::vector<std::vector<int>> subsets;
    uniqueSubsets(uniqueArr, output, 0, 0, subsets);

    int halfSize = arr.size()/2;
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, SubsetCompare> minSubsetHeap;

    for(const std::vector<int>& subset : subsets)
    {
        if (getMatchCount(subset, sortedArr) >= halfSize)
            minSubsetHeap.push(subset);
    }

    return minSubsetHeap.top().size();
}

int main()
{
    std::vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    std::cout<<"Min set size: "<<minSetSize(arr)<<std::endl;
    return 0;
}