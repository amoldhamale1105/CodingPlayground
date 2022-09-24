#include <iostream>
#include <Profiler.h>

struct Node
{
    int key;
    Node* left, *right;
};

Node* buildTree()
{
    PROFILE_FUNCTION();
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
    PROFILE_FUNCTION();
    if (root == nullptr)
        return 0;

    int sumLeft = sumBT(root->left);
    int sumRight = sumBT(root->right);

    return root->key + sumLeft + sumRight;
}

int main()
{
    Instrumentor::Instance().beginSession("sumbt");
    Node* root = buildTree();
    std::cout<<"Binary tree node sum: "<<sumBT(root)<<std::endl;
    Instrumentor::Instance().endSession();
    return 0;
}