#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

static bool canPlace(const int& rowIndex, const int& colIndex, const std::vector<std::vector<int>>& board)
{
    int dim = board.size();

    //Check if a queen is already placed on the same column
    for (auto i = 0; i < dim; ++i)
    {
        if (board[i][colIndex])
            return false;
    }

    //Check if queen is placed on either diagonals
    int i = rowIndex;
    int j = colIndex;
    while(i >= 0 && j >= 0)
    {
        if (board[i--][j--])
            return false;
    }

    i = rowIndex;
    j = colIndex;
    while(i >= 0 && j < dim)
    {
        if (board[i--][j++])
            return false;
    }

    return true;
}

static int helper(const int& row, const int& n, std::vector<std::vector<int>>& board)
{
    //Base case
    if (row >= n){
        //Print possible solutions (optional)
        //std::cout<<board;
        return 1;
    }

    //Rec case
    int ways = 0;
    for(auto col = 0; col < n; ++col)
    {
        if (canPlace(row, col, board)){
            board[row][col] = 1;
            ways += helper(row+1, n, board);
            board[row][col] = 0;
        }
    }

    return ways;
}

static int nQueen(const int& n)
{
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    return helper(0, n, board);
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter the chessboard dimension as program arg"<<std::endl;
        return -1;
    }

    std::cout<<"Number of possible solutions: "<<nQueen(std::stoi(argv[1]))<<std::endl;

    return 0;
}