#include <iostream>
#include <vector>

static int xoring(std::vector<int>& v)
{
    int uniqueNumber{0};
    int n = v.size();

    for(auto i = 0; i < n; ++i)
    {
       uniqueNumber ^= v[i];
    }

    return uniqueNumber;
}

int main()
{
    std::vector<int> vec = {1,2,3,1,4,2,3};
    std::cout<<"unique number: "<<xoring(vec)<<std::endl;
    return 0;
}