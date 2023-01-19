#include <iostream>
#include <vector>
#include <climits>

int minCoinsTopDown(const int& amount, std::vector<int>& minCoinsDp, const std::vector<int>& demonitizations)
{
    if (amount == 0)
        return 0;
    
    if (minCoinsDp[amount] != INT_MAX)
        return minCoinsDp[amount];

    for(const int& coin : demonitizations)
    {
        if (amount-coin >= 0){
            int downMin = minCoinsTopDown(amount-coin, minCoinsDp, demonitizations);
            if (downMin != INT_MAX)
                minCoinsDp[amount] = std::min(minCoinsDp[amount], downMin+1);
        }
    }

    return minCoinsDp[amount];
}

int minCoins(const int& amount, const std::vector<int>& demonitizations)
{
    std::vector<int> minCoinsDp(amount+1, INT_MAX);
    minCoinsDp[0] = 0;
    int retVal = minCoinsTopDown(amount, minCoinsDp, demonitizations);
    return  retVal == INT_MAX ? -1 : retVal;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter amount as program arg."<<std::endl;
        return -1;
    }

    std::vector<int> demonitizations = {1,5,7,10};
    std::cout<<"Min coins required for change: "<<minCoins(std::stoi(argv[1]), demonitizations)<<std::endl;

    return 0;
}