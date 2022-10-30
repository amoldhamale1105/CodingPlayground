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

struct has_comparator_impl
{
    template <typename T, typename gt = decltype(std::declval<const T&>().operator>()),
                        typename lte = decltype(std::declval<const T&>().operator<=()),
                        typename lt = decltype(std::declval<const T&>().operator<()),
                        typename eq = decltype(std::declval<const T&>().operator==())>
    static std::true_type test(int);
    
    template <typename...>
    static std::false_type test(...);
};

template <typename T>
struct has_comparator : decltype(has_comparator_impl::test<T>(0)) {};

template <typename T>
static Node<T>* insert(Node<T>* root, const T& key)
{
    if (root == nullptr)
        return new Node<T>(key);

    if (key <= root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

template <typename T>
Node<T>* buildBST(const std::vector<T>& nodes)
{
    static_assert(std::is_same<T,int>::value ||
                    std::is_same<T,float>::value ||
                    std::is_same<T,double>::value ||
                    std::is_same<T,long>::value ||
                    std::is_same<T,long long>::value || 
                    has_comparator<T>::value, 
                    "type must have comparator functionality");
    Node<T>* root = nullptr;

    for(const T& element : nodes)
    {
        root = insert(root, element);
    }
    return root;
}
