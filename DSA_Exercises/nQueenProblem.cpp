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

static int nQueen(const int& n)
{
    static std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    static int row{0};

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
            row++;
            ways += nQueen(n);
            row--;
            board[row][col] = 0;
        }
    }

    return ways;
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