#include <iostream>
#include <vector>
#include <BuildHelpers.hpp>
#include <PrintHelpers.hpp>

static Node<int>* findMin(Node<int>* root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node<int>* deleteNode(Node<int>* root, const int& k)
{
    if (root == nullptr)
        return nullptr;

    if (k == root->key){
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr){
            Node<int>* delNode = root;
            root = root->right;
            delete delNode;
        }
        else if (root->right == nullptr){
            Node<int>* delNode = root;
            root = root->left;
            delete delNode;
        }
        else{
            Node<int>* nextMin = findMin(root->right);
            root->key = nextMin->key;
            root->right = deleteNode(root->right, nextMin->key);
        }
    }
    else if (k < root->key){
        root->left = deleteNode(root->left, k);
    }
    else{
        root->right = deleteNode(root->right, k);
    }

    return root;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter node to be deleted as program arg."<<std::endl;
        return -1;
    }

    std::vector<int> treeMap = {7,5,3,-1,-1,6,-1,-1,9,8,-1,-1,10,-1,-1};
    Node<int>* root = buildTree(treeMap);
    
    std::cout<<"original tree:"<<std::endl;
    printTree(root);
    std::cout<<"updated tree:"<<std::endl;
    printTree(deleteNode(root, std::stoi(argv[1])));
    
    return 0;
}