#include<iostream>

using namespace std;

struct  node
{
	int Data;
	struct node * Next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Stack
{
private:
	PNODE Head;
public:
	Stack();
	~Stack();

	void PUSH(int);
	int POP();
	int PEEP();
	void Dispaly();
};


int main()
{
	Stack obj1;
	Stack obj2;

	obj1.PUSH(11);
	obj1.PUSH(21);

	obj2.PUSH(101);
	obj2.PUSH(111);
	obj2.PUSH(121);

	obj1.Dispaly(); cout << "\n";
	obj2.Dispaly(); cout << "\n";

	cout << obj1.POP(); cout << "\n";
	cout << obj2.POP(); cout << "\n";
	obj1.Dispaly(); cout << "\n";
	obj2.Dispaly(); cout << "\n";
	cout << obj2.PEEP(); cout << "\n";

	int i;
	cin >> i;
}
Stack::Stack()
{
	Head = NULL;
}

Stack::~Stack()
{
	PNODE temp = Head;
	while (Head != NULL)
	{
		Head = Head->Next;
		delete temp;
		temp = Head;
	}
}
void Stack::PUSH(int value)
{
	PNODE NewN = NULL;

	NewN = new NODE;

	NewN->Data = value;
	NewN->Next = NULL;

	if (Head == NULL)
	{
		Head = NewN;
	}
	else
	{
		NewN->Next = Head;
		Head = NewN;
	}
}
int Stack::POP()
{
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		PNODE temp = Head;
		Head = Head->Next;
		int iRet = temp->Data;
		delete temp;
		return iRet;
	}
}
int Stack::PEEP()
{
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		return (Head->Data);	
	}
}
void Stack::Dispaly()
{
	PNODE temp = Head;
	while (temp != NULL)
	{
		cout << temp->Data << "\t";
		temp = temp->Next;
	}
}