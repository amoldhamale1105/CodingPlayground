#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

bool validEntry(const std::vector<std::vector<int>>& input, int row, int col, int entry)
{
    // Check for matching entry in row
    for(int i = 0; i < 9; i++)
    {
        if (i == col)
            continue;
        if (input[row][i] == entry)
            return false;
    }
    // Check for matching entry in column
    for(int i = 0; i < 9; i++)
    {
        if (i == row)
            continue;
        if (input[i][col] == entry)
            return false;
    }
    // Check in enclosed sub-matrix
    for(int i = row-row%3; i < row-row%3+3; i++)
    {
        if (i == row)
            continue;
        for(int j = col-col%3; j < col-col%3+3; j++)
        {
            // No need to check in same row or col since that has been covered in prev checks
            if (j == col)
                continue;
            if (input[i][j] == entry)
                return false;
        }
    }
    return true;
}

bool sudokuHelper(std::vector<std::vector<int>>& input, int row, int col)
{
    if (row == 9)
        return true;

    if (col == 9)
        return sudokuHelper(input, row+1, 0);
    if (input[row][col] != 0)
        return sudokuHelper(input, row, col+1);

    // Try all possible entries for a given cell
    for(int entry = 1; entry <= 9; entry++)
    {
        if (validEntry(input, row, col, entry)){
            input[row][col] = entry;
            if (sudokuHelper(input, row, col+1))
                return true;
        }
    }
    // If no entry is valid
    input[row][col] = 0;
    return false;
}

std::vector<std::vector<int>> solveSudoku(std::vector<std::vector<int>> input)
{
    sudokuHelper(input, 0, 0);
    return input;
}

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> sudokuProb = {
        {0,3,0, 0,0,0, 9,0,0},
        {0,0,6, 0,0,0, 0,0,0},
        {0,0,0, 2,4,1, 0,3,0},
        {0,0,0, 9,0,0, 7,0,0},
        {0,0,0, 0,0,2, 0,0,4},
        {0,8,0, 0,7,0, 0,2,0},
        {8,5,0, 0,0,0, 0,0,0},
        {0,9,0, 7,0,4, 0,0,0},
        {0,0,0, 0,0,6, 0,0,1},
    };
    std::cout<<"sudoku solution:\n"<<solveSudoku(sudokuProb);
    return 0;
}