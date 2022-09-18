#pragma once
#include <iostream>
#include <queue>
#include <CommonTypes.hpp>

template <typename T>
void printTree(Node<T>* root)
{
    if (root == nullptr)
        return;

    std::queue<Node<T>*> treeQue;
    treeQue.push(root);
    treeQue.push(nullptr);

    while (!treeQue.empty())
    {
        Node<T>* front = treeQue.front();
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

std::string superScript(const int& number)
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