#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front = nullptr;
    Node *rear = nullptr;

    void enqueue(int data)
    {
        Node *temp = new Node;

        temp->data = data;
        temp->next = nullptr;

        if (isEmpty())
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        Node *temp = front;

        if (front == nullptr)
            return;
        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = temp->next;
            delete (temp);
        }
    }
    bool isEmpty()
    {
        return (front == nullptr && rear == nullptr);
    }

    // int Front() {
    //     if (front == nullptr)
    //     {
    //         cout << "Queue is empty";
    //         return 1;
    //     }
    //     return front->data;
    // }

    void Print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue queue1;

    queue1.enqueue(2);
    queue1.Print();
    queue1.enqueue(4);
    queue1.Print();
    queue1.enqueue(6);
    queue1.Print();
    queue1.dequeue();
    queue1.Print();
    queue1.enqueue(8);
    queue1.Print();
}