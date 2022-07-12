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

node* alternateMerge(node * root1, node* root2){
    node* currentNode = root1;
    node* list2Node = root2;
    node* list1Tail = nullptr;

    while (currentNode != nullptr)
    {
        node* nextLink = currentNode->next;
        node* origList2Next = list2Node->next;
        
        if (currentNode->next == nullptr)
            list1Tail = currentNode->next;
        currentNode->next = list2Node;
        list2Node->next = nextLink;
        list2Node = origList2Next;
        currentNode = nextLink;
    }

    if (list2Node != nullptr){
        list1Tail->next = list2Node;
    }

    return root1;  
}

int main()
{
    node* root1Node1 = new node(5); // head
    node *root1Node2 = new node(7);
    node *root1Node3 = new node(17);
    node *root1Node4 = new node(13);
    node *root1Node5 = new node(11);

    root1Node1->next = root1Node2;
    root1Node2->next = root1Node3;
    root1Node3->next = root1Node4;
    root1Node4->next = root1Node5;

    node* root2Node1 = new node(12); // head
    node *root2Node2 = new node(10);
    node *root2Node3 = new node(2);
    node *root2Node4 = new node(4);
    node *root2Node5 = new node(6);

    root2Node1->next = root2Node2;
    root2Node2->next = root2Node3;
    root2Node3->next = root2Node4;
    root2Node4->next = root2Node5;

    std::cout<<"Merged list: ";
    node* currentNode = alternateMerge(root1Node1, root2Node1);
    while (currentNode != nullptr)
    {
        std::cout<<currentNode->data<<"->";
        currentNode = currentNode->next;
    }
    std::cout<<"end of list"<<std::endl;

    return 0;
}