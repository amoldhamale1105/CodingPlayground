#include <vector>
#include <iostream>

static int vacationHelper(int day, int prevActivity, const std::vector<std::vector<int>>& activityMat, std::vector<std::vector<int>>& activityMem)
{
    if (day >= activityMat.front().size())
        return 0;
    
    if (activityMem[prevActivity][day])
        return activityMem[prevActivity][day];
    
    int maxPoints{0};

    for(auto i = 0; i < activityMat.size(); i++)
    {
        if (i == prevActivity && day > 0)
            continue;
        maxPoints = std::max(maxPoints, activityMat[i][day] + vacationHelper(day+1, i, activityMat, activityMem));
    }

    return activityMem[prevActivity][day] = maxPoints;
}

int vacation(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c)
{
    std::vector<std::vector<int>> activityMat;
    std::vector<std::vector<int>> activityMem(a.size(), std::vector<int>(a.size(), 0));
    activityMat.emplace_back(a);
    activityMat.emplace_back(b);
    activityMat.emplace_back(c);
    return vacationHelper(0, 0, activityMat, activityMem);
}

int main()
{
    std::vector<int> swimPoints = {10,20,30};
    std::vector<int> bugPoints = {40,50,60};
    std::vector<int> homeworkPoints = {70,80,90};

    std::cout<<"Maximum possible happiness points: "<<vacation(swimPoints, bugPoints, homeworkPoints)<<std::endl;
    return 0;
}