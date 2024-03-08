#include<iostream>
using namespace std;
class Queue
{
private:
	int* array;
	int size; 
	int front;
	int rear;
public:
	//comment this
	Queue(int size)
	{
		array = new int[size];
		this->size = size;
		front = -1;
		rear = -1;
	}
	~Queue() 
	{
		delete[] array;
	}
	bool isEmpty()
	{
		if (front == -1)
			return true; 
		else
			return false;
	}
	bool isFull()
	{
		if (((rear + 1) % size) == front)
			return true;
		else
			return false;
	}
	bool enqueue(int num)
	{
		if (isFull())
		{
			cout << "overflow";
			return false;
		}
		if (isEmpty())
			rear = front = 0;
		else
			rear = (rear + 1) % size;
		array[rear] = num;
		return true;
	}
	bool dequeue()
	{
		if (isEmpty()) 
		{
			cout << "underflow";
			return false;
		}
		int num = array[front];
		cout << num << " : is dequeued" << endl;

		if (front == rear) 
		{
			front = -1;
			rear = -1;
		}
			 
		else
		{
			front = (front + 1) % size;
		}
			
		return true;
	}
		void display() 
		{
			if (isEmpty()) 
			{
				cout << "Queue is empty!" << endl;
				return;
			}
			int i = front;
			while (i != rear) 
			{
				cout << array[i] << " ";
				i = (i + 1) % size;
			}
			cout << array[rear] << endl; 
		}
};


int main()
{
	Queue q(5);
	if (q.isEmpty())
	{
		cout << "queue is empty" << endl;
	}
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	if (q.isFull())
	{
		cout << "queue is Full" << endl;
	}
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	system("pause");
}

