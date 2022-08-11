#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

static std::vector<std::vector<int>> makeZeroes(const std::vector<std::vector<int>>& arr)
{
    std::vector<std::vector<int>> zeroedArr = arr;
    std::set<int> cursedColIndex;
    bool rowContainsZero{false};

    for(std::vector<int>& vec : zeroedArr)
    {
        for(auto index = 0; index < vec.size(); ++index)
        {
            if (vec[index] == 0){
                cursedColIndex.insert(index);
                rowContainsZero = true;
            }
        }

        if (rowContainsZero){
            std::fill(vec.begin(), vec.end(), 0);
            rowContainsZero = false;
        }
    }

    for(auto index = 0; index < zeroedArr.size(); ++index)
    {
        for(const int& cursedIndex : cursedColIndex)
        {
            zeroedArr[index][cursedIndex] = 0;
        }
    }

    return zeroedArr;
}

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> arr = {{5,4,3,9}, {2,0,7,6}, {1,3,4,0}, {9,8,3,4}};
    std::cout<<makeZeroes(arr);
    return 0;
}