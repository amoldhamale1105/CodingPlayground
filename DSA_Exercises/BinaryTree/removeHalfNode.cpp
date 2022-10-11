#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>
#include <CommonTypes.hpp>
#include <BuildHelpers.hpp>

static void reconstructTree(Node<int>*& root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right != nullptr){
        Node<int>* halfNode = root;
        root = root->right;
        delete halfNode;
        reconstructTree(root);
    }
    else if (root->right == nullptr && root->left != nullptr){
        Node<int>* halfNode = root;
        root = root->left;
        delete halfNode;
        reconstructTree(root);
    }
    else{
        reconstructTree(root->left);
        reconstructTree(root->right);
    }
}

static void storeInorder(Node<int>* root, std::vector<int>& updatedTree)
{
    if (root == nullptr)
        return;

    storeInorder(root->left, updatedTree);
    updatedTree.emplace_back(root->key);
    storeInorder(root->right, updatedTree);
}

std::vector<int> removeHalfNodes(Node<int> *root)
{
    std::vector<int> updatedTree;
    reconstructTree(root);
    storeInorder(root, updatedTree);

    return updatedTree;
}

int main()
{
    std::vector<int> treeMap = {2,7,-1,6,1,-1,-1,11,-1,-1,5,-1,9,4,-1,-1,-1};
    Node<int>* root = buildTree(treeMap);
    std::cout<<"Inorder traversal of updated tree: "<<removeHalfNodes(root)<<std::endl;
    return 0;
}