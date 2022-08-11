#include <iostream>

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

static int size(node* head)
{
    node* currentNode = head;
    int count{0};

    while (currentNode != nullptr)
    {
        count++;
        currentNode = currentNode->next;
    }
    
    return count;
}

static node* at(node* head, int index)
{
    node* currentNode = head;

    while (index > 0)
    {
        if (currentNode->next == nullptr)
            break;
        index--;
        currentNode = currentNode->next;
    }

    return currentNode;
}

static void swap(node* head, node* first, node* second)
{
    node* currentNode = head;
    node* firstPrev = nullptr;
    node* secondPrev = nullptr;
    node* secondNodeNext = nullptr;

    if (first != head){
        while (currentNode->next != first)
        {
            currentNode = currentNode->next;
        }
        firstPrev = currentNode;
        currentNode = head;
    }

    while (currentNode->next != second)
    {
        currentNode = currentNode->next;
    }
    secondPrev = currentNode;

    if (first != head)
        firstPrev->next = second;
    secondPrev->next = first;

    secondNodeNext = second->next;
    second->next = first->next;
    first->next = secondNodeNext;
}

node* bubble_sort_LinkedList_itr(node* head)
{
    int n = size(head);
    
    for(auto i = 0; i < n; ++i)
    {
        for(auto j = i+1; j < n; ++j)
        {
            node* atIndexI = at(head, i);
            node* atIndexJ = at(head, j);
            if (atIndexI->data > atIndexJ->data){
                swap(head, atIndexI, atIndexJ);
                if (i == 0){
                    head = atIndexJ;
                }
            }
        }
    }

    return head;
}

int main()
{
    node* element1 = new node(10); // head
    node *element2 = new node(30);
    node *element3 = new node(20);
    node *element4 = new node(5); // tail

    element1->next = element2;
    element2->next = element3;
    element3->next = element4;

    std::cout<<"sorted list: ";
    node* currentNode = bubble_sort_LinkedList_itr(element1);
    while (currentNode != nullptr)
    {
        std::cout<<currentNode->data<<"->";
        currentNode = currentNode->next;
    }
    std::cout<<"end of list"<<std::endl;

    return 0;
}