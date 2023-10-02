#include <iostream>

std::string breakPalindrome(std::string palindrome)
{
    int n = palindrome.size();
    if (n == 1)
        return "";
    for(int i = 0; i < n/2; i++)
    {
        if (palindrome[i] != 'a'){
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome.back() = 'b';
    return palindrome;
}

int main()
{
    //std::string palindrome = "abccba";
    //std::string palindrome = "a";
    //std::string palindrome = "aa";
    std::string palindrome = "aba";
    std::cout<<"lexicographically smallest broken palindrome: "<<breakPalindrome(palindrome)<<std::endl;
    return 0;
}