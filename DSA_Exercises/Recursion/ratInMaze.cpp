#include <iostream>
#include <vector>
#include <algorithm>
#include <ComplexObjectStream.hpp>

bool findHelper(const std::vector<std::vector<char>>& maze, int n, std::pair<int,int> pos, std::vector<int>& soln)
{
    if (pos.first == n-1 && pos.second == n-1){
        soln.emplace_back((n*pos.first) + pos.second+1);
        return true;
    }
    if (pos.first > n-1 || pos.second > n-1)
        return false;
    
    if (pos.first < n-1 && maze[pos.first+1][pos.second] == 'O'){
        if (findHelper(maze, n, {pos.first+1, pos.second}, soln)){
            soln.emplace_back((n*pos.first) + pos.second+1);
            return true;
        }
    }
    if (pos.second < n-1 && maze[pos.first][pos.second+1] == 'O'){
        if (findHelper(maze, n, {pos.first, pos.second+1}, soln)){
            soln.emplace_back((n*pos.first) + pos.second+1);
            return true;
        }
    }
    return false;
}

std::vector<int> findPath(int n, std::vector<std::vector<char>> c)
{
    std::vector<int> soln{};
    findHelper(c, n, {0,0}, soln);
    std::reverse(soln.begin(), soln.end());
    return soln;
}

int main()
{
    std::vector<std::vector<char>> maze = {
        {'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O'},
    };
    std::cout<<"Maze solution: "<<findPath(4, maze)<<std::endl;
    return 0;
}