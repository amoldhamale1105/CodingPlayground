#include <iostream>
#include <vector>
#include <BuildHelpers.hpp>

static bool isOperator(const std::string& key)
{
    return key == "+" || key == "-" || key == "/" || key == "*";
}

static int calculate(const int& leftOperand, const int& rightOperand, const std::string& expOperator)
{
    int calculation{0};

    if (expOperator == "+")
        calculation = leftOperand + rightOperand;
    else if (expOperator == "-")
        calculation = leftOperand - rightOperand;
    else if (expOperator == "*")
        calculation = leftOperand * rightOperand;
    else if (expOperator == "/")
        calculation = leftOperand / rightOperand;
    else
        calculation = -1;

    return calculation;
}

int evalTree(Node<std::string>* root)
{
    if (root == nullptr)
        return 0;

    if (isOperator(root->key)){
        int leftVal = evalTree(root->left);
        int rightVal = evalTree(root->right);

        return calculate(leftVal, rightVal, root->key);
    }

    return std::stoi(root->key);
}

int main()
{
    std::vector<std::string> treeMap = {"+","3","","","*","+","5","","","9","","","2","",""};
    Node<std::string>* root = buildTreeStr(treeMap);
    std::cout<<"Tree expression value: "<<evalTree(root)<<std::endl;
    return 0;
}