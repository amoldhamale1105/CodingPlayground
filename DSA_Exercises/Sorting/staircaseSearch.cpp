#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

void searchHelper(int m, int n, int i, int j, const std::vector<std::vector<int>>& vec, std::pair<int,int>& idx, int k)
{
    //base case
    if (i >= m || j >= n)
        return;
    if (idx.first != -1)
        return;
    if (vec[i][j] == k){
        idx = std::make_pair(i, j);
        return;
    }
        
    //rec case
    searchHelper(m, n, i, j+1, vec, idx, k);
    searchHelper(m, n, i+1, j, vec, idx, k);
}

std::pair<int,int> search(int m, int n, std::vector<std::vector<int>> v, int k)
{
    std::pair<int,int> index = {-1,-1};
    searchHelper(m, n, 0, 0, v, index, k);
    return index;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter number to be searched as program arg"<<std::endl;
        return 1;
    }
    std::vector<std::vector<int>> mat = {
        {1,4,9},
        {2,5,10},
        {6,7,11}
    };
    std::cout<<"Index of provided number: "<<search(3, 3, mat, std::stoi(argv[1]))<<std::endl;
    return 0;
}