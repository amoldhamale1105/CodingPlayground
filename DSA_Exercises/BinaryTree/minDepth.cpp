#include <iostream>
#include <vector>
#include <BuildHelpers.hpp>

static int subtreeDepths(Node<int> *root, std::pair<int,int>& depths)
{
    // Base case
    if (root == nullptr)
        return 0;

    // Rec case
    int leftHeight = subtreeDepths(root->left, depths);
    int rightHeight = subtreeDepths(root->right, depths);
    depths = std::make_pair(leftHeight, rightHeight);
    
    return 1 + std::max(leftHeight, rightHeight);
}

static int minDepth(Node<int> *root)
{
    std::pair<int,int> treeDepths = {0,0};
    subtreeDepths(root, treeDepths);
    
    return 1 + std::min(treeDepths.first, treeDepths.second);
}

int main()
{
    std::vector<int> treeMap = {2,7,-1,9,11,-1,-1,4,-1,-1,5,-1,1,-1,-1};
    Node<int>* root = buildTree(treeMap);
    std::cout<<"Min tree depth: "<<minDepth(root)<<std::endl;
    return 0;
}