#include<iostream>
using namespace std;
struct Component
{
    char item; // data type can be changed to another type
    Component *nextPtr ;
};
class Queue
{
    Component *Front, *Rear;

public:
    Queue()
    {
        Front = Rear = NULL;  //   Initially

    }
    void Enqueue(char Data)    // for insertion from rear
    {
        Component *newComponent;
        newComponent = new Component;
        newComponent->item = Data;
        newComponent->nextPtr = NULL;

        if(Front == NULL)
            Front = Rear = newComponent;
        else
        {
            Rear->nextPtr = newComponent;
            Rear = newComponent;
        }
    }
    void Dequeue()            // for deletion from front
    {
        Component *temp;
        if(Front == NULL)
            cout<<"Queue is Empty";
        else
        {
            temp= Front;
            Front = Front->nextPtr;
            delete temp;
        }

    }
    void display()
    {
        Component *temp;
        temp= Front;
        while(temp!=NULL) // (temp!= rear->next)
        {
            cout<<temp->item<<" ";
            temp = temp->nextPtr;
        }
        cout<<endl;
    }
};
int main()

{
    Queue Q1;
    Q1.Enqueue('A');
    Q1.Enqueue('B');
    Q1.Enqueue('C');
    Q1.display();
    cout<<"\n";
    Q1.Dequeue();
    cout<<"Queue after Dequeue"<<endl;
    Q1.display();
}
