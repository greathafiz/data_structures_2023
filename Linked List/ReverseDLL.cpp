#include <iostream>
using namespace std;
//node declaration for doubly linked list
struct Node {
   char data;
   struct Node *prev, *next;
};

Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->prev = temp->next = nullptr;
   return temp;
}
void displayList(Node* head)
{
   while (head->next != nullptr) {
      cout << head->data << " <==> ";
      head = head->next;
      }
   cout << head->data << endl;
}

// Insert a new node at the head of the list
void insert(Node** head, int node_data)
{
   Node* temp = newNode(node_data);
   temp->next = *head;
   (*head)->prev = temp;
   (*head) = temp;
}

// reverse the doubly linked list
void reverseList(Node** head)
{
   Node* left = *head, * right = *head;

   // traverse entire list and set right next to right
   while (right->next != nullptr)
   right = right->next;

   //swap left and right data by moving them towards each other till they meet or cross
   while (left != right && left->prev != right) {

      // Swap left and right pointer data
      swap(left->data, right->data);

      // Advance left pointer
      left = left->next;

      // Advance right pointer
      right = right->prev;
   }
}
int main()
{
   Node* headNode = newNode('E');
   insert(&headNode, 'D');
   insert(&headNode, 'C');
   insert(&headNode, 'B');
   insert(&headNode, 'A');
   cout << "Original doubly linked list: " << endl;
   displayList(headNode);
   cout << "Reverse doubly linked list: " << endl;
   reverseList(&headNode);
   displayList(headNode);

   return 0;
}
