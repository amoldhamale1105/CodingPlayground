#include <iostream>
#include <vector>
#include <queue>
#include <ComplexObjectStream.hpp>

std::vector<char> firstnonrepeating(const std::vector<char>& str)
{
    std::queue<char> uniqueChars, helperQueue;
    std::vector<char> output;
    char lastDiscardedChar{0};

    char firstChar = str.front();
    output.emplace_back(firstChar);
    uniqueChars.push(firstChar);

    for(auto itr = str.begin()+1; itr != str.end(); ++itr)
    {
        if (!uniqueChars.empty()){
            if (uniqueChars.front() == *itr){
                lastDiscardedChar = uniqueChars.front();
                uniqueChars.pop();
                output.emplace_back(uniqueChars.empty() ? '0' : uniqueChars.front());
            }
            else{
                char uniqueChar = uniqueChars.front();
                output.emplace_back(uniqueChar);
                helperQueue.push(uniqueChar);
                uniqueChars.pop();
                bool duplicateFound{false};

                while (!uniqueChars.empty())
                {
                    char currChar = uniqueChars.front();
                    uniqueChars.pop();
                    if (currChar == *itr)
                        duplicateFound = true;
                    else 
                        helperQueue.push(currChar);
                }
                if (!duplicateFound)
                    helperQueue.push(*itr);
                helperQueue.swap(uniqueChars);
            }
        }
        else{
            if (lastDiscardedChar == *itr){
                output.emplace_back('0');
            }
            else{
                output.emplace_back(*itr);
                uniqueChars.push(*itr);
            }
        }
    }

    return output;
}

int main()
{
    std::vector<char> string = {'a','a','a','c'};
    std::cout<<"Non rep char array: "<<firstnonrepeating(string)<<std::endl;
    return 0;
}