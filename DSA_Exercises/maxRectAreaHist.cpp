#include <iostream>
#include <vector>
#include <stack>

int getMaxArea(const std::vector<int>& hist)
{
    int n = hist.size();
    std::stack<int> bars;
    int maxArea{0}, index{0}, rectAreaIndex{0}, areaWithCurrBar{0};

    while (index < n)
    {
        if (bars.empty() || hist[index] >= hist[bars.top()])
            bars.push(index++);
        else{
            rectAreaIndex = bars.top();
            bars.pop();
            areaWithCurrBar = hist[rectAreaIndex] * (bars.empty() ? index : index - bars.top() - 1);
        }

        if (areaWithCurrBar > maxArea)
            maxArea = areaWithCurrBar;
    }

    while (!bars.empty())
    {
        rectAreaIndex = bars.top();
        bars.pop();
        areaWithCurrBar = hist[rectAreaIndex] * (bars.empty() ? index : index - bars.top() - 1);

        if (areaWithCurrBar > maxArea)
            maxArea = areaWithCurrBar;
    }
    
    return maxArea;
}

int main()
{
    std::vector<int> hist = {6,2,5,4,5,1,6};
    std::cout<<"Max area: "<<getMaxArea(hist)<<std::endl;
    return 0;
}