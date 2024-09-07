#include <iostream>
#include <vector>

int maxValHelper(const std::vector<int>& v, int s, int e, int k)
{
    // Base case of less than 2k coins left which means last turn
    if (s + 2*k -1 >= e){
        return std::max([&]()->int{int sum = 0; for(int i = s; i < s+k; i++)sum+=v[i]; return sum;}(),
                    [&]()->int{int sum = 0; for(int i = e; i > e-k; i--)sum+=v[i]; return sum;}());
    }
    // Rec case where each player maximizes his minimum with the assumption that the other player is going to pick the best option
    // If Oswald picks first k coins in a row, his next turn could mean choosing between 2k+1 th or k last after Henry's turn in between
    int op1 = [&]()->int{int sum = 0; for(int i = s; i < s+k && i <= e; i++)sum+=v[i]; return sum;}() + 
                std::min(maxValHelper(v, s+2*k, e, k), maxValHelper(v, s+k, e-k, k));
    // If Oswald picks last k coins, his next turn could mean choosing between k+1 th or 2k last after Henry's turn in between
    int op2 = [&]()->int{int sum = 0; for(int i = e; i > e-k && i >= s; i--)sum+=v[i]; return sum;}() + 
                std::min(maxValHelper(v, s+k, e-k, k), maxValHelper(v, s, e-2*k, k));

    return std::max(op1, op2);
}

int MaxValue(int n, std::vector<int> v, int k)
{
    return maxValHelper(v, 0, n-1, k);
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cout<<"Enter number of coins per turn as program arg."<<std::endl;
        return 1;
    }
    std::vector<int> value{10, 15, 20, 9, 2, 5};
    std::cout<<"Max value earned by Oswald: "<<MaxValue(value.size(), value, std::stoi(argv[1]))<<std::endl;
    return 0;
}