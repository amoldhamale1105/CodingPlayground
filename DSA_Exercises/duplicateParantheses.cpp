#include <iostream>
#include <stack>

bool duplicateParentheses(const std::string& str)
{
    int openExpressionCounter{0}, position{0};
    std::stack<char> brackets;

    while (position < str.length())
    {
        char current = str.at(position);
        char prev = position == 0 ? '\0' : str.at(position-1);

        if (current == '('){
            brackets.push(current);
        }
        else if (current == ')'){
            openExpressionCounter--;
            brackets.pop();
        }
        else if ((current != '(' && (prev == ')' || prev == '('))){
            openExpressionCounter++;
        }

        position++;
    }

    return openExpressionCounter < 0;
}

int main()
{
    //std::string expression = "((a+b)+(c+d))";
    std::string expression = "(((a+(b)))+(c+d))";
    std::cout<<"duplicate parantheses? "<<(duplicateParentheses(expression) ? "Yes" : "No")<<std::endl;
    return 0;
}