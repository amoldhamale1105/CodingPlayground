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

int kthLastElement(node * head,int k){
    int targetIndex = size(head) - k;
    node* currentNode = head;
    if (head == nullptr)
        return -1;

    while (targetIndex > 0)
    {
        if (currentNode == nullptr)
            break;
        targetIndex--;
        currentNode = currentNode->next;
    }

    return currentNode->data;
}

static std::string superScript(const int& number)
{
    std::string ret;
    
    switch (number%10)
    {
    case 1:
        ret = "st";
        break;
    case 2:
        ret = "nd";
        break;
    case 3:
        ret = "rd";
        break;
    default:
        ret = "th";
        break;
    }

    if (number == 11 || number == 12 || number == 13)
        ret = "th";

    return ret;
}

int main(int argc, char** argv)
{
    if (argc < 2){
        std::cerr<<"Please enter the kth last element to be searched as program arg!"<<std::endl;
        return -1;
    }

    node* element1 = new node(1); // head
    node *element2 = new node(2);
    node *element3 = new node(3);
    node *element4 = new node(4);
    node *element5 = new node(5);
    node *element6 = new node(6);
    node *element7 = new node(7); // tail

    element1->next = element2;
    element2->next = element3;
    element3->next = element4;
    element4->next = element5;
    element5->next = element6;
    element6->next = element7;

    int k = std::stoi(argv[1]);
    std::string printOutput = k == 1 ? "" : std::to_string(k) + superScript(k) + " ";

    std::cout<<printOutput<<"last element in list is: "<<kthLastElement(element1, k)<<std::endl;
    return 0;
}