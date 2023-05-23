#include <iostream>
using namespace std;

// A doubly linked list node
struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
};

// inserts node at the front of the list
void insert_front(struct Node **head, int new_data)
{
   // allocate memory for New node
   struct Node *newNode = new Node;

   // assign data to new node
   newNode->data = new_data;

   // new node is head and previous is null, since we are adding at the front
   newNode->next = (*head);
   newNode->prev = NULL;

   // previous of head is new node
   if ((*head) != NULL)
      (*head)->prev = newNode;

   // head points to new node
   (*head) = newNode;
}
/* Given a node as prev_node, insert a new node after the given node */
void insert_After(struct Node *prev_node, int new_data)
{
   // check if prev node is null
   if (prev_node == NULL)
   {
      cout << "Previous node is required , it cannot be NULL";
      return;
   }
   // allocate memory for new node
   struct Node *newNode = new Node;

   // assign data to new node
   newNode->data = new_data;

   // set next of newnode to next of prev node
   newNode->next = prev_node->next;

   // set next of prev node to newnode
   prev_node->next = newNode;

   // now set prev of newnode to prev node
   newNode->prev = prev_node;

   // set prev of new node's next to newnode
   if (newNode->next != NULL)
      newNode->next->prev = newNode;
}

// insert a new node at the end of the list
void insert_end(struct Node **head, int new_data)
{
   // allocate memory for node
   struct Node *newNode = new Node;

   struct Node *last = *head; // set last node value to head

   // set data for new node
   newNode->data = new_data;

   // new node is the last node , so set next of new node to null
   newNode->next = NULL;

   // check if list is empty, if yes make new node the head of list
   if (*head == NULL)
   {
      newNode->prev = NULL;
      *head = newNode;
      return;
   }

   // otherwise traverse the list to go to last node
   while (last->next != NULL)
      last = last->next;

   // set next of last to new node
   last->next = newNode;

   // set last to prev of new node
   newNode->prev = last;
   return;
}

void deleteNode(struct Node **head, struct Node *del)
{
   /* base case */
   if (*head == NULL || del == NULL)
      return;

   /* If node to be deleted is head node */
   if (*head == del)
      *head = del->next;

   /* Change next only if node to be deleted is NOT
      the last node */
   if (del->next != NULL)
      del->next->prev = del->prev;

   /* Change prev only if node to be deleted is NOT
      the first node */
   if (del->prev != NULL)
      del->prev->next = del->next;

   /* Finally, free the memory occupied by del*/
   free(del);
}

void deleteNodeAtGivenPos(struct Node **head, int n)
{
   /* if list in NULL or invalid position is given */
   if (*head == NULL || n <= 0)
      return;

   struct Node *current = *head;
   int i;

   /* traverse up to the node at position 'n' from
      the beginning */
   for (int i = 1; current != NULL && i < n; i++)
      current = current->next;

   /* if 'n' is greater than the number of nodes
      in the doubly linked list */
   if (current == NULL)
      return;

   /* delete the node pointed to by 'current' */
   deleteNode(head, current);
}

// This function prints contents of linked list starting from the given node
void displayList(struct Node *node)
{
   struct Node *last;

   while (node != NULL)
   {
      cout << node->data << "<==>";
      last = node;
      node = node->next;
   }
   if (node == NULL)
      cout << "NULL";
}

// main program
int main()
{
   /* Start with the empty list */
   struct Node *head = NULL;

   // Insert 40 as last node
   insert_end(&head, 40);

   // insert 20 at the head
   insert_front(&head, 20);

   // Insert 10 at the beginning.
   insert_front(&head, 10);

   // Insert 50 at the end.
   insert_end(&head, 50);

   // Insert 30, after 20.
   insert_After(head->next, 30);

   cout << "Doubly linked list after insertion operation: " << endl;
   displayList(head);

   // delete second node
   deleteNode(&head, head->next);
   cout << "\nDoubly linked list after deletion operation : " << endl;
   displayList(head);

   deleteNodeAtGivenPos(&head, 1); // Delete item at position 3

   cout << "\nDoubly linked list after deletion operation : " << endl;
   displayList(head);

   return 0;
}
