#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ComplexObjectStream.hpp>

static int minSetSize(const std::vector<int>& arr)
{
    std::priority_queue<int> pq;
    std::vector<int> elementFreq;

    for(const int& num : arr)
    {
        pq.push(num);
    }
    int count{0};
    int currentElement = pq.top();
    while (!pq.empty())
    {
        while(!pq.empty() && currentElement == pq.top())
        {
            count++;
            pq.pop();
        }
        elementFreq.emplace_back(count);
        currentElement = pq.top();
        count = 0;
    }
    
    // Sort in descending order
    std::sort(elementFreq.begin(), elementFreq.end(), [](const int& a, const int& b)->bool{return a > b;});
    int setCount{0}, sum{0};
    int halfSize = arr.size()/2;

    for(const int& freqElement : elementFreq)
    {
        sum += freqElement;
        setCount++;
        if (sum >= halfSize)
            break;
    }

    return setCount;
}

int main()
{
    std::vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    std::cout<<"Min set size: "<<minSetSize(arr)<<std::endl;
    return 0;
}