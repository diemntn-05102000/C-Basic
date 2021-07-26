#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1000
typedef int data;
typedef struct NODE
{
	data x;
	struct NODE *next;
}NODE;
typedef struct LIST
{
	NODE *top;
}LIST;
NODE *CreatNode(data x)
{
	NODE *new;
	new=(NODE*)malloc(sizeof(NODE));
	if (new==NULL)
	{
		printf("Error\n");
		return NULL;

	}
	else
	{
		new->x=x;
		new->next=NULL;
		return new;

	}
}
void push(LIST *l1,data x)
{
	NODE *tmp=CreatNode(x);
	if (l1->top==NULL)
	{
		l1->top=tmp;
	}
	else
	{
		tmp->next=l1->top;
		l1->top=tmp;

	}
}	
int Pop(LIST *l1)
{
	NODE *p=l1->top;
	if (p==NULL)
	{
		return -1;
	}
	else
	{
		l1->top=l1->top->next;
		int a=p->x;
		//printf("%d\n", a);
		free(p);
		return a;

	}
}
void Free(LIST *l)
{
	while(l->top!=NULL)
	Pop(l);
}
void GetList(LIST *l,char s[])
{
	for (int i = 0; i < strlen(s);i++)
	{
		int a=s[i]-'0';
		if (a<0 || a>9)
		{
			Free(l);
			break;
		}
		else
		{
			push(l,a);
		}
	}
	printf("thanh cong\n");
}
void Tru(LIST *l,LIST *l1,LIST *l2)
{
	int a=0,b=0,dem=0,c=0;

	while(1)
	{
		a=Pop(l1);
		b=Pop(l2);
		if(a==-1 && b==-1) break;
		//if(a==-1) a=0;
		if(b==-1) b=0;
		b=b+dem;
		if(a>=b)
		  {
		   c=a-b;
		   push(l,c);
		  }
		else
		  {
		    a=a+10;
		    dem=1;
		    c=a-b;
		    push(l,c);
		  }
	}
}
void In(LIST *l)
{
	while(l->top!=NULL)
	{
		printf("%d", Pop(l));
	}
}
