#include <iostream>

static int earthLevel(const int& k)
{
    int steps{0};
    int level = k;

    while (level > 0)
    {
        steps++;
        level &= (level - 1);
    }
    
    return steps;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter 1 arg for level for this program and relaunch"<<std::endl;
        return -1;
    }

    std::cout<<"Min steps required: "<<earthLevel(std::stoi(argv[1]))<<std::endl;
    return 0;
}