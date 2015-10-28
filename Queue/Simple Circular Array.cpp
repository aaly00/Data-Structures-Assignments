#include <iostream>
#include <cstdlib>
using namespace std;
struct arrayqueue{
	int end;
	int front;
	int capacity;
	int* array;
};

struct arrayqueue *queue(int size)
{
	arrayqueue *q = new arrayqueue;
	if (!q)
		return NULL;
	q->capacity = size;
	q->end = q->front = -1;
	q->array = new int[size];
	if (!q)
		return NULL;
	return q;
}

bool isEmpty(arrayqueue *q)
{
	return (q->front == -1);
}
bool isFull(arrayqueue *q)
{
	return ((q->end+1)%q->capacity==q->front);
}
void enqueue(arrayqueue*q,int data)
{
	if (isFull(q))
	{
		cout << "Exception\nTrying to write to Empty or Full queue\n";
		return;
	}
	q->end = (++q->end) % q->capacity;
	q->array[q->end] = data;
	if (q->front == -1)
	{
		q->front = q->end;
	}
}
int dequeue(arrayqueue *q)
{
	int data;
	if (isEmpty(q))
	{
		cout << "Exception\nTrying to write to Empty or Full queue\n";
		return 0;
	}
	data = q->array[q->front];
	if (q->front == q->end)
	{
		q->front = q->end = -1;
	}else
	q->front = (++q->front) % q->capacity;
	
	return data;
}
void printqueue(arrayqueue *q)
{
	if (isEmpty(q))
	{
		cout << "Exception\nEmpty queue\n";
		return;
	}
	if (q->end<q->front)
	{
		for (int i = q->front; i <= q->end; i = (++i)%q->capacity)
		{
			cout << q->array[i] << endl;
		}
	}
	else{
		for (int i = q->front; i <= q->end; i++)
		{
			cout << q->array[i] << endl;
		}
	}
}
int queuesize(arrayqueue *q)
{
	if (q->end < q->front)
	{
		return(1 + q->end + q->front);
	}
	else return(1 + q->end - q->front);
}

void main()
{
		int selection, data, loopcontrol, size;
		cout << "Array implementaion of Queue" << endl;
		cout << "Enter the size of the array" << endl;
		cin >> size;
		struct arrayqueue * q = queue(size);
		do{
			cout << "Please make a choice" << endl;
			cout << "1. Enter Queue" << endl;
			cout << "2. Leave Queue" << endl;
			cout << "3. Check queue size" << endl;
			cout << "4. Check if queue is empty" << endl;
			cout << "5. check if queue is full" << endl;
			cout << "6. Print queue" << endl;
			cin >> selection;
			switch (selection)
			{
			case 1:
				cout << "What is the value you want to put in queue" << endl;
				cin >> data;
				enqueue(q, data);
				break;
			case 2:
				cout << "Value that exited the queue is " << dequeue(q) << endl;
				break;
			case 3:
				cout << "Queue size is " << queuesize(q) << endl;
				break;
			case 4:
				if (isEmpty(q))
					cout << "Queue is empty" << endl;
				else cout << "Queue is not empty" << endl;
				break;
			case 5:
				if (isFull(q))
					cout << "Queue is full" << endl;
				else cout << "Queue is not full" << endl;
				break;
			case 6:
				printqueue(q);
				break;

			}
			cout << "Run the program again, press 1 for yes" << endl;
			cin >> loopcontrol;
		} while (loopcontrol == 1);
		return;
}