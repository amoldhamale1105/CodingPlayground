#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node* left, *right;
};

Node* buildTreePreorder(std::vector<int>::const_iterator& itr, const std::vector<int>::const_iterator& endItr)
{
    if (*itr == -1)
        return nullptr;
    
    Node* node = new Node;
    node->key = *itr;
    node->left = node->right = nullptr;

    if (itr != endItr)
        itr++;
    node->left = buildTreePreorder(itr, endItr);
    
    if (itr != endItr)
        itr++;
    node->right = buildTreePreorder(itr, endItr);

    return node;
}

Node* buildTree(const std::vector<int>& treeMap)
{
    std::vector<int>::const_iterator start = treeMap.begin();
    std::vector<int>::const_iterator end = treeMap.end();

    return buildTreePreorder(start, end);
}

int sumBT(Node* root)
{
    if (root == nullptr)
        return 0;

    int sumLeft = sumBT(root->left);
    int sumRight = sumBT(root->right);

    return root->key + sumLeft + sumRight;
}

int main()
{
    std::vector<int> treeMap = {2,7,-1,9,11,-1,-1,4,-1,-1,5,-1,1,-1,-1};
    Node* root = buildTree(treeMap);
    std::cout<<"Binary tree node sum: "<<sumBT(root)<<std::endl;
    return 0;
}