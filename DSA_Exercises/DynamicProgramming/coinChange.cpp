#include <vector>
#include <iostream>

static long long combinations(const int& amount, int coinIndex, const std::vector<int>& coins, std::vector<std::vector<long long>>& combos)
{
    if (amount < 0 || coinIndex < 0)
        return 0;
    if (amount == 0)
        return 1;

    if (combos[amount][coinIndex])
        return combos[amount][coinIndex];

    long long includedCoinsCombos = combinations(amount, coinIndex-1, coins, combos);
    long long excludedCoinCombos = combinations(amount-coins[coinIndex], coinIndex, coins, combos);

    return combos[amount][coinIndex] = includedCoinsCombos + excludedCoinCombos;
}

long long findCombinations(const int& n, const std::vector<int>& coins)
{
    int totalCoins = coins.size();
    std::vector<std::vector<long long>> combos(n+1, std::vector<long long>(totalCoins, 0));
    return combinations(n, totalCoins-1, coins, combos);
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter amount as program arg."<<std::endl;
        return -1;
    }
    std::vector<int> coins = {1,2,3};
    std::cout<<"Total combinations of change: "<<findCombinations(std::stoi(argv[1]), coins)<<std::endl;
    return 0;
}