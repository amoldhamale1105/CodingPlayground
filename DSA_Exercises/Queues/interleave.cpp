#include <iostream>
#include <queue>
#include <list>
#include <ComplexObjectStream.hpp>

std::queue<int> interLeave(std::queue<int> q)
{
    std::queue<int> interleavedQ;
    int len = q.size();

    for(int i = 0; i < len/2; i++)
    {
        interleavedQ.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        interleavedQ.push(interleavedQ.front());
        interleavedQ.push(q.front());
        q.pop();
        interleavedQ.pop();
    }

    return interleavedQ;
}

int main()
{
    std::list<int> queueList = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::queue<int> q;

    for(const int& num : queueList)
    {
        q.push(num);
    }
    
    std::queue<int> iq = interLeave(q);
    std::cout<<iq<<std::endl;
    return 0;
}