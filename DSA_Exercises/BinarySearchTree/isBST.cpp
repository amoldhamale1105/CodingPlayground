#include <iostream>
#include <vector>
#include <BuildHelpers.hpp>

static void isBSTHelper(Node<int>* root, int& prev, bool& result)
{
    if (!result || root == nullptr)
        return;

    isBSTHelper(root->left, prev, result);
    if (!result)
        return;
    if (prev > root->key){
        result = false;
        return;
    }
    prev = root->key;
    isBSTHelper(root->right, prev, result);
}

bool isBST(Node<int>* root)
{
    int prev{-1};
    bool result{true};
    isBSTHelper(root, prev, result);

    return result;
}

int main()
{
    std::vector<int> treeMap = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    //std::vector<int> treeMap = {4,2,1,-1,-1,3,-1,-1,5,-1,6,-1,-1};
    Node<int>* root = buildTree(treeMap);
    std::cout<<"is BST? "<<(isBST(root) ? "yes" : "no")<<std::endl;
    return 0;
}