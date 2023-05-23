#include <iostream>
using namespace std;
class Node
{ // A struct can also be used instead of a class
public:
	char data;	 // the type of the data can be changed
	Node *left;	 // points to left child
	Node *right; // points to right child

	Node(char data)
	{
		this->data = data;	   // The actual item/value to be stored on the tree
		this->left = nullptr;  // left child of the node points to Null
		this->right = nullptr; // Right child of the node points to Null
	}
};

class BinaryTree
{
public:
	Node *root;

	BinaryTree()
	{ // No argument Constructor
		root = nullptr;
	}

	void addNode(char data)
	{ // Function to add a new node to the Binary Tree
		Node *newNode = new Node(data);

		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			Node *focusNode = root;
			Node *parent;

			while (true)
			{
				parent = focusNode;

				if (data < focusNode->data)
				{
					focusNode = focusNode->left;
					if (focusNode == nullptr)
					{
						parent->left = newNode;
						return;
					}
				}
				else
				{
					focusNode = focusNode->right;
					if (focusNode == nullptr)
					{
						parent->right = newNode;
						return;
					}
				}
			}
		}
	}
	// Function for Pre-order Traversal
	void preOrderTraversal(Node *focusNode)
	{
		if (focusNode != nullptr)
		{
			cout << focusNode->data << " ";
			preOrderTraversal(focusNode->left);
			preOrderTraversal(focusNode->right);
		}
	}

	// Function for In-order Traversal
	void inOrderTraversal(Node *focusNode)
	{
		if (focusNode != nullptr)
		{
			inOrderTraversal(focusNode->left);
			cout << focusNode->data << " ";
			inOrderTraversal(focusNode->right);
		}
	}
	// Function for Post-order Traversal
	void postOrderTraversal(Node *focusNode)
	{
		if (focusNode != nullptr)
		{
			postOrderTraversal(focusNode->left);
			postOrderTraversal(focusNode->right);
			cout << focusNode->data << " ";
		}
	}
};

int main()
{
	BinaryTree tree;

	tree.addNode('H');
	tree.addNode('I');
	tree.addNode('J');
	tree.addNode('K');
	tree.addNode('L');
	tree.addNode('M');
	tree.addNode('N');
	tree.addNode('O');
	tree.addNode('A');
	tree.addNode('B');
	tree.addNode('C');
	tree.addNode('D');
	tree.addNode('E');
	tree.addNode('F');
	tree.addNode('G');

	cout << endl
		 << "************Pre-Order Traversal*************" << endl;
	tree.preOrderTraversal(tree.root);
	cout << endl
		 << "************In-Order Traversal*************" << endl;
	tree.inOrderTraversal(tree.root);
	cout << endl
		 << "************Post-Order Traversal*************" << endl;
	tree.postOrderTraversal(tree.root);

	return 0;
}
