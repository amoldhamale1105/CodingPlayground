#include <iostream>
#include <vector>

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
	std::vector<int> span(1, 1);

    for(auto i = 0; i < n; ++i)
    {
        for(auto j = i; j > 0; --j)
        {
            if (stocks[j-1] > stocks[i]){
                span.emplace_back(i-j+1);
                break;
            }
        }
    }

    return span;
}

int main()
{
    std::vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};

    std::cout<<"Span: "<<stockSpanner(stocks)<<std::endl;

    return 0;
}