#include <iostream>
using namespace std;
class queue 
{
private:
    int* array;
    int front, rear, size;

public:
    queue(int size)
	{
        this->size = size;
        array = new int[size];
        front = rear = -1;
    }

    ~queue() 
	{
        delete[] array;
    }

    void enqueue(int value)
	{
        if ((rear + 1) % size == front)
		{
            cout << "queue is full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        array[rear] = value;
        if (front == -1) 
		{
            front = rear;
        }
    }

    int dequeue()
	{
        if (isEmpty()) 
		{
            cout << "queue is empty" << endl;
            return -1;
        }
        int value = array[front];
        if (front == rear)
		{
            front = rear = -1;
        }
        else
		{
            front = (front + 1) % size;
        }
        return value;
    }

    bool isEmpty() 
	{
        return front == -1;
    }

    void rearrange()
	{
        int half = (rear - front + 1) / 2;
        int* temp = new int[half]; 
        for (int i = 0; i < half; i++) 
		{
            temp[i] = dequeue();
        }
        for (int i = 0; i < half; i++) 
		{
            enqueue(temp[i]);
            enqueue(dequeue());
        }
        delete[] temp; 
    }
};

int main() 
{
    queue q(8);
    int arr[] = { 3, 2, 5, 6 ,7, 9, 8 ,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
	cout << "before rearranging : ";
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
    for (int i = 0; i < n; i++)
	{
        q.enqueue(arr[i]);
    }
    q.rearrange();
	cout << "after rearranging : ";
    while (!q.isEmpty())
	{
        cout << q.dequeue()<<" ";
    }
	cout << endl;
	system("pause");
}
