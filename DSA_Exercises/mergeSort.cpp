#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<int>>& mat)
{
    for(const std::vector<int>& vec : mat)
    {
        for(const int& num : vec)
        {
            stream << num << " ";
        }
        stream<<std::endl;
    }
    return stream;
}

static std::vector<std::vector<int>> mergeSort(const int& m, const int& n, const std::vector<std::vector<int>>& v)
{
    std::vector<std::vector<int>> sortedVec = v;
    return sortedVec;
}

int main(int argc, char** argv)
{
    if (argc < 3){
        std::cerr<<"Please enter matrix dimensions as program args"<<std::endl;
        return -1;
    }

    std::vector<std::vector<int>> mat = {{18,4,16,8},
                                         {23,13,20,11},
                                         {28,24,26,25},
                                         {1,30,15,19}};
    std::cout<<mergeSort(std::stoi(argv[1]), std::stoi(argv[2]), mat);

    return 0;
}