#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

static bool isPalindrome(const std::string& str)
{
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());
    if (!strcmp(temp.c_str(), str.c_str()))
        return true;
    return false;

}

int main(int argc, char* argv[])
{
    std::string str = argv[1];
    std::cout<<isPalindrome(str)<<std::endl; 
    return 0;
}
