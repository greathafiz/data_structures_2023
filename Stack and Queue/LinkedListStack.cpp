#include <iostream>
using namespace std;

class Component {
public:
	char item;
	Component* ptr;

	// Constructor
	Component (char ITEM)
	{
		this->item = ITEM;
		this->ptr = NULL;
	}
};

class Stack {
	Component* top;

public:
	Stack() { top = NULL; }

	void push(char Item)
	{

		// Create new node temp and allocate memory in heap
		Component* temp = new Component(Item);

		// Check if stack (heap) is full.
		// Then inserting an element would
		// lead to stack overflow
		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}

		// Initialize data into temp data field
		temp->item = Item;

		// Put top pointer reference into temp link
		temp->ptr = top;

		// Make temp as top of Stack
		top = temp;
	}

	// Utility function to check if
	// the stack is empty or not
	bool isEmpty()
	{
		// If top is NULL it means that
		// there are no elements are in stack
		return top == NULL;
	}

	// Utility function to return top element in a stack
	char peek()
	{
		// If stack is not empty , return the top element
		if (!isEmpty())
			return top->item;
		else
			exit(1);
	}

	// Function to remove
	// a key from given queue q
	void pop()
	{
		Component* temp;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {

			// Assign top to temp
			temp = top;

			// Assign second node to top
			top = top->ptr;

			// This will automatically destroy
			// the link between first node and second node

			// Release memory of top node
			// i.e delete the node
			free(temp);
		}
	}

	// Function to print all the
	// elements of the stack
	void display()
	{
		Component* temp;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {

				// Print node data
				cout <<(temp-> item);

				// Assign temp link to temp
				temp = temp->ptr;
				if (temp != NULL)
					cout << " -> ";
			}
		}
	}
};

// Driven Program
int main()
{
	// Creating a stack
	Stack Stack2;

	// Push the elements of stack
	Stack2.push('A');
	Stack2.push('B');
	Stack2.push('C');
	Stack2.push('D');

	// Display stack elements
	Stack2.display();

	// Print top element of stack
	cout << "\nTop element is " << Stack2.peek() << endl;

	// Delete top elements of stack
	Stack2.pop();
	Stack2.pop();

	// Display stack elements
	Stack2.display();

	// Print top element of stack
	cout << "\nTop element is " << Stack2.peek() << endl;

	return 0;
}

