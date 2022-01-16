#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

static int compress(std::vector<char>& chars)
{
    int repCount{1}, i{0};
    std::vector<char>::iterator itr, it;
    
    for(itr = chars.begin(); itr != chars.end(); ++itr)
    {
        if(itr == chars.begin())
            continue;
        if(*itr == *(itr-1))
            repCount++;
        else{
            if(repCount == 1)
                continue;
            std::vector<char>::iterator nextElementItr = chars.erase(itr-(repCount-1), itr);
            while(repCount /= std::pow(10,i))
            {
                it = chars.insert(nextElementItr, (repCount%10)+48);
                i++;
            }
            std::reverse(nextElementItr, it+i);
            itr = it + i;
            repCount = 1;
            i = 0;
        }
    }

    if(itr == chars.end() && repCount > 1){
        chars.erase(itr-(repCount-1), chars.end());
        while(repCount /= std::pow(10,i))
        {
            chars.push_back((repCount%10)+48);
            i++;
        }
        std::reverse(chars.end()-i, chars.end());
    }
    return chars.size();
}

int main()
{
    std::vector<char> vec = {'a','a','b','b','c','c','c'};
    std::vector<char> vec2 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    std::cout<<"compressed length: "<<compress(vec)<<std::endl;
    for(const char& ch : vec)
        std::cout<<ch<<" ";
    std::cout<<std::endl;
    return 0;
}
