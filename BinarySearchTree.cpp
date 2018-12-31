#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define TRUE 1;
#define FALSE 0;
struct node
{
	struct node * Lchild;
	int data;
	struct node * Rchild;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
typedef int BOOL;

void Insert(PPNODE, int);
void InOrder(PNODE);
void PreOrder(PNODE);
void PostOrder(PNODE);
BOOL Search(PNODE, int);
int Count(PNODE);
int CountLeafNode(PNODE);

void Insert(PPNODE Root, int iValue)
{
	PNODE Temp = *Root;

	PNODE NewN = NULL;
	NewN = (PNODE)malloc(sizeof(NODE));

	NewN->Lchild = NULL;
	NewN->data = iValue;
	NewN->Rchild = NULL;

	if (*Root == NULL)
	{
		*Root = NewN;
	}
	else
	{
		while (1)
		{
			if (iValue > Temp->data)
			{
				if (Temp->Rchild == NULL)
				{
					Temp->Rchild = NewN;
					break;
				}
				Temp = Temp->Rchild;
			}
			else if(iValue < Temp->data)
			{
				if (Temp->Lchild == NULL)
				{
					Temp->Lchild = NewN;
					break;
				}
				Temp = Temp->Lchild;
			}
			else if (iValue == Temp->data)
			{
				free(NewN);
				break;
			}
		}
	}
}

void InOrder(PNODE Root)
{
	if (Root != NULL)
	{
		InOrder(Root->Lchild);
		printf("%d\t", Root->data);
		InOrder(Root->Rchild);
	}
}

void PreOrder(PNODE Root)
{
	if (Root != NULL)
	{
		printf("%d\t", Root->data);
		PreOrder(Root->Lchild);
		PreOrder(Root->Rchild);
	}
}

void PostOrder(PNODE Root)
{
	if (Root != NULL)
	{
		PostOrder(Root->Lchild);
		PostOrder(Root->Rchild);
		printf("%d\t", Root->data);
	}
}

BOOL Search(PNODE Root, int Value)
{
	if (Root == NULL)
	{
		return FALSE;
	}
	while (Root != NULL)
	{
		if (Value == Root->data)
		{
			break;
		}
		else if (Value > Root->data)
		{
			Root = Root->Rchild;
		}
		else
		{
			Root = Root->Lchild;
		}
	}

	if (Root == NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int Count(PNODE Root)
{
	static int iCnt = 0;

	if (Root != NULL)
	{
		iCnt++;
		Count(Root->Lchild);
		Count(Root->Rchild);
	}
	return iCnt;
}

int CountLeafNode(PNODE Root)
{
	static int iCnt = 0;
	
	if (Root != NULL)
	{
		if ((Root->Lchild) && (Root->Rchild) == NULL)
		{
			iCnt++;
		}
		CountLeafNode(Root->Lchild);
		CountLeafNode(Root->Rchild);
	}
	return iCnt;
}
int main()
{
	PNODE Head = NULL;
	int iRet = 0;
	Insert(&Head, 21);
	Insert(&Head, 51);
	Insert(&Head, 11);
	Insert(&Head, 10);
	Insert(&Head, 12);
	Insert(&Head, 111);
	Insert(&Head, 11);
	Insert(&Head, 42);

	InOrder(Head);
	printf("\n");

	PreOrder(Head);
	printf("\n");

	PostOrder(Head);
	printf("\n");

	iRet = Search(Head, 11);
	if (iRet == 1)
	{
		printf("Number is avilable in tree.\n");
	}
	else
	{
		printf("Number is not avilable in tree.\n");
	}


	iRet = Count(Head);
	printf("Number of node in tree is : %d\n", iRet);

	iRet = CountLeafNode(Head);
	printf("Number of Leaf Node in tree is : %d\n", iRet);
	return 0;
}