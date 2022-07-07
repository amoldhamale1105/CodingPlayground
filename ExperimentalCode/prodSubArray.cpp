#include <iostream>
#include <vector>
#include <algorithm>

static std::vector<std::vector<int>> getProdSubArrays(std::vector<int>& arr, const int& product)
{
    int n = arr.size();
    int lastProd{0};
    std::vector<int> loopSubArr;
    std::vector<std::vector<int>> prodSubArr;

    for(auto i = 0; i < n-1; ++i)
    {
        lastProd = arr[i];
        loopSubArr.push_back(arr[i]);
        for(auto j = i+1; j < n; ++j)
        {
            loopSubArr.push_back(arr[j]);
            lastProd *= arr[j];
            if (lastProd == product){
                prodSubArr.push_back(loopSubArr);
                if (j < n-1 && arr[j+1] == 1)
                    continue;
                else
                    break;
            }
        }
        loopSubArr.clear();
    }

    return prodSubArr;
}

int main(int argc, char** argv)
{
    int product = std::stoi(argv[1]);
    //std::vector<int> arr = {1,2,3,4};
    std::vector<int> arr = {1,6,4,3,8};

    for(const std::vector<int>& vec : getProdSubArrays(arr, product))
    {
        for(const int& num : vec)
        {
            std::cout<<num<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}