#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

// Division purposely not used because of problem statement requirement
static std::vector<int> productArray(const std::vector<int>& arr)
{
    int n = arr.size();
    std::vector<int> output(n,1);
    // save forward prefix product upto prev index in curr index of output
    for(int i = 1; i < n; i++)
    {
        output[i] = arr[i-1]*output[i-1];
    }
    // multiply forward and reverse prefix product to get final output
    int revProd = 1;
    for(int i = n-1; i >= 0; i--)
    {
        output[i] *= revProd;
        revProd *= arr[i];
    }
    
    return output;
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5};
    std::cout<<"array products: "<<productArray(arr)<<std::endl;
    return 0;
}