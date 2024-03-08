#include<iostream>
using namespace std;
class queue
{
private:
	int* array; 
	int size; 
	int front;
	int rear;
	int count; 
public:
	queue(int s) 
	{
		array = new int[s];
		size = s;
		front = -1;
		rear = -1;
		count = 0;
	}
	~queue() 
	{
		delete[] array;
	}
	bool isEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (count == size)
			return true;
		else
			return false;
	}
	bool enqueue(int num)
	{
		if (isFull())
		{
			cout << "overflow"<<endl;
			return false;
		}
		rear = (rear + 1) % size;
		array[rear] = num;
		count++;
		return true;
	}
	bool dequeue()
	{
		if (isEmpty())
		{
			cout << "underflow"<<endl;
			return false;
		}
		front = (front + 1) % size;
		int num = array[front];
		count--;
		cout << num << " is dequeued" << endl;
		return true;
	}
		void display()
		{
			if (isEmpty())
			{
				cout << "Queue is empty!" << endl;
				return;
			}
			int i = 0;
			while (i <= rear)
			{
				cout << array[i] << " ";
				i++;
			}
			cout << endl;
		}
};

int main()
{
	queue q(5);
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


