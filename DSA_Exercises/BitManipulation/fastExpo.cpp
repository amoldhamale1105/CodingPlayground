#include <iostream>

size_t fastExpo(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc < 3){
        std::cerr<<"Please enter base and exponent as program args"<<std::endl;
        return 1;
    }
    int base = std::stoi(argv[1]);
    int exp = std::stoi(argv[2]);
    std::cout<<base<<" to the power of "<<exp<<" is "<<fastExpo(base, exp)<<std::endl;
    return 0;
}