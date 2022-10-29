#include <iostream>
#include <vector>
#include <BuildHelpers.hpp>
#include <PrintHelpers.hpp>

Node<int>* insert(Node<int>* root, const int& key)
{
    if (root == nullptr){
        Node<int>* node = new Node<int>;
        node->key = key;
        node->left = node->right = nullptr;
        return node;
    }

    if (key <= root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

bool search(Node<int>* root, const int& key)
{
    if (root == nullptr)
        return false;
    if (key == root->key)
        return true;

    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Enter element to be checked for existence in BST as program arg"<<std::endl;
        return -1;
    }
    int searchElement = std::stoi(argv[1]);
    Node<int>* root = nullptr;
    std::vector<int> arr = {8,3,10,1,6,14,4,7,13};

    for(const int& element : arr)
    {
        root = insert(root, element);
    }

    printTree(root);
    std::cout<<searchElement<<(search(root, searchElement) ? " exists" : " does not exist")<<" in the BST"<<std::endl;
    return 0;
}