#include <iostream>
#include <vector>
#include <bits/stdc++.h>

static int defkin(int W, int H, std::vector<std::pair<int, int>> position)
{
    int maxPenalty{0};
    std::vector<int> cutOffCols, cutOffRows;
    
    for(const std::pair<int,int>& loc : position)
    {
        cutOffCols.push_back(loc.second);
        cutOffRows.push_back(loc.first);
    }

    std::sort(cutOffRows.begin(), cutOffRows.end());
    std::sort(cutOffCols.begin(), cutOffCols.end());
    if(cutOffRows.back() < W)
        cutOffRows.push_back(W+1);
    if(cutOffCols.back() < H)
        cutOffCols.push_back(H+1);

    //Compute max penalty based on row and col cut off
    int prevRow{0}, prevCol{0};
    for(int rowIndex : cutOffRows)
    {
        //Compute no. of undefended sqaures in any row based on col cut off
        for(int colIndex : cutOffCols)
        {
            maxPenalty = std::max(maxPenalty, ((rowIndex-(prevRow+1))*(colIndex-(prevCol+1)))); 
            prevCol = colIndex;
        }
        prevRow = rowIndex;
    }

    return maxPenalty;
}

int main()
{
    int mapWidth = 15, mapHeight = 8;
    std::vector<std::pair<int,int>> towerPositions = {{3,8},{11,2},{8,6}};
    std::cout<<"Max penalty: "<<defkin(mapWidth, mapHeight, towerPositions)<<std::endl;
    return 0;
}
