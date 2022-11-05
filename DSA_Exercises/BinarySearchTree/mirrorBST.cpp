#include <iostream>
#include <vector>
#include <BuildHelpers.hpp>
#include <PrintHelpers.hpp>

Node<int>* mirrorBST(Node<int>* root)
{
    if (root == nullptr)
        return nullptr;
    
    root->left = mirrorBST(root->left);
    root->right = mirrorBST(root->right);
    if (root->left == nullptr && root->right != nullptr){
        root->left = root->right;
        root->right = nullptr;
    }
    else if (root->right == nullptr && root->left != nullptr){
        root->right = root->left;
        root->left = nullptr;
    }
    else if (root->left && root->right)
        std::swap(root->left->key, root->right->key);
    
    return root;
}

int main()
{
    std::vector<int> treeMap = {1,3,-1,-1,2,5,-1,-1,4,-1,-1};
    Node<int>* root = buildTree(treeMap);
    printTree(root);
    std::cout<<"Mirrored tree:"<<std::endl;
    printTree(mirrorBST(root));
    return 0;
}