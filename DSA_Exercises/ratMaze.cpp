#include <iostream>
#include <vector>

enum Move_E
{
    DOWN=0,
    RIGHT,
    LEFT,
    UP
};

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

static bool canMoveDown(const int& rowIndex, const int& colIndex, const std::vector<std::string>& maze)
{
    int mazeHeight = maze.size();
    if (rowIndex+1 >= mazeHeight || maze[rowIndex+1].at(colIndex) == 'X')
        return false;
    return true;
}

static bool canMoveRight(const int& rowIndex, const int& colIndex, const std::vector<std::string>& maze)
{
    int mazeWidth = maze[0].length();
    if (colIndex+1 >= mazeWidth || maze[rowIndex].at(colIndex+1) == 'X')
        return false;
    return true;
}

static bool canMoveLeft(const int& rowIndex, const int& colIndex, const std::vector<std::string>& maze)
{
    if (colIndex-1 < 0 || maze[rowIndex].at(colIndex-1) == 'X')
        return false;
    return true;
}

static bool canMoveUp(const int& rowIndex, const int& colIndex, const std::vector<std::string>& maze)
{
    if (rowIndex-1 < 0 || maze[rowIndex-1].at(colIndex) == 'X')
        return false;
    return true;
}

static std::vector<std::vector<int>> ratAndMice(const std::vector<std::string>& arr)
{
    static int mazeWidth = arr[0].length();
    static int mazeHeight = arr.size();
    static int row{0}, col{0};
    static Move_E lastMove{Move_E::RIGHT};

    static std::vector<std::vector<int>> solution(mazeHeight, std::vector<int>(mazeWidth));

    //Base case
    // Target reached at the bottom right corner of the maze
    if (row == mazeHeight-1 && col == mazeWidth-1){
        solution[0][0] = 1;
        return solution;
    }
    
    //Rec case
    // Highest priority will be to move down and to the right for fastest descent towards the target
    // Followed by movement to the left and lowest to moving up which is in opposite direction
    switch (lastMove)
    {
    case Move_E::DOWN:
        if (canMoveDown(row, col, arr)){
            row++;
            lastMove = Move_E::DOWN;
        }
        else if (canMoveRight(row, col, arr)){
            col++;
            lastMove = Move_E::RIGHT;
        }
        else if (canMoveLeft(row, col, arr)){
            col--;
            lastMove = Move_E::LEFT;
        }
        break;

    case Move_E::RIGHT:
        if (canMoveDown(row, col, arr)){
            row++;
            lastMove = Move_E::DOWN;
        }
        else if (canMoveRight(row, col, arr)){
            col++;
            lastMove = Move_E::RIGHT;
        }
        else if (canMoveUp(row, col, arr)){
            row--;
            lastMove = Move_E::UP;
        }
        break;
    
    case Move_E::LEFT:
        if (canMoveDown(row, col, arr)){
            row++;
            lastMove = Move_E::DOWN;
        }
        else if (canMoveLeft(row, col, arr)){
            col--;
            lastMove = Move_E::LEFT;
        }
        else if (canMoveUp(row, col, arr)){
            row--;
            lastMove = Move_E::UP;
        }
        break;

    case Move_E::UP:
        if (canMoveRight(row, col, arr)){
            col++;
            lastMove = Move_E::RIGHT;
        }
        else if (canMoveLeft(row, col, arr)){
            col--;
            lastMove = Move_E::LEFT;
        }
        else if (canMoveUp(row, col, arr)){
            row--;
            lastMove = Move_E::UP;
        }
        break;
    
    default:
        break;
    }

    solution[row][col] = 1;
    return ratAndMice(arr);
}

int main()
{
    std::vector<std::string> maze = {"OXOO",
                                     "OOOX",
                                     "XOXO",
                                     "XOOX",
                                     "XXOO"};
    std::cout<<"Possible exit path for the rat:"<<std::endl<<ratAndMice(maze);

    return 0;
}