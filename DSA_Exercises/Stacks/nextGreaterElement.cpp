#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <ComplexObjectStream.hpp>

std::vector<int> nextGreaterElement(const std::vector<int>& v)
{
    int n = v.size();
    std::stack<int> stack;
    std::vector<int> nextGreaterContainer;

    for(auto i = n-1; i >= 0; --i)
    {
        while (!stack.empty() && stack.top() <= v[i])
        {
            stack.pop();
        }
        if (stack.empty())
            nextGreaterContainer.emplace_back(-1);
        else
            nextGreaterContainer.emplace_back(stack.top());

        stack.push(v[i]);
    }

    std::reverse(nextGreaterContainer.begin(), nextGreaterContainer.end());

    return nextGreaterContainer;
}

int main()
{
    std::vector<int> vec = {1,6,2,7,25};
    std::cout<<"Next greater element set: "<<nextGreaterElement(vec)<<std::endl;
    return 0;
}