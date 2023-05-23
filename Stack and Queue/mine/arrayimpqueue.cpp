#include <iostream>
using namespace std;
#define MAX 101

struct Queue
{
    int Array[MAX];
    int front = -1;
    int rear = -1;

    void Enqueue(int data);
    void Dequeue();

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (front == (MAX - 1));
    }

    int Front()
    {
        if (front == -1)
        {
            cout <<"Error: cannot return front from empty queue\n";
            return 1;
        }
        int data = Array[front];
        return data;
        
    }
};



void Queue::Enqueue(int data)
{
    if (isFull())
    {
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    Array[rear] = data;
    cout << Array[rear] << endl;
}


void Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Cannot dequeue. Queue is empty";
        return;
    }
    else if (front == rear)
    {
        rear = front = -1;
    }
    else
    {
        // front++;
        front = (front + 1) % MAX;
        // int data = Array[front++];
        cout << front << " dequeued" << endl;
        // return;
    }
}

int main()
{
    Queue queue1;
    queue1.Enqueue(4);
    queue1.Enqueue(3);
    queue1.Enqueue(2);
    queue1.Enqueue(1);
    queue1.Dequeue();
    queue1.Enqueue(10);
    // queue1.Dequeue();
    // queue1.Front();
}