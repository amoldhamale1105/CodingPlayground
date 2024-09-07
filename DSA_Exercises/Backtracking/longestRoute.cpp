#include <iostream>
#include <vector>

void findHelper(const std::vector<std::vector<int>>& v, std::vector<std::vector<bool>>& visited, int m, int n, std::pair<int,int> pos, int pathLen, int& maxLen)
{
    if (pos.first == m-1 && pos.second == n-1){
        maxLen = std::max(maxLen, pathLen);
        return;
    }
    if (pos.first > m-1 || pos.second > n-1 || pos.first < 0 || pos.second < 0)
        return;

    if (pos.first < m-1 && v[pos.first+1][pos.second] == 1 && !visited[pos.first+1][pos.second]){
        visited[pos.first+1][pos.second] = true;
        findHelper(v, visited, m, n, {pos.first+1, pos.second}, pathLen+1, maxLen);
        visited[pos.first+1][pos.second] = false;
    }
    if (pos.second < n-1 && v[pos.first][pos.second+1] == 1 && !visited[pos.first][pos.second+1]){
        visited[pos.first][pos.second+1] = true;
        findHelper(v, visited, m, n, {pos.first, pos.second+1}, pathLen+1, maxLen);
        visited[pos.first][pos.second+1] = false;
    }
    if (pos.first > 0 && v[pos.first-1][pos.second] == 1 && !visited[pos.first-1][pos.second]){
        visited[pos.first-1][pos.second] = true;
        findHelper(v, visited, m, n, {pos.first-1, pos.second}, pathLen+1, maxLen);
        visited[pos.first-1][pos.second] = false;
    }
    if (pos.second > 0 && v[pos.first][pos.second-1] == 1 && !visited[pos.first][pos.second-1]){
        visited[pos.first][pos.second-1] = true;
        findHelper(v, visited, m, n, {pos.first, pos.second+1}, pathLen+1, maxLen);
        visited[pos.first][pos.second-1] = false;
    }
}

int findLongestPath(int m, int n, std::vector<std::vector<int>> v)
{
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    int maxLen = 0;
    findHelper(v, visited, m, n, {0,0}, 0, maxLen);
    return maxLen;
}

int main()
{
    std::vector<std::vector<int>> map = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 1},
    };
    std::cout<<"Length of longest route: "<<findLongestPath(3, 3, map)<<std::endl;
    return 0;
}