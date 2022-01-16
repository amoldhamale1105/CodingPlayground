#include <iostream>
#include <string>
#include <vector>

static std::string vowel(std::string S)
{
    std::string output;
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] == 'a' | S[i] == 'e' | S[i] == 'i' | S[i] == 'o' | S[i] == 'u')
            output += S[i];
    }
    return output;
}

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout<<"Please pass a string arg to the program"<<std::endl;
        return 0;
    }

    std::cout<<"vowels in serial order: "<<vowel(std::string(argv[1]))<<std::endl;
    return 0;
}
