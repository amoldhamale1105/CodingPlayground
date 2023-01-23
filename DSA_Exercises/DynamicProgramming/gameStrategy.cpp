#include <iostream>
#include <vector>
#include <Profiler.h>

static int maxValueHelper(int left, int right, std::vector<std::vector<int>>& valuesMem, const std::vector<int>& values)
{
    PROFILE_FUNCTION();
    if (left > right)
        return 0;
    
    if (valuesMem[left][right])
        return valuesMem[left][right];

    int pickLeft = values[left] + maxValueHelper(left+2, right, valuesMem, values);
    int pickRight = values[right] + maxValueHelper(left, right-2, valuesMem, values);

    return valuesMem[left][right] = std::max(pickLeft, pickRight);
}

int MaxValue(const int& n, const std::vector<int>& v)
{
    PROFILE_FUNCTION();
    std::vector<std::vector<int>> valuesMem(n, std::vector<int>(n, 0));
    return maxValueHelper(0, v.size()-1, valuesMem, v);
}

int main()
{
    Instrumentor::Instance().beginSession("Game strategy profiling", "gameStrategy.json");
    std::vector<int> values = {1,2,3,4};
    std::cout<<"Max possible value for first player: "<<MaxValue(values.size(), values)<<std::endl;
    Instrumentor::Instance().endSession();
    return 0;
}