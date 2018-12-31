#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

struct  node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node * * PPNODE;

void InsertFirst(PPNODE, int);
void DisplayF(PNODE);
void InsertLast(PPNODE, int);
void DisplayB(PNODE);
int Count(PNODE);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE, int, int);
void DeleteAtPos(PPNODE, int);

int main()
{
	PNODE first = NULL;
	int iRet = 0;
	InsertFirst(&first, 51);
	InsertFirst(&first, 21);
	InsertFirst(&first, 11);

	DisplayF(first);
	DisplayB(first);

	iRet = Count(first);
	printf("\n");
	printf("Number of elements are : %d\n", iRet);

	InsertLast(&first, 101);
	DisplayF(first);
	DisplayB(first);

	DeleteFirst(&first);
	DisplayF(first);
	DisplayB(first);
	DeleteLast(&first);
	DisplayF(first);
	DisplayB(first);
	InsertAtPos(&first, 151, 3); InsertAtPos(&first, 201, 4);
	DisplayF(first);
	DeleteAtPos(&first, 3);
	DisplayF(first); scanf_s("%d");
	return 0;
}

void InsertFirst(PPNODE head, int value)
{
	PNODE NewN = NULL;

	NewN = (PNODE)malloc(sizeof(NODE));				//Allocate memory for New Node.

	NewN->data = value;								// inialized members of new node.
	NewN->next = NULL;
	NewN->prev = NULL;

	if (*head == NULL)								//if link list is empty than store the address of new node in
	{
		*head = NewN;
	}
	else
	{												//if link list contains atleast one node then control comes into else part.
		NewN->next = *head;
		(*head)->prev = NewN;						//maintain previous pointer of old first node.
		*head = NewN;
	}
}

void DisplayF(PNODE head)
{
	while (head != NULL)
	{
		printf("|%d|<=>", head->data);
		head = head->next;
	}printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;
	while (head != NULL)
	{
		iCnt++;
		head = head->next;
	}

	return iCnt;
}

void DisplayB(PNODE head)
{	if (head == NULL) { return; }
	while (head->next != NULL)						//travers the link list till last node.
	{
		head = head->next;
	}
	printf("NULL");
	while (head != NULL)							//traverse the link list backward derection till head becomes NULL
	{
		printf("<=>|%d|", head->data);
		head = head->prev;
	}
	printf("\n");
}

void InsertLast(PPNODE head, int value)
{
	PNODE NewN = NULL;
	PNODE Temp = *head;

	NewN = (PNODE)malloc(sizeof(NODE));

	NewN->data = value;
	NewN->next = NULL;
	NewN->prev = NULL;

	if (*head == NULL)
	{
		*head = NewN;
	}
	else
	{
		while (Temp->next != NULL)
		{
			Temp = Temp->next;
		}

		Temp->next = NewN;
		NewN->prev = Temp;
	}
}

void DeleteFirst(PPNODE head)
{
	if (*head == NULL)								//if link list is empty than we return directly
	{
		return;
	}
	else if ((*head)->next == NULL)					//if link list contains one node than delete that node
	{
		free(*head);
		*head = NULL;
	}
	else											//if link list contains more than one node
	{
		*head = (*head)->next;						// store the address of second node into 'first' pointer through head
		free((*head)->prev);						//physically remove the memory of first node
		(*head)->prev = NULL;						//store NULL into 'prev' pointerof 'first' node
	}
}

void DeleteLast(PPNODE head)
{
	PNODE Temp = *head;

	if (*head == NULL)
	{
		return;
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		while (Temp->next != NULL)
		{
			Temp = Temp->next;
		}
		
		Temp->prev->next = NULL;
		free(Temp);
	}
}

void InsertAtPos(PPNODE head, int value, int iPos)
{
	int iSize = Count(*head);
	int i = 0;
	PNODE NewN = NULL, Temp = *head;
	if ((iPos < 1) || (iPos > (iSize + 1)))
	{
		return;
	}
	if (iPos == 1)
	{
		InsertFirst(head, value);
	}
	else if (iPos == (iSize + 1))
	{
		InsertLast(head, value);
	}
	else
	{
		NewN = (PNODE)malloc(sizeof(NODE));

		NewN->data = value;
		NewN->next = NULL;
		NewN->prev = NULL;


		for (i = 1; i < (iPos - 2); i++)
		{
			Temp = Temp->next;
		}

		NewN->next = Temp->next;
		NewN->next->prev = NewN;
		Temp->next = NewN;
		NewN->prev = Temp;
	}
}

void DeleteAtPos(PPNODE head, int iPos)
{
	PNODE Temp = *head;
	int i = 0;
	int iSize = Count(*head);

	if ((iPos < 1) || (iPos > iSize))
	{
		return;
	}
	if (iPos == 1)
	{
		DeleteFirst(head);
	}
	else if (iPos == iSize)
	{
		DeleteLast(head);
	}
	else
	{
		for (i = 1; i < (iPos - 2); i++)
		{
			Temp = Temp->next;
		}

		Temp->next = Temp->next->next;
		free(Temp->next->prev);
		Temp->next->prev = Temp;
	}
}