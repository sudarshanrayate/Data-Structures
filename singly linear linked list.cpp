#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

struct node									// it is declration of our node which is part of link list
{
	int data;
	struct node * next;
};

typedef struct node NODE;					// we cerate our own "typedef" that we can use in our program (NODE is typedef of struct node)
typedef struct node * PNODE;				//PNODE is typdef of struct node *
typedef struct node * * PPNODE;				//PPNODE is typedef of struct node * *

void InsertFirst(PPNODE, int);
void Display(PNODE);
int Count(PNODE);
void InsertLast(PPNODE, int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE, int, int);
void DeleteAtPos(PPNODE, int);



int main()
{
	PNODE first = NULL;					// it is a pointer which hoalds the address of first node of our link list
	int iRet = 0;
	InsertFirst(&first, 101);
	InsertFirst(&first, 51);
	InsertFirst(&first, 21);
	InsertFirst(&first, 11);
	Display(first);
	iRet = Count(first);
	printf("Number of elements are : %d\n", iRet);

	InsertLast(&first, 111);
	InsertLast(&first, 121);

	Display(first);
	DeleteFirst(&first);
	Display(first);
	DeleteLast(&first);
	Display(first);
	
	InsertAtPos(&first, 201,5);
	Display(first);

	DeleteAtPos(&first, 4);
	Display(first);

	scanf_s("%d", &iRet);
	return 0;
}
void InsertFirst(PPNODE head, int iValue)
{
	PNODE NewN = NULL;							//Create one pointer which hoalds address of new node.

	NewN = (PNODE)malloc(sizeof(NODE));			//Allocate dynamic memory of our new node.

	NewN->data = iValue;
	NewN->next = NULL;

	if (*head == NULL)							//control comes into if part if link list is empty 
	{
		*head = NewN;							//as we into if part our new node is first node. due to which we can store the address of new node into pointer through head pointer.
	}
	else 										//control comes into else if linklist contains single node
	{
		NewN->next = *head;						//store the address of prevoius first node into next pointer of our new node
		*head = NewN;							//store the address of new node into first pointer through the head ponter.
	}
}

void Display(PNODE head)						//As this function is not going to modify anything.
{
	printf("Elements from link list are :\n");

	while (head != NULL)						//Travers link list till our head pointer becomes NULL.
	{
		printf("|%d|->", head->data);			//Display the contents of node. 
		head = head->next;						//Increment the header pointer by one location
	}
	printf("NULL\n");
}

int Count(PNODE head)							//As this function is not going to modify anything.
{
	int iCnt = 0;

	while (head != NULL)
	{
		iCnt++;									//Increment the counter.
		head = head->next;					//Increment the header pointer by one location
	}

	return iCnt;								//Return the vale of counter
}
void InsertLast(PPNODE head, int iValue)		//same as InsertFirst.
{
	PNODE NewN = NULL;							//Create one pointer which hoalds address of new node.
	PNODE Temp = *head;							//Temprary pointer

	NewN = (PNODE)malloc(sizeof(NODE));			//Allocate dynamic memory of our new node

	NewN->data = iValue;
	NewN->next = NULL;

	if (*head == NULL)							//control comes into if part if link list is empty 
	{
		*head = NewN;							//as we into if part our new node is first node. due to which we can store the address of new node into pointer through head pointer.
	}
	else 										//control comes into else part if linklist cotains atlest one element
	{
		while (Temp->next != NULL)
		{
			Temp = Temp->next;
		}

		Temp->next = NewN;
	}
}
void DeleteLast(PPNODE head)
{
	PNODE Temp = *head;						// Temprary pointer is requried because we want to perform the Traversal.

	if (*head == NULL)						// if linklist is empty than we have to written directly.
	{
		return;
	}
	else if ((*head)->next == NULL)			// if link list atlest one node than we enter into this else if
	{
		free(Temp);							// free the physical memory of node by using free().
		*head = NULL;						// as our link list contain only ne node & that node also deleted, due to which we have to set NULL into the 'first' pointer through 'head' pointer
	}
	else
	{
		while (Temp -> next -> next != NULL)//by using temprary pinter travers till the 2nd last node.
		{
			Temp = Temp->next;
		}
		
		free(Temp->next);					//Physically remove the memory of last node
		Temp->next = NULL;					//store Null into the 'next' pointer of old 2nd last node.
	}
}

void DeleteFirst(PPNODE head)
{
	PNODE Temp = *head;

	if (*head == NULL)						//if link list empty than we have to return from fuction directly.
	{
		return;
	}
	else									//counter comes into else if link list contains atlest one node.
	{
		(*head) = (*head)->next;			//store the address of second node (if avalable) into 'first' pointer through head pointer
		free(Temp);							// remove the physical memory of first node whose address presrved in temp pointer
	}
}

void InsertAtPos(PPNODE head, int iValue, int iPos)
{
	PNODE Temp = *head;
	PNODE NewN = NULL;
	int iSize = Count(*head);				//Before display any logic we count the length of link list.
	int i = 0;
	if ((iPos < 1) || (iPos > (iSize + 1))) // if position is invalid than we return directly
	{
		return;
	}
	if (iPos == 1)							//if position is 1 than we call InserFirst() function (Reusability of code).
	{
		InsertFirst(head, iValue);
	}
	else if (iPos == (iSize + 1))			// if position is last position than we call InsertLast() function.
	{
		InsertLast(head, iValue);
	}
	else									//control comes into else part if position is in between the first & last node.
	{
		NewN = (PNODE)malloc(sizeof(NODE)); //allocate memory for new node & iniliazed it.

		NewN->data = iValue;
		NewN->next = NULL;

		for (i = 1; i <= (iPos - 2); i++)	//traverse the 'Temp' pointer till the previous node at which we have to insert new node
		{
			Temp = Temp->next;
		}

		NewN->next = Temp->next;			//store the address of next node into next pinter of prevous node.
		Temp->next = NewN;					//store the address of next node into next pointer of previous node.
	}
}

void DeleteAtPos(PPNODE head, int iPos)
{
	PNODE Temp1 = *head;
	PNODE Temp2 = NULL;
	int i = 0;
	int iSize = Count(*head);

	if ((iPos < 1) || (iPos > iSize))
	{
		return;
	}

	if (iPos = 1)
	{
		DeleteFirst(head);
	}
	else if (iPos == iSize)
	{
		DeleteLast(head);
	}
	else
	{
		for (i = 1; i <= (iPos - 2); i ++ )
		{
			Temp1 = Temp1->next;
		}

		Temp2 = Temp1->next;

		Temp1->next = Temp2->next;
		free(Temp2);
	}
}