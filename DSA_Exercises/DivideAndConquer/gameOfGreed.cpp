#include <iostream>
#include <vector>
#include <algorithm>

bool canDivide(const std::vector<int>& coins, int partition, int count)
{
    int friends = 0;
    int sum = 0;

    for(int i = 0; i < coins.size(); i++)
    {
        sum += coins[i];
        if (sum >= partition){
            friends++;
            if (friends == count)
                return true;
            sum = 0;
        }
    }
    return false;
}

int getCoins(std::vector<int>& arr, int k)
{
    int s = INT32_MAX; // min possible value
    auto total = [&]() -> int {
        int sum = 0;
        for(int x : arr)
        {
            s = std::min(s, x);
            sum += x;
        }
        return sum;
    };
    int e = total(); // max possible value
    int maxVal = 0;

    // The search space is monotonic between the min and max partition. Perform a binary search on it
    while (s <= e)
    {
        int mid = (s+e)/2;
        if (canDivide(arr, mid, k)){
            maxVal = mid;
            s = mid+1;
        }
        else
            e = mid-1;
    }
    return maxVal;
}

int main()
{
    std::vector<int> coins = {1,2,3,4};
    std::cout<<"Max value won: "<<getCoins(coins, 3)<<std::endl;
    return 0;
}