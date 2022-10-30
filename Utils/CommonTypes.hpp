#pragma once

template <typename T>
struct Node
{
    T key;
    Node* left, *right;

    Node() : left(nullptr), right(nullptr) {}
    Node(const T& key) : key(key), left(nullptr), right(nullptr) {}
};