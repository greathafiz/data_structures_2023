#include <iostream>
using namespace std;

// Component class to represent
// a node of the linked list.
class Component {
public:
	char Item;// This can be changed to another datatype
	Component* next;

	// Default constructor
	Component()
	{
		Item = 0;
		next = NULL;
	}

	// Parameterised Constructor
Component(char data)
	{
		this->Item = data;
		this->next = NULL;
	}
};

// Linked list class to
// implement a linked list.
class Linkedlist {
	Component* head;

public:
	// Default constructor
	Linkedlist() { head = NULL; }

	// Function to insert a
	// node at the end of the
	// linked list.
	void insertNode(char);

	// Function to print the
	// linked list.
	void printList();

	// Function to delete the
	// node at given position
	void deleteNode(int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
	Component *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}

	// Check if the position to be
	// deleted is greater than the length
	// of the linked list.
	if (ListLen < nodeOffset) {
		cout << "Index out of range"
			<< endl;
		return;
	}

	// Declare temp1
	temp1 = head;

	// Deleting the head.
	if (nodeOffset == 1) {

		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to
	// find the node to be deleted.
	while (nodeOffset-- > 1) {

		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

// Function to insert a new node.
void Linkedlist::insertNode(char data)
{
	// Create the new Node.
	Component* newComponent = new Component(data);

	// Assign to head
	if (head == NULL) {
		head = newComponent;
		return;
	}

	// Traverse till end of list
	Component* temp = head;
	while (temp->next != NULL) {

		// Update temp
		temp = temp->next;
	}

	// Insert at the last.
	temp->next = newComponent;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
	Component* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->Item << " ";
		temp = temp->next;
	}
}

// Driver Code
int main()
{
	Linkedlist list;

	// Inserting nodes
	list.insertNode('A');
	list.insertNode('B');
	list.insertNode('C');
	list.insertNode('D');

	cout << "Elements of the list are: ";

	// Print the list
	list.printList();
	cout << endl;

	// Delete node at position 2.
	list.deleteNode(2);
	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;

	// Delete node at position 1.
	list.deleteNode(1);
	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;

	return 0;
}
