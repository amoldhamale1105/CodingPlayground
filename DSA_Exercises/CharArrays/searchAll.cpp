#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

std::vector<int> stringSearch(const std::string& big, const std::string& small)
{
    //store the occurrences in the result vector
    std::vector<int> result = {};
    int next = 0;
    
    while ((next = big.find(small, next+1)) != std::string::npos)
    {
        result.emplace_back(next);
    }

    return result;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter string to be searched as program argument"<<std::endl;
        return EXIT_FAILURE;
    }
    std::string bigString = "I liked the movie, acting in movie was great!";
    std::cout<<"Occurence indices: "<<stringSearch(bigString, argv[1])<<std::endl;
    return 0;
}