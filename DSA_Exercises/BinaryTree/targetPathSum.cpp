#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>
#include <CommonTypes.hpp>
#include <BuildHelpers.hpp>

void traverseTree(Node<int>* root, std::vector<int> pathTrack, std::vector<std::vector<int>>& targetPaths, const int& targetSum)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr){
        int sum = root->key;
        for(const int& num : pathTrack)
        {
            sum += num;
        }
        if (sum == targetSum){
            pathTrack.emplace_back(root->key);
            targetPaths.emplace_back(pathTrack);
        }
        return;
    }

    pathTrack.emplace_back(root->key);
    traverseTree(root->left, pathTrack, targetPaths, targetSum);
    traverseTree(root->right, pathTrack, targetPaths, targetSum);
}

std::vector<std::vector<int>> pathSum(Node<int>* root, int targetSum)
{
    std::vector<int> pathTrack;
    std::vector<std::vector<int>> targetPaths;

    traverseTree(root, pathTrack, targetPaths, targetSum);
    return targetPaths;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter target sum as program arg"<<std::endl;
        return -1;
    }
    
    std::vector<int> treeMap = {5,4,11,7,-1,-1,2,-1,-1,-1,8,13,-1,-1,4,5,-1,-1,1,-1,-1};
    Node<int>* root = buildTree(treeMap);
    std::cout<<"Root to leaf paths for target sum: "<<pathSum(root, std::stoi(argv[1]));
    return 0;
}