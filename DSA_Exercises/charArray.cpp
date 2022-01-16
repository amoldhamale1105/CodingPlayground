#include <iostream>
#include <cstring>

int main()
{
    char sentence[1000];

    char temp = std::cin.get();
    char* str = sentence;
    while(temp != '#')
    {
        *str++ = temp;
        temp = std::cin.get();
    }
    *str = 0;
    std::cout<<sentence<<strlen(sentence)<<std::endl;

    return 0;
}
