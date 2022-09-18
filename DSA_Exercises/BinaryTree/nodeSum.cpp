#include <iostream>

struct Node
{
    int key;
    Node* left, *right;
};

Node* buildTree()
{
    int data;
    std::cin >> data;

    if (data == -1)
        return nullptr;
    
    Node* node = new Node;
    node->key = data;
    node->left = node->right = nullptr;

    node->left = buildTree();
    node->right = buildTree();

    return node;
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
    Node* root = buildTree();
    std::cout<<"Binary tree node sum: "<<sumBT(root)<<std::endl;
    return 0;
}