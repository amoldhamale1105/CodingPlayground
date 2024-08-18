#include <iostream>
#include <vector>

int maxValHelper(const std::vector<int>& v, int s, int e)
{
    // Base case of 1 or 2 coins left
    if (s == e || s == e-1)
        return std::max(v[s], v[e]);
    // Rec case where each player maximizes his minimum with the assumption that the other player is going to pick the best option
    // If Oswald picks first coin, his next turn could mean choosing between third or second last after Henry's turn in between
    int op1 = v[s] + std::min(maxValHelper(v, s+2, e), maxValHelper(v, s+1, e-1));
    // If Oswald picks last coin, his next turn could mean choosing between second or third last after Henry's turn in between
    int op2 = v[e] + std::min(maxValHelper(v, s+1, e-1), maxValHelper(v, s, e-2));

    return std::max(op1, op2);
}

int MaxValue(int n, std::vector<int> v)
{
    return maxValHelper(v, 0, n-1);
}

int main()
{
    std::vector<int> value{1,2,3,4};
    std::cout<<"Max value earned by Oswald: "<<MaxValue(value.size(), value)<<std::endl;
    return 0;
}