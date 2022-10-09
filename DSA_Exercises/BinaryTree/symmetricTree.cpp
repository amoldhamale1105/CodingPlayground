#include <iostream>
#include <vector>
#include <queue>
#include <BuildHelpers.hpp>

enum BranchSide
{
    LEFT,
    RIGHT
};

bool isSymmetric(Node<int>* root)
{
    if (root == nullptr)
        return false;
    
    std::queue<Node<int>*> levelQueue;
    std::vector<std::pair<int,BranchSide>> levelContents;
    levelQueue.push(root);
    levelQueue.push(nullptr);

    while (!levelQueue.empty())
    {
        Node<int>* currNode = levelQueue.front();
        levelQueue.pop();
        
        if (currNode != nullptr){
            if (currNode->left != nullptr){
                levelQueue.push(currNode->left);
                levelContents.push_back(std::make_pair(currNode->left->key, BranchSide::LEFT));
            }
            if (currNode->right != nullptr){
                levelQueue.push(currNode->right);
                levelContents.push_back(std::make_pair(currNode->right->key, BranchSide::RIGHT));
            }
        }
        else{
            size_t n = levelContents.size();
            if (n%2 != 0)
                return false;
            
            for(auto i = 0; i < n/2; ++i)
            {
                if ((levelContents[i].first != levelContents[n-1-i].first) || (levelContents[i].second == levelContents[n-1-i].second))
                    return false;
            }
            if (!levelQueue.empty()){
                levelQueue.push(nullptr);
                levelContents.clear();
            }
        }
    }

    return true;
}

int main()
{
    std::vector<int> treeMap = {1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1};
    //std::vector<int> treeMap = {2,7,-1,9,11,-1,-1,4,-1,-1,5,-1,1,-1,-1};
    Node<int>* root = buildTree(treeMap);
    std::cout<<"Is tree symmetric? "<<(isSymmetric(root) ? "yes" : "no")<<std::endl;
    return 0;
}