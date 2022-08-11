#include <iostream>
#include <vector>

std::vector<std::vector<int>> printPascal(int n)
{
    std::vector<std::vector<int>> pT = {{1}};
        if (n <= 1)
                return pT;
        for(int i = 0; i < n-1; i++)
        {
                std::vector<int> coeffRow = {1};
                int prevRowSize = pT[i].size();
                if (prevRowSize > 1){
                        for(int j = 1; j < prevRowSize; j++)
                        {
                                coeffRow.emplace_back(pT[i][j] + pT[i][j-1]);
                        }
                }
                coeffRow.emplace_back(1);
                pT.emplace_back(coeffRow);
        }
        return pT;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter one integer argument to this program"<<std::endl;
        return -1;
    }

    std::vector<std::vector<int>> pascalTri = printPascal(std::stoi(argv[1]));

    for(const std::vector<int>& vec : pascalTri)
    {
        for(const int& coeff : vec)
        {
            std::cout<<coeff<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
