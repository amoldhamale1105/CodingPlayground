#pragma once

template <typename T>
struct Node
{
    T key;
    Node* left, *right;
};