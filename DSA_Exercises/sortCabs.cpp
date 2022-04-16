#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define SQUARE(X) X*X

static std::vector<std::pair<int,int>> sortCabs(const std::vector<std::pair<int,int>>& v)
{
    float minMag{0};
    int totalPos = v.size();
    std::vector<std::pair<int,int>> sortedV = v;
    
    for(auto i = 0; i < totalPos-1; ++i)
    {
        minMag = std::sqrt(SQUARE(sortedV[i].first) + SQUARE(sortedV[i].second));
        for(auto j = i+1; j < totalPos; ++j)
        {
            float magnitude = std::sqrt(SQUARE(sortedV[j].first) + SQUARE(sortedV[j].second));
            if (magnitude < minMag){
                std::iter_swap(sortedV.begin()+i, sortedV.begin()+j);
                minMag = magnitude;
            }
        }
    }

    return sortedV;
}

int main(int argc, char** argv)
{
    std::vector<std::pair<int,int>> cabPositions = {{2,3}, {1,2}, {3,4}, {2,4}, {1,4}};

    for(const std::pair<int,int>& pos : sortCabs(cabPositions))
    {
        std::cout<<pos.first<<","<<pos.second<<std::endl;
    }
    
    return 0;
}