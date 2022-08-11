#include <iostream>

static int friendsPairing(const int& n)
{
    //Base case
    if (n == 0 || n == 1)
        return 1;

    //recursive case
    int possibilities = (n-1) * friendsPairing(n-2) + friendsPairing(n-1);
    return possibilities;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter number of friends as program arg."<<std::endl;
        return -1;
    }

    std::cout<<"Number of ways friends be single or paired: "<<friendsPairing(std::stoi(argv[1]))<<std::endl;

    return 0;
}