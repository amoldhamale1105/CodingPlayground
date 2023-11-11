#include <iostream>
#include <set>
#include <unordered_map>

std::string smallestWindow(const std::string& str)
{
    std::set<char> uniqueChars;
    std::unordered_map<char,int> windowChars;
    for(char ch : str)
    {
        uniqueChars.insert(ch);
    }
    int start{0}, end{0}, smallestStart{0}, count{0};
    int smallestLen = INT32_MAX, windowLen{0};

    while (end < str.length())
    {
        windowChars[str[end]]++;
        
        if (uniqueChars.count(str.at(end)) && windowChars[str[end]] <= uniqueChars.count(str.at(end)))
            count++;

        if (uniqueChars.size() == count){
            while (!uniqueChars.count(str[start]) || windowChars[str[start]] > uniqueChars.count(str.at(start)))
            {
                windowChars[str[start]]--;
                start++;
            }
            windowLen = end-start+1;
            if (windowLen < smallestLen){
                smallestLen = windowLen;
                smallestStart = start;
            }
        }
        end++;
    }
    
    return str.substr(smallestStart, smallestLen);
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter random string as program arg"<<std::endl;
        return 1;
    }
    std::cout<<"Smallest distinct letters window is: "<<smallestWindow(argv[1])<<std::endl;
    return 0;
}