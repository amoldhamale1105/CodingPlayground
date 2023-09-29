#include <iostream>
#include <vector>
#include <algorithm>

bool lexCompare(const std::string& s1, const std::string& s2)
{
    return s1+s2 > s2+s1;
}

std::string concatenate(const std::vector<int>& numbers)
{
    std::vector<std::string> strNums;
    int n = numbers.size();
    std::string largest;
    
    for(const int& num : numbers)
    {
        strNums.emplace_back(std::to_string(num));
    }
    std::sort(strNums.begin(), strNums.end(), lexCompare);
    for(const std::string& strNum : strNums)
    {
        largest += strNum;
    }
    
    return largest;
}

int main()
{
    std::vector<int> numbers = {10,11,20,30,3};
    std::cout<<"Biggest lexicographical number: "<<concatenate(numbers)<<std::endl;
    return 0;
}