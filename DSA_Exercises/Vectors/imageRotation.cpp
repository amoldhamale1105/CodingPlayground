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

static void rotate(std::vector<std::vector<int>>& matrix)
{
    int length = matrix.size();
    int stride{0};
    
    for(auto i = 0; i < length && length > 1; ++i)
    {
        stride = length-1;
        for(auto j = 0; j < length-1; ++j)
        {
            //Swap successive elements at a stride of length-1 in counterclockwise fashion
            //If the same swap sequence is reversed, the image rotation will be -90 deg
            std::swap(matrix[i][j+i], matrix[stride-j+i][i]);
            std::swap(matrix[stride+i][stride-j+i], matrix[stride-j+i][i]);
            std::swap(matrix[j+i][stride+i], matrix[stride+i][stride-j+i]);
        }
        //Peel off the outer layer resulting in a submatrix with dimentions n-2 x n-2
        length -= 2;
    }
}

int main(int argc, char** argv)
{
    //std::vector<std::vector<int>> myImageMat = {{1,2,3,10}, {4,5,6,11}, {7,8,9,12}, {13,14,15,16}};
    std::vector<std::vector<int>> myImageMat = {{1,2,3}, {4,5,6}, {7,8,9}};
    rotate(myImageMat);
    std::cout<<"rotated image:\n"<<myImageMat;
    return 0;
}