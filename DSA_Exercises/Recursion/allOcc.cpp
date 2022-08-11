#include <iostream>
#include <vector>

static std::vector<int> findAllOccurences(const int& k, const std::vector<int>& v)
{
    static std::vector<int> occIndices{-1};
    static int index{0};

    //base case
    if (v.size() == 0){
        std::vector<int> indices = occIndices;
        if (occIndices[0] != -1){
            occIndices.clear();
            occIndices.push_back(-1);
        }
        index = 0;
        return indices;
    }
    
    //Recursive case
    if (v[0] == k){
        if (occIndices[0] == -1)
            occIndices[0] = index;
        else
            occIndices.push_back(index);
    }
    index++;

    return findAllOccurences(k, std::vector<int>(v.begin()+1, v.end()));
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please feed number to check as arg to program"<<std::endl;
        return -1;
    }
    std::vector<int> vec = {1,2,5,3,1,2,3,8,6,3,6,7,9};
    //std::vector<int> vec = {3,3,3,3};

    for(const int& num : findAllOccurences(std::stoi(argv[1]), vec))
    {
        std::cout<<num<<" ";
    }

    std::cout<<std::endl;

    return 0;
}