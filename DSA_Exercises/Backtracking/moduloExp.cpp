#include <iostream>

#define MOD 1000000007

long long int powerModulo(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (b & 1)
        return ((powerModulo(((a%MOD)*(a%MOD))%MOD, b>>1)%MOD) * (a%MOD))%MOD;
    return powerModulo(((a%MOD)*(a%MOD))%MOD, b>>1);
}

int main(int argc, char** argv)
{
    if (argc < 3){
        std::cerr<<"Enter 2 integers as input"<<std::endl;
        return 1;
    }
    std::cout<<"modulo exponentiation: "<<powerModulo(std::stoi(argv[1]), std::stoi(argv[2]))<<std::endl;
    return 0;
}