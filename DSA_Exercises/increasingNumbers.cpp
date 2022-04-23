#include <iostream>
#include <vector>
#include <algorithm>

static std::vector<int> increasingNumbers(const int& N)
{
    static std::vector<int> incSeries;

    if (N == 0){
        std::vector<int> series = incSeries;
        if (!incSeries.empty())
            incSeries.clear();
        std::reverse(series.begin(), series.end());
        return series;
    }

    incSeries.emplace_back(N);

    return increasingNumbers(N-1);
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please feed number as upper bound of the series to program"<<std::endl;
        return -1;
    }

    for(const int& num : increasingNumbers(std::stoi(argv[1])))
    {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;

    return 0;
}