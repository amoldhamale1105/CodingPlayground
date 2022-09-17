#include <iostream>
#include <vector>
#include <queue>
#include <ComplexObjectStream.hpp>

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

void printTree(Node* root)
{
    if (root == nullptr)
        return;

    std::queue<Node*> treeQue;
    treeQue.push(root);
    treeQue.push(nullptr);

    while (!treeQue.empty())
    {
        Node* front = treeQue.front();
        treeQue.pop();

        if (front != nullptr){
            if (front->left != nullptr)
                treeQue.push(front->left);
            if (front->right != nullptr)
                treeQue.push(front->right);
            std::cout<<front->key<<" ";
        }
        else{
            std::cout<<std::endl;
            if (!treeQue.empty())
                treeQue.push(nullptr);
            else
                return;
        }
    }
}

std::vector<int> printKthLevel(Node* root, int k)
{
    if (root == nullptr)
        return {};
    
    std::vector<int> kthLevelElements;
    std::queue<Node*> treeQue;
    treeQue.push(root);
    treeQue.push(nullptr);

    while (!treeQue.empty() && k >= 0)
    {
        Node* front = treeQue.front();
        treeQue.pop();

        if (front != nullptr){
            if (front->left != nullptr)
                treeQue.push(front->left);
            if (front->right != nullptr)
                treeQue.push(front->right);
            if (k == 0)
                kthLevelElements.emplace_back(front->key);
        }
        else{
            k--;
            if (!treeQue.empty())
                treeQue.push(nullptr);
            else
                break;
        }
    }

    return kthLevelElements;
}

static std::string superScript(const int& number)
{
    std::string ret;
    
    switch (number%10)
    {
    case 1:
        ret = "st";
        break;
    case 2:
        ret = "nd";
        break;
    case 3:
        ret = "rd";
        break;
    default:
        ret = "th";
        break;
    }

    if (number == 11 || number == 12 || number == 13)
        ret = "th";

    return ret;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter tree depth/level as program arg!"<<std::endl;
        return -1;
    }

    int level = std::stoi(argv[1]);
    Node* root = buildTree();
    //printTree(root);
    std::cout<<level<<superScript(level)+" level of tree: "<<printKthLevel(root, level)<<std::endl;
    
    return 0;
}