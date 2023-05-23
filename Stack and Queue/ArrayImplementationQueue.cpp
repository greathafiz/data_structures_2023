# include <iostream>
using namespace std;
// A structure to represent a queue
class Queue {
public:
	int Front, Rear, Size;
	unsigned Capacity;
	char* Array;  // the data type can be changed to another
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned Capacity)
{
	Queue* Queue1 = new Queue();
	Queue1->Capacity = Capacity;
	Queue1->Front = Queue1->Size = 0;

	// This is important, see the enqueue
	Queue1->Rear = Capacity - 1;
	Queue1->Array = new char[Queue1->Capacity];
	return Queue1;
}

// Queue is full when size
// becomes equal to the capacity
int isFull(Queue* Queue1)
{
	return (Queue1->Size == Queue1->Capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* Queue1)
{
	return (Queue1->Size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* Queue1, char item)
{
	if (isFull(Queue1))
		return;
	Queue1->Rear = (Queue1->Rear + 1)
				% Queue1->Capacity;
	Queue1->Array[Queue1->Rear] = item;
	Queue1->Size = Queue1->Size + 1;
	cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* Queue1)
{
	if (isEmpty(Queue1))
		return 0;
	int item = Queue1->Array[Queue1->Front];
	Queue1->Front = (Queue1->Front + 1)
				% Queue1->Capacity;
	Queue1->Size = Queue1->Size - 1;
	return item;
}

// Function to get front of queue
char Front(Queue* Queue1)
{
	if (isEmpty(Queue1))
		return 0;
	return Queue1->Array[Queue1->Front];
}

// Function to get rear of queue
char Rear(Queue* Queue1)
{
	if (isEmpty(Queue1))
		return 0;
	return Queue1->Array[Queue1->Rear];
}

// Driver code
int main()
{
	Queue* Queue2 = createQueue(50);

	enqueue(Queue2, 'A');
	enqueue(Queue2, 'B');
	enqueue(Queue2, 'C');
	enqueue(Queue2, 'D');

	cout << dequeue(Queue2)
		<< " dequeued from queue\n";

	cout << "Front item is "
		<< Front(Queue2) << endl;
	cout << "Rear item is "
		<< Rear(Queue2) << endl;

	return 0;
}
