#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

static void merge(std::vector<int>& vec, const int& s, const int& e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;

    std::vector<int> temp;

    // Compare 2 partitions and tranfer the lower element to the temp vector
    while(i <= mid && j <= e)
    {
        if (vec[i] < vec[j]){
            temp.push_back(vec[i]);
            i++;
        }
        else{
            temp.push_back(vec[j]);
            j++;
        }
    }

    //Finish transferring over remaining elements from either partition
    while(i <= mid)
    {
        temp.push_back(vec[i++]);
    }
    while(j <= e)
    {
        temp.push_back(vec[j++]);
    }

    int k = 0;
    for (auto i = s; i <= e; ++i)
    {
        vec[i] = temp[k++];
    }
}

static void mergeSortVector(std::vector<int>& v, const int& s, const int& e)
{
    if (s >= e)
        return;

    int mid = (s+e)/2;
    mergeSortVector(v, s, mid);
    mergeSortVector(v, mid+1, e);

    return merge(v, s, e);
}

static std::vector<std::vector<int>> mergeSort(const int& m, const int& n, const std::vector<std::vector<int>>& v)
{
    std::vector<std::vector<int>> sortedVec = v;

    // Sort matrix row wise first
    for (auto i = 0; i < n; ++i)
    {
        mergeSortVector(sortedVec[i], 0, n-1);
    }

    // Sort column wise
    std::vector<std::vector<int>> colVec = sortedVec;
    for (auto j = 0; j < n; ++j)
    {
        for (auto i = 0; i < m; ++i)
        {
            colVec[j][i] = sortedVec[i][j];
        }
        mergeSortVector(colVec[j], 0, m-1);
    }
    
    // Take transpose of column matrix to get the final sorted matrix
    for (auto j = 0; j < n; ++j)
    {
        for (auto i = 0; i < m; ++i)
        {
            sortedVec[j][i] = colVec[i][j];
        }
    }

    return sortedVec;
}

int main()
{
    std::vector<std::vector<int>> mat = {{18,4,16,8},
                                         {23,13,20,11},
                                         {28,24,26,25},
                                         {1,30,15,19}};
    // std::vector<std::vector<int>> mat = {{18,9,11},
    //                                      {1,4,15},
    //                                      {13,23,20}};
    std::cout<<mergeSort(mat.size(), mat[0].size(), mat);

    return 0;
}