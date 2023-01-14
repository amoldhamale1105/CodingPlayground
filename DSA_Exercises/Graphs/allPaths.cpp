#include <vector>
#include <list>
#include <ComplexObjectStream.hpp>

class Graph
{
    std::vector<std::list<int>> nodes;
    void allPathsHelper(const int& node, std::vector<int>& path, std::vector<std::vector<int>>& paths, std::vector<bool>& visited)
    {
        visited[node] = true;
        path.emplace_back(node);

        for(const int& neighbor : nodes.at(node))
        {
            if (neighbor == nodes.size()-1){
                paths.emplace_back(path);
                paths.back().emplace_back(neighbor);
                continue;
            }
            if (!visited[neighbor]){
                allPathsHelper(neighbor, path, paths, visited);
                visited[neighbor] = false;
                path.pop_back();
            }
        }
    }
public:
    Graph(const int& total) { nodes.resize(total); }
    void addEdge(const int& fn, const int& sn)
    {
        nodes[fn].emplace_back(sn);
    }
    std::vector<std::vector<int>> allPaths()
    {
        std::vector<int> path;
        std::vector<std::vector<int>> paths;
        std::vector<bool> visited(nodes.size(), false);
        allPathsHelper(0, path, paths, visited);
        return paths;
    }
};

std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>>& graph)
{
    int totalNodes = graph.size();
    Graph pathGraph(totalNodes);
    for(auto i = 0; i < totalNodes; i++)
    {
        for(const int& neighbor : graph[i])
        {
            pathGraph.addEdge(i, neighbor);
        }
    }
    return pathGraph.allPaths();
}

int main()
{
    //std::vector<std::vector<int>> graph = {{1,2},{3},{3},{}};
    std::vector<std::vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    std::cout<<"All paths from 0 to "<<graph.size()-1<<std::endl<<allPathsSourceTarget(graph);
    return 0;
}