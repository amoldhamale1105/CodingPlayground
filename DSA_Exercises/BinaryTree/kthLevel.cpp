#include <iostream>
#include <vector>
#include <queue>
#include <ComplexObjectStream.hpp>

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
    std::vector<int> treeMap = {60, 50, 80, -1, -1, 10, -1, -1, 30, 40, -1, -1, -1};
    //std::vector<int> treeMap = {2,7,-1,9,11,-1,-1,4,-1,-1,5,-1,1,-1,-1};
    Node* root = buildTree(treeMap);
    printTree(root);
    std::cout<<level<<superScript(level)+" level of tree: "<<printKthLevel(root, level)<<std::endl;
    
    return 0;
}