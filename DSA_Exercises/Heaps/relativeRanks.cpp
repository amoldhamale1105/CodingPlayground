#include <iostream>
#include <vector>
#include <queue>
#include <ComplexObjectStream.hpp>

class ScoreCompare
{
public:
    bool operator()(const std::pair<int,int>& p1, const std::pair<int,int>& p2)
    {
        return p1.second < p2.second;
    }
};

static std::string getRankTitle(const int& rankNum)
{
    std::string title = "";
    switch (rankNum)
    {
    case 1:
        title = "Gold Medal";
        break;
    case 2:
        title = "Silver Medal";
        break;
    case 3:
        title = "Bronze Medal";
        break;
    default:
        title = std::to_string(rankNum);
        break;
    }

    return title;
}   

static std::vector<std::string> findRelativeRanks(const std::vector<int>& score)
{
    int athleteCount = score.size();
    std::vector<std::string> ranks(athleteCount);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, ScoreCompare> rankQueue;

    for(auto i = 0; i < athleteCount; i++)
    {
        rankQueue.push(std::make_pair(i, score[i]));
    }
    for(auto i = 0; i < athleteCount; i++)
    {
        ranks[rankQueue.top().first] = getRankTitle(i+1);
        rankQueue.pop();
    }

    return ranks;
}

int main()
{
    std::vector<int> score = {5,4,7,2,1};
    std::cout<<"Ranks: "<<std::endl<<findRelativeRanks(score)<<std::endl;
    return 0;
}