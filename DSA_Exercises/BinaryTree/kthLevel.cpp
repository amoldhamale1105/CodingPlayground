#include <iostream>
#include <vector>
#include <queue>
#include <ComplexObjectStream.hpp>
#include <CommonTypes.hpp>
#include <BuildHelpers.hpp>
#include <PrintHelpers.hpp>

std::vector<int> printKthLevel(Node<int>* root, int k)
{
    if (root == nullptr)
        return {};
    
    std::vector<int> kthLevelElements;
    std::queue<Node<int>*> treeQue;
    treeQue.push(root);
    treeQue.push(nullptr);

    while (!treeQue.empty() && k >= 0)
    {
        Node<int>* front = treeQue.front();
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

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter tree depth/level as program arg!"<<std::endl;
        return -1;
    }

    int level = std::stoi(argv[1]);
    std::vector<int> treeMap = {60, 50, 80, -1, -1, 10, -1, -1, 30, 40, -1, -1, -1};
    //std::vector<int> treeMap = {2,7,-1,9,11,-1,-1,4,-1,-1,5,-1,1,-1,-1};
    Node<int>* root = buildTree(treeMap);
    printTree(root);
    std::cout<<level<<superScript(level)+" level of tree: "<<printKthLevel(root, level)<<std::endl;
    
    return 0;
}