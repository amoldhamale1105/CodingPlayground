#include <iostream>
#include <vector>

void helper(const std::string& str, const std::vector<std::string>& dictionary, int& ways)
{
    int len = str.length();

    for(auto i = 1; i <= len; ++i)
    {
        std::string subStr = str.substr(0, i);
        bool wordFound{false};

        for(const std::string& word : dictionary)
        {
            if (word == subStr){
                wordFound = true;
                break;
            }
        }

        if (wordFound){
            if (i == len){
                ways++;
                return;
            }
            helper(str.substr(i, len-i), dictionary, ways);
        }
    }
}

static int wordBreak(const std::string& str, const std::vector<std::string>& dictionary)
{
    int ways = 0;
    helper(str, dictionary, ways);
    return ways;
}

int main()
{
    //std::string str = "ilikesamsungmobile";
    std::string str = "iloveonepieceandnaruto";
    //std::vector<std::string> dict = {"i", "like", "sam", "sung", "samsung", "mobile"};
    std::vector<std::string> dict = {"onepieceandnaruto","onepiece","and","naruto", "i", "love", "one", "piece"};

    std::cout<<"Total ways of breaking the sentence: "<<wordBreak(str, dict)<<std::endl;
    return 0;
}