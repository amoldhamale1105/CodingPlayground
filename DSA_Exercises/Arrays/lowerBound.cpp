#include <iostream>
#include <vector>

int lowerBound(const std::vector<int>& A, const int& Val)
{
    int ASize = A.size();
    int s = 0;
    int e = ASize - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (A[mid] == Val || (A[mid] < Val && A[mid + 1] > Val))
            return A[mid];
        else if (A[mid] < Val)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return Val > A[ASize - 1] ? A[ASize - 1] : -1;
}

int main()
{
    std::vector<int> vec = {-1, -1, 2, 3, 5};
    std::cout<<"lower bound: "<<lowerBound(vec, 4)<<std::endl;
    return 0;
}