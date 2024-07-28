#include <iostream>
#include <vector>
#include <set>
#include <ComplexObjectStream.hpp>

void sortedPermHelper(std::set<std::string>& permSet, std::string& str, int idx)
{
    if (idx == str.length()){
        permSet.insert(str);
        return;
    }

    // Swap out the first letter with all subsequent letters in the string
    for(int i = idx; i < str.length(); i++)
    {
        if (i > idx)
            std::swap(str[i], str[idx]);
        sortedPermHelper(permSet, str, idx+1);
        // Undo swap for next branch
        if (i > idx)
            std::swap(str[i], str[idx]);
    }
}

std::vector<std::string> findSortedPermutations(std::string s)
{
    std::set<std::string> permSet{};
    sortedPermHelper(permSet, s, 0);
    std::vector<std::string> perms(permSet.begin(), permSet.end());
    return perms;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter string with less than 11 chars as program arg"<<std::endl;
        return 1;
    }
    std::cout<<"sorted permutations: "<<findSortedPermutations(argv[1])<<std::endl;
    return 0;
}