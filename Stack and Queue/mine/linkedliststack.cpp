#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Stack
{
    Node* top = NULL;

    void push(int data);
    void pop();
    bool isEmpty();
    int peek();
};



void Stack::push(int data) {
    Node* temp = new Node;

    temp->data = data;
    temp->next = top;
    top = temp;
}

void Stack::pop() {
    Node *temp;

    if (top == NULL)
    {
        return;
    }

    temp = top;
    top = top->next;
    free(temp);
}

bool Stack::isEmpty()
{
    return top == NULL;
}

int Stack::peek()
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
    Stack stack1;
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.pop();
    stack1.peek();
}