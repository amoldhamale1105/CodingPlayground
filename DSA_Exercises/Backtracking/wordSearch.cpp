#include <iostream>
#include <vector>

static bool canMoveAtIndex(const std::vector<std::vector<char>>& board, const int& rowIndex, const int& colIndex, const int& wordIndex, const std::string& word)
{
    int m = board.size();
    int n = board[0].size();
    if (rowIndex > m-1 || rowIndex < 0 || colIndex > n-1 || colIndex < 0 || wordIndex >= word.length())
        return false;
    return board[rowIndex][colIndex] == word.at(wordIndex);
}

static bool wordSearchHelper(const std::vector<std::vector<char>>& inputBoard, std::vector<std::vector<char>>& traversedBoard, int row, int col, const std::string& word, int wordIndex)
{
    int m = inputBoard.size();
    int n = inputBoard[0].size();
    bool nextLetterFound{false};
    
    //Base case
    if (wordIndex >= word.length()-1 && traversedBoard[row][col] == word.at(wordIndex)){
        std::cout<<"letter found: "<<traversedBoard[row][col]<<" word index: "<<wordIndex<<" {i,j}:"<<"{"<<row<<","<<col<<"}"<<std::endl;
        return true;
    }
    if (row >= m)
        return false;

    //Rec case
    for(auto i = row; i < m; ++i)
    {
        for(auto j = col; j < n; ++j)
        {
            if (traversedBoard[i][j] == word.at(wordIndex)){
                std::cout<<"letter found: "<<traversedBoard[i][j]<<" word index: "<<wordIndex<<" {i,j}:"<<"{"<<i<<","<<j<<"}"<<std::endl;
                if (canMoveAtIndex(traversedBoard, i, j+1, wordIndex+1, word)){
                    nextLetterFound = true;
                    traversedBoard[i][j] = '\0';
                    bool furtherTraversalPossible = wordSearchHelper(inputBoard, traversedBoard, i, j+1, word, wordIndex+1);
                    if (furtherTraversalPossible)
                        return true;
                    traversedBoard[i][j] = inputBoard[i][j];
                    if (!furtherTraversalPossible && wordIndex > 0)
                        return false;
                }
                if (canMoveAtIndex(traversedBoard, i, j-1, wordIndex+1, word)){
                    nextLetterFound = true;
                    traversedBoard[i][j] = '\0';
                    bool furtherTraversalPossible = wordSearchHelper(inputBoard, traversedBoard, i, j-1, word, wordIndex+1);
                    if (furtherTraversalPossible)
                        return true;
                    traversedBoard[i][j] = inputBoard[i][j];
                    if (!furtherTraversalPossible && wordIndex > 0)
                        return false;
                }
                if (canMoveAtIndex(traversedBoard, i-1, j, wordIndex+1, word)){
                    nextLetterFound = true;
                    traversedBoard[i][j] = '\0';
                    bool furtherTraversalPossible = wordSearchHelper(inputBoard, traversedBoard, i-1, j, word, wordIndex+1);
                    if (furtherTraversalPossible)
                        return true;
                    traversedBoard[i][j] = inputBoard[i][j];
                    if (!furtherTraversalPossible && wordIndex > 0)
                        return false;
                }
                if (canMoveAtIndex(traversedBoard, i+1, j, wordIndex+1, word)){
                    nextLetterFound = true;
                    traversedBoard[i][j] = '\0';
                    bool furtherTraversalPossible = wordSearchHelper(inputBoard, traversedBoard, i+1, j, word, wordIndex+1);
                    if (furtherTraversalPossible)
                        return true;
                    traversedBoard[i][j] = inputBoard[i][j];
                    if (!furtherTraversalPossible && wordIndex > 0)
                        return false;
                }
            }
            if (wordIndex > 0 && !nextLetterFound)
                break;
        }
        if (wordIndex > 0 && !nextLetterFound)
            break;
    }
    return false;
}

static bool wordSearch(std::vector<std::vector<char>>& board, const std::string& word)
{
    return wordSearchHelper(board, board, 0, 0, word, 0);
}

int main()
{
    std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "CEE";

    if (wordSearch(board, word))
        std::cout<<"word present!"<<std::endl;
    else
        std::cout<<"word absent!"<<std::endl;
    
    return 0;
}