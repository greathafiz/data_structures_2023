//
#include <iostream>
using namespace std;
#define MAX 101

struct Stack
{
    int top = -1;
    int A[MAX];

    void push(int data);
    void pop();
    int peek();
    bool isEmpty();
    void print();
};

void Stack::push(int data)
{
    if (top == (MAX - 1))
    {
        cout << "⚠️Error: Stack Overflow";
        return;
    }
    A[++top] = data;
    // cout << data << " pushed into stack\n";
}

void Stack::pop()
{
    if (top < 0)
    {
        cout << "⚠️Error: Stack Underflow";
        return;
    }
    int data = A[top--];
    cout << data << " popped" << endl;
    return;
}

int Stack::peek()
{
    return A[top];
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::print()
{
    cout << "Stack: ";
    for (int i = 0; i <= top; i++)
    {
        // cout << A[i] << endl;
        printf("%d ", A[i]);
    }
    printf("\n");
    
}

int main()
{
    Stack stack;
    stack.push(2); stack.print();
    stack.push(4); stack.print();
    stack.push(6); stack.print();
    stack.push(8); stack.print();
    stack.push(9); stack.print();
    stack.pop(); stack.print();
}
