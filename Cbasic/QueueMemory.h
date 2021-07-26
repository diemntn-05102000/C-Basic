#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
  char ID[20];
  int Mem;
}DT;
typedef struct NODE
{
  DT x;
  struct NODE *next;
  struct NODE *prew;
}NODE;
typedef struct
{
  NODE *Head;
  NODE *Tail;
  int Sum;
}LIST;
int isEmpty(LIST *l)
{
	return(l->Head==NULL);
}
NODE *CreatNODE(DT a)
{
	NODE *p=(NODE *)malloc(sizeof(NODE));
	if(p==NULL)	return NULL;
	p->x=a;
	p->next=NULL;
	p->prew=NULL;
	return p;
}
void EnQueue(LIST *l,DT a)
{
	NODE *p=CreatNODE(a);
	if(l->Head==NULL) l->Head=l->Tail=p;
	else
	{
		l->Tail->next=p;
		p->prew=l->Tail;
		l->Tail=p;
	}
}
void Free(LIST *l)
{
	NODE *p=l->Head;
	while(p!=NULL)
	{
		l->Head=l->Head->next;
		free(p);
		p=l->Head;
	}
	free(p);
}
DT DeQueue(LIST *l)
{
	NODE *p=l->Head;
	DT a=p->x;
	if (isEmpty(l)) exit(0);
	if(l->Head->next==NULL) l->Head=l->Tail=NULL;
	else
	{
		l->Head=l->Head->next;
		l->Head->prew=NULL;
	}
	free(p);
	return a;
}
