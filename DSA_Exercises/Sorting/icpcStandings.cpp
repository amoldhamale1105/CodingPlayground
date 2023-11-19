#include <iostream>
#include <vector>

int badness(std::vector<std::pair<std::string,int>> teams)
{
    int minBadness{0};
    for(int i = 0; i < teams.size(); i++)
    {
        if (teams[i].second != i+1){
            if (teams[teams[i].second-1].second != teams[i].second)
                std::swap(teams[i], teams[teams[i].second-1]);
            minBadness += std::abs(i+1-teams[i].second);
        }
    }
    return minBadness;
}

int main()
{
    std::vector<std::pair<std::string,int>> ranklist = {
        {"WinOrBooze", 1},
        {"BallOfDuty", 2},
        {"WhoKnows", 2},
        {"BholeChature", 1},
        {"DCECoders", 5},
        {"StrangeCase", 7},
        {"WhoKnows", 7},
    };
    std::cout<<"Min badness: "<<badness(ranklist)<<std::endl;
    return 0;
}