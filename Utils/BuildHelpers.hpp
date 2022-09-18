#pragma once

#include <iostream>
#include <vector>
#include <type_traits>
#include <CommonTypes.hpp>

template <typename T>
static Node<T>* buildTreePreorder(typename std::vector<T>::const_iterator& itr, const typename std::vector<T>::const_iterator& endItr)
{
    if (*itr == -1)
        return nullptr;
    
    Node<T>* node = new Node<T>;
    node->key = *itr;
    node->left = node->right = nullptr;

    if (itr != endItr)
        itr++;
    node->left = buildTreePreorder<T>(itr, endItr);
    
    if (itr != endItr)
        itr++;
    node->right = buildTreePreorder<T>(itr, endItr);

    return node;
}

template <typename T>
static Node<T>* buildTreePreorder(typename std::vector<T*>::const_iterator& itr, const typename std::vector<T*>::const_iterator& endItr)
{
    if (*itr == nullptr)
        return nullptr;
    
    Node<T>* node = new Node<T>;
    node->key = *itr;
    node->left = node->right = nullptr;

    if (itr != endItr)
        itr++;
    node->left = buildTreePreorder<T>(itr, endItr);
    
    if (itr != endItr)
        itr++;
    node->right = buildTreePreorder<T>(itr, endItr);

    return node;
}

template <typename T>
Node<T>* buildTree(const std::vector<T>& treeMap)
{
    typename std::vector<T>::const_iterator start = treeMap.begin();
    typename std::vector<T>::const_iterator end = treeMap.end();

    return buildTreePreorder<T>(start, end);
}