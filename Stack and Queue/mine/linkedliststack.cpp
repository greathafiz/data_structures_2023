#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int data) {
    Node* temp = new Node;

    temp->data = data;
    temp->next = top;
    top = temp;
}

void Pop() {
    Node *temp;

    if (top == NULL)
    {
        return;
    }

    temp = top;
    top = top->next;
    free(temp);
}

bool isEmpty()
{
    return top == NULL;
}

int peek()
{
    if (isEmpty())
    {
        exit(1);
    } else
    {
        return top->data;
    }
}

int main()
{
    Push(3);
    Push(7);
    Push(6);
    peek();
}