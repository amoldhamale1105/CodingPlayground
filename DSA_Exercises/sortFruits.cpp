#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

union variant
{
    char name[50];
    int price;

    variant() 
    {
        memset(this, 0, sizeof(variant));
    }
    ~variant() {}
    void operator=(const variant& other)
    {
        memcpy(this, &other, sizeof(variant));
    }
};

std::ostream& operator<<(std::ostream& stream, const std::vector<std::pair<std::string, int>>& vec)
{
    for(const std::pair<std::string,int>& myPair : vec)
    {
        stream << myPair.first << "," << myPair.second<<std::endl;
    }
    return stream;
}

static std::vector<std::pair<std::string, int>> sortFruits(const std::vector<std::pair<std::string,int>>& v, const std::string& S)
{
    std::vector<std::pair<std::string, int>> sortedFruits = v;
    int n = v.size();
    variant minEntity;

    for(auto i = 0; i < n-1; ++i)
    {
        if (S == "name")
            strcpy(minEntity.name, sortedFruits[i].first.c_str());
        else
            minEntity.price = sortedFruits[i].second;

        for(auto j = i+1; j < n; ++j)
        {
            variant entity;
            if (S == "name")
                strcpy(entity.name, sortedFruits[j].first.c_str());
            else
                entity.price = sortedFruits[j].second;

            if ((S == "name" && strcmp(entity.name, minEntity.name) < 0) || (S == "price" && entity.price < minEntity.price)){
                std::iter_swap(sortedFruits.begin()+i, sortedFruits.begin()+j);
                minEntity = entity;
            }
        }
    }

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