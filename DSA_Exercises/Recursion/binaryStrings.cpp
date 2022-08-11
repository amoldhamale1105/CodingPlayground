#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

static std::string decimalToBinary(const int& decimal, const int& numofBits)
{
    int number = decimal;
    int bitCount{0};
    std::string binary;
    while(number > 0)
    {
        if (number & 1)
            binary.append("1");
        else
            binary.append("0");
        number >>= 1;
        bitCount++;
    }
    while(bitCount++ < numofBits)
    {
        binary.append("0");
    }
    std::reverse(binary.begin(), binary.end());

    return binary;
}

static std::vector<std::string> binaryStrings(const int& n)
{
    std::vector<std::string> output;
    int upperBound = std::pow(2, n);

    for(auto i = 0; i < upperBound; ++i)
    {
        if (!(i & (i >> 1)))
            output.emplace_back(decimalToBinary(i, n));
    }

    return output;
}

int main(int argc, char** argv)
{
    if (argc < 2 || std::stoi(argv[1]) > 12){
        std::cerr<<"Please enter integer <=12 as program arg."<<std::endl;
        return -1;
    }

    //std::cout<<decimalToBinary(std::stoi(argv[2]))<<std::endl;

    for(const std::string& str : binaryStrings(std::stoi(argv[1])))
    {
        std::cout<<str<<std::endl;
    }

    return 0;
}