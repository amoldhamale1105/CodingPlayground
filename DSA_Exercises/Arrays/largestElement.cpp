#include <iostream>
#include <vector>

int largestElement(const std::vector<int> &arr)
{
    int maxElement = arr[0];
    for(auto itr = arr.begin(); itr != arr.end(); ++itr)
    {
        if (*itr > maxElement)
            maxElement = *itr;
    }

    return maxElement;
}

int main()
{
    std::vector<int> vec = {-3, 4, 1, 2, 3};
    std::cout<<"largest element: "<<largestElement(vec)<<std::endl;
    return 0;
}