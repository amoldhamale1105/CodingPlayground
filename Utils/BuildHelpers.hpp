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
static Node<T>* buildTreePreorderStr(typename std::vector<T>::const_iterator& itr, const typename std::vector<T>::const_iterator& endItr)
{
    if ((*itr).empty())
        return nullptr;
    
    Node<T>* node = new Node<T>;
    node->key = *itr;
    node->left = node->right = nullptr;

    if (itr != endItr)
        itr++;
    node->left = buildTreePreorderStr<T>(itr, endItr);
    
    if (itr != endItr)
        itr++;
    node->right = buildTreePreorderStr<T>(itr, endItr);

    return node;
}

template <typename T>
static Node<T>* buildTreePreorderPtr(typename std::vector<T>::const_iterator& itr, const typename std::vector<T>::const_iterator& endItr)
{
    if (*itr == nullptr)
        return nullptr;
    
    Node<T>* node = new Node<T>;
    node->key = *itr;
    node->left = node->right = nullptr;

    if (itr != endItr)
        itr++;
    node->left = buildTreePreorderPtr<T>(itr, endItr);
    
    if (itr != endItr)
        itr++;
    node->right = buildTreePreorderPtr<T>(itr, endItr);

    return node;
}

template <typename T>
Node<T>* buildTree(const std::vector<T>& treeMap)
{
    typename std::vector<T>::const_iterator start = treeMap.begin();
    typename std::vector<T>::const_iterator end = treeMap.end();

    return buildTreePreorder<T>(start, end);
}

template <typename T>
Node<T>* buildTreeStr(const std::vector<T>& treeMap)
{
    static_assert(std::is_base_of<std::string, T>::value, "buildTreeStr must inherit from std::string");
    typename std::vector<T>::const_iterator start = treeMap.begin();
    typename std::vector<T>::const_iterator end = treeMap.end();

    return buildTreePreorderStr<T>(start, end);
}

template <typename T>
Node<T>* buildTreePtr(const std::vector<T>& treeMap)
{
    static_assert(std::is_pointer<T>::value, "buildTreePtr must accept pointers");
    typename std::vector<T>::const_iterator start = treeMap.begin();
    typename std::vector<T>::const_iterator end = treeMap.end();

    return buildTreePreorderPtr<T>(start, end);
}