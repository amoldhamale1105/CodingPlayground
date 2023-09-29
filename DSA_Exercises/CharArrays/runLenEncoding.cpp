#include <iostream>

std::string compressString(const std::string &str)
{
    std::string compressedStr;
    int n = str.size();
    int freq = 1;
    
    compressedStr.push_back(str[0]);
    for(int i = 1; i < n; i++)
    {
        if (str[i] == str[i-1])
            freq++;
        else{
            compressedStr.append(std::to_string(freq));
            compressedStr.push_back(str[i]);
            freq = 1;
        }
    }
    compressedStr.append(std::to_string(freq));

    return compressedStr.length() < str.length() ? compressedStr : str;
}

int main()
{
    std::string origStr = "bbbaaaadexxxxxx";
    //std::string origStr = "abc";
    std::cout<<"Compressed string: "<<compressString(origStr)<<std::endl;
    return 0;
}