#include <iostream>
#include <vector>
#include <algorithm>

static int pairSticks(std::vector<int> length, const int& D)
{
    int n = length.size();
    int maxPairCount{0};
    std::vector<int> usedIndices;

    for(int i = 0; i < n-1; i++)
    {
        if(std::find(usedIndices.begin(), usedIndices.end(), i) != usedIndices.end())
            continue;

        for(int j = i+1; j < n; j++)
        {
            if(std::find(usedIndices.begin(), usedIndices.end(), j) != usedIndices.end())
                continue;
            if(std::abs(length[i] - length[j]) <= D){
                maxPairCount++;
                usedIndices.push_back(i);
                usedIndices.push_back(j);
                break;
            }
        }
    }

    return maxPairCount;
}

int main(int argc, char** argv)
{
    std::vector<int> vec = {1,3,3,9,4};
    int lenDiff = std::atoi(argv[1]);
    std::cout<<"Max chopsticks pairs with length difference "<<lenDiff<<" : "<<pairSticks(vec, lenDiff)<<std::endl;
    return 0;
}
