#include <iostream>
#include <vector>

static std::vector<bool> subsetSum(std::vector<int>& num, std::vector<int>& query)
{
    std::vector<bool> results;
    int n = num.size();
    int sum{0};

    for(auto i = 0; i < n; ++i)
    {
        sum += num[i];
    }

    for (const int& queryParam : query)
    {
        bool subsetFound{false};

        for(auto i = 0; i < n; ++i)
        {
            if (!(sum ^ queryParam) || !((sum - num[i]) ^ queryParam)){
                subsetFound = true;
                break;
            }
        }

        results.push_back(subsetFound);
    }

    return results;
}

int main()
{
    std::vector<int> arr = {6,2,3,4};
    std::vector<int> query = {7,9};

    for(bool result : subsetSum(arr, query))
    {
        std::cout<<result<<" ";
    }

    std::cout<<std::endl;

    return 0;
}