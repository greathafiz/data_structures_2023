// Doubly Linked List Operations
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head;

// To create a new node in the heap which then returns a pointer to the address
Node *GetNewNode(int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// To insert a node at the head
void InsertAtHead(int data)
{
    Node *newNode = GetNewNode(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// To insert a new node after a given node OR at a given position
void InsertAtX(int n, int data)
{
    // if n == 1, data should be the head✅
    // if n < 1, print error message✅
    // if n > length of linked list, print error msg✅
    // else traverse to the n - 1 node and fix the links✅
    Node *newNode = GetNewNode(data);
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    if (n > len)
    {
        printf("Out of range... There are only %d items in the list\n", len);
        return;
    }
    temp = head;

    if (n < 1)
    {
        printf("Invalid index. Position must be >= 1\n");
        return;
    }
    if (n == 1)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    // newNode->next = temp->next;
    // newNode->prev = temp;
    // temp->next = newNode;
    // newNode->next->prev = newNode;
    
}

// To insert at the tail
void InsertAtTail(int data)
{
    Node *newNode = GetNewNode(data);
    Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// To delete a particular node at X position
void Delete(int n) {
    Node* temp1 = head;

    if (n == 1)
    {
        temp1->next->prev = NULL;
        head = temp1->next;
        delete temp1;
        return;
    }

    for (int i = 0; i < n-2; i++)
    {
        temp1 = temp1->next;
    }
    // if (temp1->next != NULL)
    // {
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        // temp1->next->prev = temp1;
        delete temp2;
    //     return;
    // }
    // if (temp1->next == NULL)
    // {
    //     Node* temp2 = temp1->next;
    //     temp1->next = NULL;
    //     delete temp2;
    //     // return;
    // }    
}

// To search for an item
void Search(int target)
{
    Node* temp = head;
    int index = 1;

    while (temp != NULL)
    {

        if (temp->data == target)
        {
            cout << "Item found at Node "<<index<<endl;
            return;
        }
        index++;
        temp = temp->next;
    }

    cout<<"Item not found";
}

// To display the nodes
void Print()
{
    Node *temp = head;

    printf("Forward: ");

    while (temp != NULL)
    {
        printf("%d<==>", temp->data);
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("NULL");
    }

    printf("\n");
}

// To reverse the linked list
void ReversePrint()
{
}

int main()
{
    head = NULL;

    InsertAtHead(2);
    Print();
    InsertAtHead(4);
    Print();
    InsertAtHead(6);
    Print();

    InsertAtTail(3);
    Print();
    InsertAtTail(5);
    Print();
    InsertAtTail(7);
    Print();

    InsertAtX(4, 10);
    Print();

    Delete(4);
    Print();

    Delete(6);
    Print();

    Search(5);
    Search(50);
}
