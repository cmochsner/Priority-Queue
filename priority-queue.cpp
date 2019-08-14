#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next = NULL;
};
class queue
{
	node *front;

public:
	queue()
	{
		front = NULL;
	}
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;
	}
	int getFront()
	{
		return front->data;
	}
	void enqueue(int el)
	{
		node *newnode = new node;
		newnode->data = el;

		if (isEmpty())
		{
			front = newnode;
			return;
		}
		if (front->data < el)
		{
			newnode->next = front;
			front = newnode;
			return;
		}

		node *curr = front;
		while (curr->next != NULL && curr->next->data > el)
		{
			curr = curr->next;
		}
		if (curr->next != NULL)
		{
			newnode->next = curr->next;
		}
		
		curr->next = newnode;
	}
	int dequeue()
	{
		if (isEmpty())
		{
			return 0;
		}
		int item = front->data;

		node *temp = front;
		front = front->next;

		free(temp);

		return item;
	}
	void print()
	{
		node *curr = front;
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main()
{
	cout << "Welcome to the 2nd LPT Printer Program! (Priority Queue)" << endl;

	queue q;
	int num;
	int size = 0;

	cout << "Enter the list of numbers you'd like to schedule. Seperate them by spaces or new lines. Enter -1 when finished." << endl;
	while (cin >> num)
	{
		if (num == -1)
		{
			break;
		}
		q.enqueue(num);
		size++;
	}

	int a[25];
	int b[25];
	int c[25];

	a[0] = q.dequeue();
	b[0] = q.dequeue();
	c[0] = q.dequeue();

	int numA = 0, numB = 0, numC = 0;

	while (!q.isEmpty())
	{
		if (a[numA] <= b[numB])
		{
			if (c[numC] < a[numA])
			{
				c[numC + 1] = q.dequeue() + c[numC];
				numC++;
			}
			else
			{
				a[numA + 1] = q.dequeue() + a[numA];
				numA++;
			}
		}
		else
		{
			if (c[numC] < b[numB])
			{
				c[numC + 1] = q.dequeue() + c[numC];
				numC++;
			}
			else
			{
				b[numB + 1] = q.dequeue() + b[numB];
				numB++;
			}
		}
	}

	cout << "\nHere's our final schedule for the printers! \nNote that subsequent numbers represent the total time for the printer after adding a new task to the schedule." << endl;

	cout << "\nPrinter A: ";
	for (int u = 0; u < numA; u++)
	{
		cout << a[u] << " ";
	}
	cout << a[numA] << endl;

	cout << "Printer B: ";
	for (int u = 0; u < numB; u++)
	{
		cout << b[u] << " ";
	}
	cout << b[numB] << endl;

	cout << "Printer C: ";
	for (int u = 0; u < numC; u++)
	{
		cout << c[u] << " ";
	}
	cout << c[numC] << endl;

	//system("pause");
	return 0;
}