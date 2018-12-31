#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node * * PPNODE;

void InsertFirst(PPNODE, PPNODE, int);
void InsertLast(PPNODE, PPNODE, int);
void InsertAtPos(PPNODE, PPNODE, int,int);

void DeleteFirst(PPNODE, PPNODE);
void DeleteLast(PPNODE, PPNODE);
void DeleteAtPos(PPNODE, PPNODE, int);

void Display(PNODE, PNODE);
int Count(PNODE, PNODE);






int main()
{
	PNODE first = NULL;
	PNODE last = NULL;
	int iRet = 0;
	InsertFirst(&first, &last, 51);
	InsertFirst(&first, &last, 21);
	InsertFirst(&first, &last, 11);
	Display(first, last);

	InsertLast(&first, &last, 101);
	InsertLast(&first, &last, 111);

	InsertAtPos(&first, &last, 121, 4);
	Display(first, last);

	DeleteFirst(&first, &last);
	Display(first, last);
	DeleteLast(&first, &last);
	DeleteAtPos(&first, &last, 3);
	Display(first, last);

	iRet = Count(first, last);
	printf("number of elements are : %d",iRet);




	scanf_s("%d");
	return 0;
}

void InsertFirst(PPNODE head, PPNODE tail, int value)		//as our link list is circular we have to pass address of 'first' pointer as well as 'last' pointer
{
	PNODE NewN = NULL;

	NewN = (PNODE)malloc(sizeof(NODE));

	NewN->data = value;
	NewN->next = NULL;

	if ((*head == NULL) && (*tail == NULL))					//if link list is empty means our node because first node. if 'first' & 'last' pointer contains the NULL than we conclude link list is empty.
	{
		*head = NewN;
		*tail = NewN;
		(*tail)->next = *head;								//this stement is use to maintain the circular nature of our link list. 
	}
	else
	{
		NewN->next = *head;
		*head = NewN;
		(*tail)->next = *head;
	}
}

void InsertLast(PPNODE head, PPNODE tail, int value)
{
	PNODE NewN = NULL;

	NewN = (PNODE)malloc(sizeof(NODE));

	NewN->data = value;
	NewN->next = NULL;

	if ((*head == NULL) && (*tail == NULL))					//if link list is empty means our node because first node. if 'first' & 'last' pointer contains the NULL than we conclude link list is empty.
	{
		*head = NewN;
		*tail = NewN;
		(*tail)->next = *head;								//this stement is use to maintain the circular nature of our link list. 
	}
	else													//as we want to insert the node at last position we have to address of last node there is no need of traversal link singly linear link list.
	{
		(*tail)->next = NewN;
		*tail = NewN;
		(*tail)->next = *head;
	}
}

void InsertAtPos(PPNODE head, PPNODE tail, int value, int iPos)
{
	PNODE temp = *head;
	PNODE NewN = NULL;
	int i = 0;
	int iSize = Count(*head, *tail);

	if ((iPos < 1) || (iPos > (iSize + 1)))
	{
		return;
	}

	if (iPos == 1)
	{
		InsertFirst(head, tail, value);
	}
	else if(iPos == (iSize + 1))
	{
		InsertLast(head, tail, value);
	}
	else
	{
		NewN = (PNODE)malloc(sizeof(NODE));

		NewN->data = value;
		NewN->next = NULL;

		for (i = 1; i <= (iPos - 2); i++)
		{
			temp = temp->next;
		}

		NewN->next = temp->next;
		temp->next = NewN;
	}
}

void DeleteFirst(PPNODE head, PPNODE tail)
{
	if ((*head == NULL) && (*tail == NULL))				//if link list is empty than reurn directy
	{
		return;
	}
	if (*head == *tail)									//if lin list contains atlest one node than we delete that node and set 'first' and 'last' pointer to NULL.
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
	else												//if link list contain more than one node than we have delete node physicaly & maintain the links accordingly.
	{
		*head = (*head)->next;
		free((*tail)->next);
		(*tail)->next = *head;
	}
}

void DeleteLast(PPNODE head, PPNODE tail)
{
	PNODE temp = *head;

	if ((*head == NULL) && (*tail == NULL))				//if link list is empty than reurn directy
	{
		return;
	}
	if (*head == *tail)									//if lin list contains atlest one node than we delete that node and set 'first' and 'last' pointer to NULL.
	{
		free(*tail);
		*head = NULL;
		*tail = NULL;
	}
	else												//if link list contain more than one node than we have delete node physicaly & maintain the links accordingly.
	{
		while (temp->next != *tail)						// we have traverse till second last node.
		{
			temp = temp->next;
		}

		free(*tail);
		*tail = temp;
		(*tail)->next = *head;
	}
}

void Display(PNODE head, PNODE tail)
{
	if ((head == NULL) && (tail == NULL))
	{
		return;
	}

	do
	{
		printf("%d    ", head->data);
		head = head->next;
	} while (head != tail->next); printf("\n");
}
int Count(PNODE head, PNODE tail)
{
	int iCnt = 0;
	if ((head == NULL) && (tail == NULL))
	{
		return -1;
	}

	do
	{
		iCnt++;
		head = head->next;
	} while (head != tail->next);

	return iCnt;
}

void DeleteAtPos(PPNODE head, PPNODE tail, int iPos)
{
	PNODE temp1 = *head;
	PNODE temp2 = NULL;
	int i = 0;
	int iSize = Count(*head, *tail);

	if ((*head == NULL) || (*tail == NULL))
	{
		return;
	}
	if ((iPos < 1) || (iPos > (iSize)))
	{
		return;
	}
	else if(*head == *tail)
	{
		DeleteFirst(head, tail);
	}
	else if (iPos == iSize)
	{
		DeleteLast(head, tail);
	}
	else
	{
		for (i = 1; i <= (iPos - 2); i++)
		{
			temp1 = temp1->next;
		}

		temp2 = temp1->next;

		temp1->next = temp2->next;
		free(temp2);
	}
}