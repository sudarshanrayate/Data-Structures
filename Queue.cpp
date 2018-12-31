#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
}NODE, * PNODE;

class Queue
{
private:
	PNODE head;
public:
	Queue();
	Queue(Queue &);
	~Queue();

	void EnQueue(int);
	int DeQueue();
	void Display();
};

Queue::Queue()
{
	head = NULL;
}

Queue::~Queue()
{
	PNODE temp = head;

	while (head != NULL)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}
Queue::Queue(Queue &ref)
{
	PNODE temp1 = ref.head;
	PNODE temp2 = NULL;
	head = NULL;
	while (temp1 != NULL)
	{
		PNODE NewN = NULL;

		NewN = new NODE;

		NewN->data = temp1->data;
		NewN->next = NULL;

		if (head == NULL)
		{
			head = NewN;
			temp2 = head;
		}
		else
		{
			temp2->next = NewN;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
void Queue::EnQueue(int value)
{
	PNODE NewN = NULL;

	NewN = new NODE;

	NewN->data = value;
	NewN->next = NULL;

	if (head == NULL)
	{
		head = NewN;
	}
	else
	{
		PNODE temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = NewN;
	}
}
int Queue::DeQueue()
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		PNODE temp = head;
		int iRet = head->data;
		head = head->next;
		delete temp;
		return iRet;
	}

}
void Queue::Display()
{
	PNODE temp = head;

	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
int main()
{
	Queue obj1;
	Queue obj2;

	obj1.EnQueue(11);
	obj1.EnQueue(21);

	obj2.EnQueue(101);
	obj2.EnQueue(111);
	obj2.EnQueue(121);

	obj1.Display();
	cout << "\n";
	obj2.Display();
	cout << "\n";

	cout << obj1.DeQueue()<<"\n";
	cout << obj2.DeQueue() << "\n";

	obj1.Display();
	cout << "\n";
	obj2.Display();
	cout << "\n";

	obj2.EnQueue(151);
	obj2.EnQueue(201);

	obj2.Display();
	
	cout << "\n";
	Queue obj3(obj2);
	obj3.Display();
	cout << "\n";
	int i;
	cin >> i;
	return 0;
}