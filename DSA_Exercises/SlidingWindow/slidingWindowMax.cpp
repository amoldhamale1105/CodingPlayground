#include <iostream>
#include <vector>
#include <set>
#include <ComplexObjectStream.hpp>

std::vector<int> maxInWindow(const std::vector<int>& input, int k)
{
    std::vector<int> output;
    std::set<int> winElements;
    int start{0};

    for(int i = 0; i < k; i++)
    {
        winElements.insert(input[i]);
    }
    output.emplace_back(*--winElements.cend());
    while (start < input.size()-k)
    {
        winElements.erase(input[start]);
        winElements.insert(input[start+k]);
        output.emplace_back(*--winElements.cend());
        start++;
    }
    
    return output;
}

int main(int argc, char** argv)
{
    std::vector<int> input = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    if (argc < 2){
        std::cerr<<"Please enter window size less than "<<input.size()<<" as program arg"<<std::endl;
        return 1;
    }
    int winSize = std::stoi(argv[1]);
    std::cout<<"Max in contiguous windows of size "<<winSize<<": "<<maxInWindow(input, winSize)<<std::endl;
    return 0;
}