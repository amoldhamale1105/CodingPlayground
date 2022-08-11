#include <iostream>
#include <vector>

static std::vector<std::pair<int, int>> sortCartesian(std::vector<std::pair<int, int>> v)
{
    int N = v.size();
    int minCoordPos;

    for(int i = 0; i < N-1; i++)
    {
        minCoordPos = i;
        for(int j = i; j < N; j++)
        {
            if((v[j].first < v[minCoordPos].first) ||
                (v[j].first == v[minCoordPos].first) && (v[j].second < v[minCoordPos].second))
                minCoordPos = j;
        }
        std::swap(v[i], v[minCoordPos]);
    }
    return v;
}

int main()
{
    std::vector<std::pair<int,int>> vec = {{3,4}, {2,3}, {3,7}, {1,5}, {3,4}};
    std::vector<std::pair<int,int>> sortedCoords = sortCartesian(vec);
    for(const std::pair<int,int>& coord : sortedCoords)
        std::cout<<"("<<coord.first<<","<<coord.second<<") ";
    std::cout<<std::endl;
    return 0;
}
