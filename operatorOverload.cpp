// C++ program to demonstrate the
// overloading of '<<' and '>>'
// operators
#include <iostream>
using namespace std;

// Class for each node object
// of the linked list
class node {
public:
	// Node of the linked list
	int data;
	node* next;

	// Constructor of node class
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

// Insert a node at head of linked
// list
void insertAtHead(node*& head, int d)
{
	node* n = new node(d);
	n->next = head;
	head = n;
}

// Insert a node at tail of linked
// list
void insertAtTail(node* head, int data)
{
	// Make new node using
	// constructor
	node* n = new node(data);
	node* temp = head;

	// Traverse till we get to end of
	// the linked list
	while (temp->next != NULL)
		temp = temp->next;

	// Append the new node n at the end
	// of the linked list
	temp->next = n;
}

// Print the node at the linked list
void print(node* head)
{
	// Print the first Node
	if (head != NULL) {
		cout << head->data;
		head = head->next;
	}

	// Traverse till head traverse
	// till end
	while (head != NULL) {
		cout << "->" << head->data;
		head = head->next;
	}
}

// Function that takes continuous input
// until user enter -1 while initializing
// the linked list.
void takeInput(node*& head)
{
	int n;
	cin >> n;

	// If n is not equals to -1 insert
	// the node in the linked list
	while (n != -1) {

		// If head is NULL, insert at
		// the beginning of list
		if (head == NULL)
			insertAtHead(head, n);
		else
			insertAtTail(head, n);
		cin >> n;
	}
}

// Overloading the ostream operator '<<'
// to print the complete linked list from
// beginning
ostream& operator<<(ostream& os, node* head)
{
	print(head);
	return os;
}

// Overloading the istream operator '>>'
// to take continuous input into the linked
// list until user inputs -1
istream& operator>>(istream& is, node*& head)
{
	takeInput(head);
	return is;
}

// Driver Code
int main()
{
	// initialise head to NULL
	node* head = NULL;

	// Overloading of '>>' for inserting
	// element in the linked list
	cin >> head;

	// Overloading of '<<' for printing
	// element in the linked list
	cout << head;
	return 0;
}

