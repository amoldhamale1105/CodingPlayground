#include <iostream>
#include <vector>
#include <ComplexObjectStream.hpp>

void sortBallsHelper(int s, int e, std::vector<int>& balls)
{
    if (s >= e)
        return;
    
    int pivot = e;
    int i = s, j = s;

    while (j < pivot)
    {
        if (balls[j] <= balls[pivot]){
            if (i != j)
                std::swap(balls[i], balls[j]);
            i++;
            j++;
        }
        else if (balls[j] > balls[pivot]){
            j++;
        }
    }
    // Place the pivot in the right position
    std::swap(balls[i], balls[pivot]);

    sortBallsHelper(s, i-1, balls);
    sortBallsHelper(i+1, pivot, balls);
}

// sort the balls in place in a single pass (O(N) time, O(1) space)
std::vector<int> sortBalls(std::vector<int> balls)
{
    sortBallsHelper(0, balls.size()-1, balls);
    return balls;
}

int main()
{
    std::vector<int> balls = {0, 0, 1, 2, 0, 1, 2, 0};
    std::cout<<"Sorted balls in order 0,1,2: "<<sortBalls(balls)<<std::endl;
    return 0;
}