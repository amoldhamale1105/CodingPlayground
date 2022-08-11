#include <iostream>

static int power(const int& x, const int& y, const int& mod)
{
    int result{1};
    int base = x;
    int exp = y;

    while(exp > 0)
    {
        if (exp & 1)
            result = ((result % mod) * (base % mod)) % mod;
        base = ((base % mod) * (base % mod)) % mod;
        exp >>= 1;
    }

    return result % mod;
}

int main(int argc, char** argv)
{
    if (argc < 4){
        std::cerr<<"Please enter 3 args x, y and mod for this program and relaunch"<<std::endl;
        return -1;
    }

    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);
    int mod = std::stoi(argv[3]);

    std::cout<<"Result: "<<power(x, y, mod)<<std::endl;

    return 0;
}