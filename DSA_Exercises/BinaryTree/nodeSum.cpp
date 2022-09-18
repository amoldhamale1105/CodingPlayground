#include <iostream>
#include <vector>
#include <CommonTypes.hpp>
#include <BuildHelpers.hpp>
#include <PrintHelpers.hpp>

int sumBT(Node<int>* root)
{
    if (root == nullptr)
        return 0;

    int sumLeft = sumBT(root->left);
    int sumRight = sumBT(root->right);

    return root->key + sumLeft + sumRight;
}

int main()
{
    std::vector<int> treeMap = {2,7,-1,9,11,-1,-1,4,-1,-1,5,-1,1,-1,-1};
    Node<int>* root = buildTree(treeMap);
    std::cout<<"Binary tree node sum: "<<sumBT(root)<<std::endl;
    return 0;
}