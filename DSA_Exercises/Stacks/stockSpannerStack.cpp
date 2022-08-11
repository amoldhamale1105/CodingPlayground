#include <iostream>
#include <vector>
#include <stack>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
    stream <<"[";
    for(const int& num : vec)
    {
        stream << num << " ";
    }
    stream<<'\b';
    stream<<"]";
    
    return stream;
}

std::vector<int> stockSpanner(const std::vector<int> &stocks)
{
    int n = stocks.size();
    std::stack<int> spanStack;
    std::vector<int> span{};
    int prevHighIndex{0};

    for(auto i = 0; i < n; ++i)
    {
        while (!spanStack.empty() && stocks[spanStack.top()] <= stocks[i])
        {
            spanStack.pop();
        }
        if (spanStack.empty())
            span.emplace_back(i+1);
        else{
            prevHighIndex = spanStack.top();
            span.emplace_back(i - prevHighIndex);
        }

        spanStack.push(i);
    }

    return span;
}

int main()
{
    std::vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};

    std::cout<<"Span: "<<stockSpanner(stocks)<<std::endl;

    return 0;
}