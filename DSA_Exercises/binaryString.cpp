#include <iostream>
#include <math.h>

static int binaryToDecimal(std::string s)
{
    int bits = s.length();
    int output{0};
    for(int i = 0; i < bits; i++)
    {
        output += ((int)s[i]-48) * std::pow(2, (bits-1) - i);
    }
    return output;
}

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout<<"Please pass a string arg to the program"<<std::endl;
        return 0;
    }

    std::cout<<"decimal equivalent: "<<binaryToDecimal(std::string(argv[1]))<<std::endl;

    return 0;
}
