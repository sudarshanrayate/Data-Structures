#include<iostream>;

using namespace std;

struct node
{
	int Data;
	node * Next;
	node * Prev;

};
typedef struct node NODE;
typedef struct node *  PNODE;

class DoublyCircular 
{
 protected:
	PNODE Head;
	PNODE Tail;
	int iSize;
public:
	DoublyCircular();
	~DoublyCircular();
	DoublyCircular(DoublyCircular &);

	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPos(int, int);

	void DisplayF();
	void DisplayB();
	int Count();

	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);

};

DoublyCircular::DoublyCircular()
{
	this->Head = NULL;
	this->Tail = NULL;
	iSize = 0;

}
DoublyCircular::~DoublyCircular()
{
	PNODE Temp = this->Head;
	if (Head != NULL)
	{
		for (int i = 1; i < iSize; i++)
		{
			Head = Head->Next;
			delete Temp;
			Temp = Head;
		}
	}
}
DoublyCircular::DoublyCircular(DoublyCircular & ref)
{
	PNODE NewN = NULL;
	PNODE Temp1 = ref.Head;
	PNODE Temp2 = NULL;

	this->iSize = ref.iSize;
	if (iSize != 0)
	{
		for (int i = 1; i < iSize; i++)
		{
			
			NewN = new NODE;
			NewN->Data = Temp1->Data;
			NewN->Next = NULL;
			NewN->Prev = NULL;

			if ((Head == NULL) && (Tail == NULL))
			{
				this->Head = NewN;
				this->Tail = NewN;
				Temp2 = Head;
			}
			else
			{
				Temp2->Next = NewN;
				NewN->Prev = Temp2;
				Temp2 = NewN;
				Tail = Temp2;
			}
			Head->Prev = Tail;
			Tail->Next = Head;

			Temp1 = Temp1->Next;
		}
		
	}

	
}

void DoublyCircular::InsertFirst(int Value)
{
	PNODE NewN = NULL;
	NewN = new NODE;

	NewN->Data = Value;
	NewN->Next = NULL;
	NewN->Prev = NULL;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = NewN;
		Tail = NewN;
	}
	else
	{
		NewN->Next = Head;
		Head->Prev = NewN;
		Head = NewN;
	}
	Head->Prev = Tail;
	Tail->Next = Head;
	iSize++;
}
void DoublyCircular::InsertLast(int Value)
{
	PNODE NewN = NULL;
	NewN = new NODE;

	NewN->Data = Value;
	NewN->Next = NULL;
	NewN->Prev = NULL;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = NewN;
		Tail = NewN;
	}
	else
	{
		Tail->Next = NewN;
		NewN->Prev = Tail;
		Tail = NewN;
	}
	Head->Prev = Tail;
	Tail->Next = Head;
	iSize++;
}
void DoublyCircular::InsertAtPos(int Value, int iPos)
{
	if ((iPos < 1) && (iPos > (iSize + 1)))
	{
		return;
	}

	if (iPos == 1)
	{
		InsertFirst(Value);
	}
	else if (iPos == (iSize + 1))
	{
		InsertLast(Value);
	}
	else
	{
		PNODE Temp = Head;
		PNODE NewN = NULL;
		NewN = new NODE;

		NewN->Data = Value;
		NewN->Next = NULL;
		NewN->Prev = NULL;

		for (int i = 1; i < (iPos-1); i++)
		{
			Temp = Temp->Next;
		}
		NewN->Next = Temp->Next;
		Temp->Next->Prev = NewN;
		Temp->Next = NewN;
		NewN->Prev = Temp;
		iSize++;
	}

}

void DoublyCircular::DisplayF()
{
	PNODE Temp = Head;
	if ((Head == NULL) &&(Tail == NULL) )
	{
		return;
	}
	do
	{
		cout << Temp->Data << "\t";
		Temp = Temp->Next;
	} while (Temp != Tail->Next);
}
void DoublyCircular::DisplayB()
{
	if ((Head == NULL) && (Tail == NULL))
	{
		return;
	}
	do
	{
		cout << Tail->Data << "\t";
		Tail = Tail->Prev;
	} while (Tail != Head->Prev);
}

int DoublyCircular::Count()
{
	return iSize;
}

void DoublyCircular::DeleteFirst()
{
	
	if ((Head == NULL) && (Tail == NULL)&&(iSize == 0))
	{
		return;
	}
	else if(Head == Tail)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head->Next;
		delete Tail->Next;
		Head->Prev = Tail;
		Tail->Next = Head;
	}
	iSize--;
}
void DoublyCircular::DeleteLast()
{
	if ((Head == NULL) && (Tail == NULL) && (iSize == 0))
	{
		return;
	}
	else if (Head == Tail)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Tail = Tail->Prev;
		delete Head->Prev;
		Head->Prev = Tail;
		Tail->Next = Head;
	}
	iSize--;
}
void DoublyCircular::DeleteAtPos(int iPos)
{
	if ((Head == NULL) && (Tail == NULL) && (iSize == 0))
	{
		return;
	}
	if ((iPos < 1) && (iPos > iSize))
	{
		return;
	}
	if (iPos == 1)
	{
		DeleteFirst();
	}
	else if (iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE Temp1 = Head;
		for (int i = 1; i <= (iPos - 2); i++)
		{
			Temp1 = Temp1->Next;
		}
		

		Temp1->Next = Temp1->Next->Next;
		delete Temp1->Next->Prev;
		Temp1->Next->Prev = Temp1;
		iSize--;
	}
}
int main()
{
	/*cout << "Enter Node Value : ";
	int NodeVal = 0;
	cin >> NodeVal;*/

	DoublyCircular obj1;
	obj1.InsertFirst(101);
	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);

	cout << "\n";
	cout << "Display Forword : ";
	obj1.DisplayF();
	cout << "\n";
	cout << "Display Backword : "; 
	obj1.DisplayB();

	cout << "\n";
	cout << "Node Count is : " << obj1.Count() << "\n";
	cout << "\n";

	obj1.InsertLast(111);
	obj1.InsertLast(121);
	obj1.InsertLast(151);

	cout << "\n";
	cout << "Display Forword : ";
	obj1.DisplayF();
	cout << "\n";
	cout << "Display Backword : ";
	obj1.DisplayB();

	cout << "\n";
	cout <<"Node Count is : "<< obj1.Count() << "\n";
	cout << "\n";

	obj1.InsertAtPos(65, 2);
	obj1.InsertAtPos(45, 5);
	obj1.InsertAtPos(55, 7);
	
	cout << "\n";
	cout << "Display Forword : ";
	obj1.DisplayF();
	cout << "\n";
	cout << "Display Backword : ";
	obj1.DisplayB();

	cout << "\n";
	cout << "Node Count is : " << obj1.Count() << "\n";
	cout << "\n";

	obj1.DeleteFirst();

	cout << "\n";
	cout << "Display Forword : ";
	obj1.DisplayF();
	cout << "\n";

	cout << "\n";
	cout << "Node Count is : " << obj1.Count() << "\n";
	cout << "\n";

	obj1.DeleteLast();

	cout << "\n";
	cout << "Display Forword : ";
	obj1.DisplayF();
	cout << "\n";

	cout << "\n";
	cout << "Node Count is : " << obj1.Count() << "\n";
	cout << "\n";

	obj1.DeleteAtPos(4);

	cout << "\n";
	cout << "Display Forword : ";
	obj1.DisplayF();
	cout << "\n";

	cout << "\n";
	cout << "Node Count is : " << obj1.Count() << "\n";
	cout << "\n\n\n";
	
	cout << "Copy Constructor";
	DoublyCircular obj2(obj1);
	cout << "\n";
	cout << "Display Forword : ";
	obj2.DisplayF();
	cout << "\n";
	cout << "Display Backword : ";
	obj2.DisplayB();
	return 0;
}