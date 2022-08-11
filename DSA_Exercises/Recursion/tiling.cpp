#include <iostream>

static int tilingProblem(const int& n, const int& m)
{
    if (n == m)
        return 2;
    if (n < m)
        return 1;
    
    int ways = tilingProblem(n-1, m) + tilingProblem(n-m, m);

    return ways;
}

int main(int argc, char** argv)
{
    if (argc < 3){
        std::cerr<<"Please enter length and breadth of floor as program args"<<std::endl;
        return -1;
    }

    int n = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);

    std::cout<<"Ways in which floor can be covered with 1x"<<m<<" tiles: "<<tilingProblem(n, m)<<std::endl;

    return 0;
}