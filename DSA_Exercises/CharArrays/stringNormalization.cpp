#include <iostream>

std::string normalize(const std::string &sentence)
{
    std::string copy = sentence;
    int n = sentence.length();
    const int caseOff = 'a'-'A';
    
    for(int i = 0; i < n; i++)
    {
        if (copy[i] == ' ')
            continue;
        else{
            if (i == 0 || copy[i-1] == ' '){
                if (copy[i] >= 'a' && copy[i] <= 'z')
                    copy[i] -= caseOff;
            }
            else{
                if (copy[i] >= 'A' && copy[i] <= 'Z')
                    copy[i] += caseOff;
            }
        }
    }

    return copy;
}

int main()
{
    std::string sentence;
    std::cout<<"Enter a sentence with words separated by spaces:"<<std::endl;
    std::getline(std::cin, sentence);
    std::cout<<"Normalized sentence:"<<std::endl<<normalize(sentence)<<std::endl;
    return 0;
}