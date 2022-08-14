#include <iostream>
#include <vector>
#include <algorithm>
#include <ComplexObjectStream.hpp>
#ifdef CXX17
#include <variant>
#endif

static std::vector<std::pair<std::string, int>> sortFruits(const std::vector<std::pair<std::string,int>>& v, const std::string& S)
{
    std::vector<std::pair<std::string, int>> sortedFruits = v;
    int n = v.size();
#ifdef CXX17
    std::variant<std::string, int> minEntity;

    for(auto i = 0; i < n-1; ++i)
    {
        if (S == "name")
            minEntity = sortedFruits[i].first;
        else
            minEntity = sortedFruits[i].second;
        for(auto j = i+1; j < n; ++j)
        {
            std::variant<std::string, int> entity;
            if (S == "name")
                entity = sortedFruits[j].first;
            else
                entity = sortedFruits[j].second;
            
            if (entity < minEntity){
                std::iter_swap(sortedFruits.begin()+i, sortedFruits.begin()+j);
                minEntity = entity;
            }
        }
    }
#endif
    return sortedFruits;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter sort arg for this program as either name or price"<<std::endl;
        return -1;
    }
    std::vector<std::pair<std::string, int>> fruits = {{"Mango",100}, {"Guava",70}, {"Grapes",40}, {"Apple",60}, {"Banana",30}};
    std::cout<<sortFruits(fruits, argv[1]);
    return 0;
}