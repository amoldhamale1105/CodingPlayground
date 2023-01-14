#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

class Graph
{
    std::vector<std::list<int>> nodes;
    void dfsHelper(const int& room, std::vector<bool>& visited)
    {
        visited[room] = true;
        for(const int& key : nodes.at(room))
        {
            if (!visited.at(key))
                dfsHelper(key, visited);
        }
    }
public:
    Graph(const int& total) { nodes.resize(total); }
    void addEdge(const int& r, const int& tr)
    {
        nodes[r].emplace_back(tr);
    }
    bool dfs(const int& start)
    {
        std::vector<bool> visited(nodes.size(), false);
        dfsHelper(start, visited);
        return std::all_of(visited.begin(), visited.end(), [](bool isOpen){ return isOpen; });
    }
};

bool canVisitAllRooms(const std::vector<std::vector<int>>& rooms)
{
    int totalRooms = rooms.size();
    Graph roomGraph(totalRooms);
    
    for(auto i = 0; i < totalRooms; i++)
    {
        for(const int& key : rooms[i])
        {
            roomGraph.addEdge(i, key);
        }
    }

    return roomGraph.dfs(0);
}

int main()
{
    std::vector<std::vector<int>> rooms = {{1},{2},{3},{}};
    std::cout<<"Can all "<<rooms.size()<<" rooms be visited? "<<(canVisitAllRooms(rooms) ? "yes" : "no")<<std::endl;
    return 0;
}