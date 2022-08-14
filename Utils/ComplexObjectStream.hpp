/**
 * @file ComplexObjectStream.hpp
 * @author Amol Dhamale
 * @brief Display contents of complex objects and structures like vectors and stacks to stdout using the ostream cout object
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022 Amol Dhamale
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <stack>

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::pair<T1, T2>& pair)
{
    stream << "{";
    stream << pair.first << "," << pair.second;
    stream << "}";

    return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<T>>& mat)
{
    for(const std::vector<T>& vec : mat)
    {
        for(const T& val : vec)
        {
            stream << val << " ";
        }
        stream << "\n";
    }

    return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec)
{
    stream << "{";
    for(const T& val : vec)
    {
        stream << val << ",";
    }

    stream << '\b' << "}";
    return stream;
}

template <typename T>
static void recursiveStackHelper(std::ostream& stream, std::stack<T>& stack)
{
    //Base case
    if (stack.empty())
        return;

    //Rec case
    T temp = stack.top();
    stream << temp << " ";
    stack.pop();
    recursiveStackHelper(stream, stack);
    stack.push(temp);
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, std::stack<T>& stack)
{
    stream << "[";
    recursiveStackHelper(stream, stack);
    stream << '\b' << "]";
    
    return stream;
}


