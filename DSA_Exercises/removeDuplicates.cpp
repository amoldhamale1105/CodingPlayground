#include <iostream>
#include <string>
#include <bits/stdc++.h>

static std::string removeDuplicate(std::string s)
{
    std::set<char> uniqueChars;
    std::string output;
    for(int i = 0; i < s.length(); i++)
    {
        uniqueChars.insert(s[i]);
    }
    for(auto itr = uniqueChars.begin(); itr != uniqueChars.end(); ++itr)
    {
        output += *itr;
    }
    return output;
}

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout<<"Please pass a string arg to the program"<<std::endl;
        return 0;
    }
    std::cout<<removeDuplicate(std::string(argv[1]))<<std::endl;
    return 0;
}
