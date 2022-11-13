#include <iostream>
#include <queue>
#include <vector>

int maxProduct(const std::vector<int>& nums)
{
    std::priority_queue<int> heap;

    for(const int& num : nums)
    {
        heap.push(num);
    }
    int max = heap.top();
    heap.pop();

    return (max-1)*(heap.top()-1);
}

int main()
{
    std::vector<int> vec = {3,4,5,2};
    std::cout<<"Max product: "<<maxProduct(vec)<<std::endl;

    return 0;
}