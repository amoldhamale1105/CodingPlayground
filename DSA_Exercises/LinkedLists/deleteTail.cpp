#include <iostream>

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

node* deleteTail(node * head){
    if (head == nullptr)
        return nullptr;
    
    node* currentNode = head;
    while (currentNode->next->next != nullptr)
    {
        currentNode = currentNode->next;
    }
    delete currentNode->next;
    currentNode->next = nullptr;

    return head;
}

int main()
{
    node* element1 = new node(14); // head
    node *element2 = new node(16);
    node *element3 = new node(18);
    node *element4 = new node(20);
    node *element5 = new node(22); // tail

    element1->next = element2;
    element2->next = element3;
    element3->next = element4;
    element4->next = element5;

    node* head = deleteTail(element1);
    std::cout<<"updated head data: "<<head->data<<" New list: "<<std::endl;
    node* currentNode = head;
    
    while (currentNode != nullptr)
    {
        std::cout<<currentNode->data<<"->";
        currentNode = currentNode->next;
    }
    std::cout<<"end of list"<<std::endl;

    return 0;
}