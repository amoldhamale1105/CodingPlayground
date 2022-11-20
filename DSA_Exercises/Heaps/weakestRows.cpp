#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ComplexObjectStream.hpp>
#include <PrintHelpers.hpp>

class Weakest
{
public:
    bool operator()(const std::pair<int,int>& row1, const std::pair<int,int>& row2)
    {
        return row1.second == row2.second ? (row1.first < row2.first) : (row1.second < row2.second);
    }
};

static std::vector<int> kWeakestRows(const std::vector<std::vector<int>>& mat, const int& k)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Weakest> weakestRowsQueue;
    int totalRows = mat.size();

    for(auto rowIndex = 0; rowIndex < totalRows; rowIndex++)
    {
        int soldierCount{0};
        auto itr = mat[rowIndex].begin();

        while (*itr != 0)
        {
            itr += ++soldierCount;
        }

        if (rowIndex < k)
            weakestRowsQueue.push(std::make_pair(rowIndex, soldierCount));
        else if (!weakestRowsQueue.empty() && soldierCount < weakestRowsQueue.top().second){
            weakestRowsQueue.pop();
            weakestRowsQueue.push(std::make_pair(rowIndex, soldierCount));
        }
    }

    std::vector<int> kWeakestIndices;
    while (!weakestRowsQueue.empty())
    {
        kWeakestIndices.emplace_back(weakestRowsQueue.top().first);
        weakestRowsQueue.pop();
    }
    std::reverse(kWeakestIndices.begin(), kWeakestIndices.end());
    
    return kWeakestIndices;   
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter top weakest rows number as program arg"<<std::endl;
        return -1;
    }

    int k = std::stoi(argv[1]);
    std::vector<std::vector<int>> mat = {{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}};
    std::cout<<std::to_string(k)+" weakest row indices are: "<<std::endl<<kWeakestRows(mat, k)<<std::endl;

    return 0;
}