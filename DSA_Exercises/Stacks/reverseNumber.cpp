#include <iostream>
#include <stack>
#include <cmath>

static void insertAtBottom(std::stack<int>& stack, const int& data)
{
    //Base case
    if (stack.empty()){
        stack.push(data);
        return;
    }

    //Rec case
    int temp = stack.top();
    stack.pop();
    insertAtBottom(stack, data);
    stack.push(temp);
}

static void recRev(std::stack<int>& stack)
{
    //Base case
    if (stack.empty())
        return;

    //Rec case
    int temp = stack.top();
    stack.pop();
    recRev(stack);
    insertAtBottom(stack, temp);
}

static int reverse(const int& n)
{   
	int number = std::abs(n);
    std::stack<int> digits;

    while (number > 0)
    {
        digits.push(number%10);
        number /= 10;
    }

    recRev(digits);
    int totalDigits = digits.size();

    while (!digits.empty())
    {
        number += digits.top() * std::pow(10, totalDigits-1);
        digits.pop();
        totalDigits--;
    }

    return n < 0 ? -number : number;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter a valid integer arg to the program!"<<std::endl;
        return -1;
    }

    std::cout<<"Reversed integer using stack: "<<reverse(std::stoi(argv[1]))<<std::endl;

    return 0;
}