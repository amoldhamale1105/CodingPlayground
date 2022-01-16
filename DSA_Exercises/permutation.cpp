#include <iostream>
#include <string>
#include<bits/stdc++.h>

bool arePermutation(std::string A, std::string B)
{
    if(A.length() != B.length())
        return false;
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    return strcmp(A.c_str(), B.c_str()) == 0;
}

int main(int argc, char** argv)
{
    std::string str1(argv[1]);
    std::string str2(argv[2]);
    std::cout<<"is permutation: "<<arePermutation(str1, str2)<<std::endl;
    return 0;
}
