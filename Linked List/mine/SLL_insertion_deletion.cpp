// Linked List: Insertion and Deletion
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head;


//To insert at the head
// void Insert_Head(int data)
// {
//     Node* temp = new Node();
//     temp->data = data;
//     temp->next = NULL;

//     if (head != NULL)
//     {
//         temp->next = head;
//     }
//     head = temp;
// }

// To insert at nth position

void InsertAtX(int n, int data) {
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = NULL;

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
        newNode->next = head;
        head = newNode;
        return;
    }
    
    for (int i = 0; i < n-2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


//To insert at the end
void Insert(int data)
{
    // Create new node
    Node* temp = new Node();

    temp->data = data;
    temp->next = NULL;

    // If list is empty, make the head pointer to the new node 
    if (head == NULL)
    {
        head = temp;
        return;
    }

    // Get the address of the head node and traverse to the end node or tail
    Node* temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    // Assign the address of the new node to the 'next' component of the last node
    temp1->next = temp; 
}

// Function to delete the
// node at nth position
void Delete(int n)
{
    Node* temp1 = head;
    int len = 0;

    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        len++;
    }

    if (n > len)
    {
        printf("Out of range... There are only %d items in the list\n", len);
        return;
    }

	temp1 = head;

    if (n == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }

    for (int i = 0; i < n-2; i++) // int i = 1; i < n-1; also works
    {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void Print()
{
    Node* temp = head;

    
    printf("List is:");
    while (temp != NULL)
    {
        printf(" %d", temp->data); // cout << temp->data << " "; // (*temp).data also works instead of temp->data
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint() {

}



int main(){
    head = NULL;

    Insert(7);
    Insert(8);
    Insert(9);
    Insert(10);
    Insert(11);
    Insert(15);
    Insert(17);
    Insert(21);
    Print();
    Delete(3);
    Print();
    Delete(6);
    Print();

    InsertAtX(3,22);
    Print();

    return 0;
}