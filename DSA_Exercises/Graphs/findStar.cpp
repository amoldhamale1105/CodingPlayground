#include <vector>
#include <iostream>

int findCenter(const std::vector<std::vector<int>>& v)
{
    std::vector<int> firstPair = v.front();
    std::vector<int> lastPair = v.back();
    int firstNode = firstPair.front();
    int secondNode = firstPair.back();

    return (lastPair.front() == firstNode) || (lastPair.back() == firstNode) ? firstNode : secondNode;
}

int main()
{
    std::vector<std::vector<int>> starGraph = {{1,2},{2,3},{4,2}};
    std::cout<<"star center: "<<findCenter(starGraph)<<std::endl;
    return 0;
}