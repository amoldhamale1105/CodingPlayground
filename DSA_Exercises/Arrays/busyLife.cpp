#include <iostream>
#include <vector>
#include <algorithm>

// Maximum time complexity O(nLogn)
static int countActivites(std::vector<std::pair<int,int>> activities)
{
    // No specialization required since pairs are sorted by first element by default
    std::sort(activities.begin(), activities.end());
    // keep track of the last start time which yeilds max possible activities therefrom
    std::pair<int,int> maxHitherto = {INT32_MAX,0};
    for(auto itr = activities.end()-1; itr >= activities.begin(); --itr)
    {
        // Increment activity count if current acitivity end time occurs before the max activities start time so far
        if (itr->second <= maxHitherto.first){
            maxHitherto.first = itr->first;
            maxHitherto.second++;
        }
    }
    
    return maxHitherto.second;
}

int main()
{
    std::vector<std::pair<int,int>> activities = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    std::cout<<"max number of activities possible: "<<countActivites(activities)<<std::endl;
    return 0;
}