#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define MAX 1000
void CreatDT(DT *x)
{
	printf("Program: ");
	gets(x->ID);
	printf("Memory: ");
	scanf("%d%*c",&x->Mem);
}
void DisplayNODE(DT x)
{
	printf("%-20s%d\n",x.ID,x.Mem);
}
void DisplayLIST(LIST *l)
{
	NODE *p=l->Head;
	while(p!=NULL)
	{
		DisplayNODE(p->x);
		p=p->next;
	}
}
void PushRun(LIST *l,LIST *l2,DT b)
{
	EnQueue(l2,b);
	if(l2->Head->x.Mem <= l->Sum)
	{
		DT a=DeQueue(l2);
		EnQueue(l,a);
		l->Sum=l->Sum-a.Mem;
	}
}
void Kill(LIST *l,LIST *l2)
{
	if(!isEmpty(l))
	{
		DT x= DeQueue(l);
		l->Sum=l->Sum+x.Mem;
		if(!isEmpty(l2))
		while(l->Sum>=l2->Head->x.Mem) 
			{
				DT a=DeQueue(l2);
				EnQueue(l,a);
				l->Sum=l->Sum-a.Mem;
				if(isEmpty(l2)) break;
			}
	}
	else if (!isEmpty(l2)) 
	{
	DeQueue(l2);
	if(!isEmpty(l2))		
	while(l->Sum>=l2->Head->x.Mem) 
			{
				DT a=DeQueue(l2);
		EnQueue(l,a);
		l->Sum=l->Sum-a.Mem;
			if(isEmpty(l2)) break;
			}
	}
	else printf("Het chuong trinh dang chay va cho\n");
}
void Empty(LIST *l,int x)
{
	l->Head=l->Tail=NULL;
	l->Sum=x;
}
int main()
{
	LIST *l=(LIST *)malloc(sizeof(LIST));
	LIST *l2=(LIST *)malloc(sizeof(LIST));
	Empty(l,MAX);
	int a;
	DT x;
	Empty(l2,0);
	do
	{
		printf("Moi ban chon: \n");
		printf("1. Creat program\n");
		printf("2. Kill program\n");
		printf("3. Display\n");
		printf("0. Exit\n");
		printf("Ban chon: ");
		scanf("%d%*c",&a);
		switch(a)
		{
			case 1:
				CreatDT(&x);
				PushRun(l,l2,x);
				break;
			case 2:
				Kill(l,l2);
				break;
			case 3:
				printf("Running: \n");
				printf("%-20s%s\n","ID","Memory");
				DisplayLIST(l);
				printf("Waiting: \n");
				printf("%-20s%s\n","ID","Memory");
				DisplayLIST(l2);
				break;
		}		
	}while(a!=0);
	Free(l);
	Free(l2);
	return 0;
}
