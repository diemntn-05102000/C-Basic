#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phoneaddress
{
  char name[20];
  char tell[11];
  char email[25];
}elementtype;
typedef struct phoneNode
{
  elementtype element;
  struct phoneNode *next;
  struct phoneNode *prev;
}node;
node *root, *tail,*cur;
void makeNull_List(node *root,node *tail,node *cur)
{
  root=NULL;
  tail=NULL;
  cur=NULL;
}
int isEmpty (node *root)
{
  return (root==NULL);
}
node *MakeNewNode(elementtype addr)
{
  node *new = (node*)malloc(sizeof(node));
  new->element = addr;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
void InsertAtHead(elementtype e)
{
  node *new = MakeNewNode(e);
  if(root==NULL)
    {
      root = new;
      tail = new;
      return;
    }
  root->prev = new;
  new->next = root;
  root=new;
  cur=root;
}
node *DisplayTail()
{
if(tail==NULL)
    {
      return 0;
    }
 node*p=tail;
 tail=tail->prev;
 tail->next=NULL;
 return p;
}

elementtype ReadNode(elementtype element)
{
  printf("Nhap ten:");
  scanf("%s",element.name);
   printf("Nhap tell:");
 scanf("%s",element.tell);
   printf("Nhap email:");
 scanf("%s",element.email);
  return element;
}

void DisplayNode(node *p)
{
  if(p==NULL)
    {
      printf("Loi con tro\n");
      return;
    }
  elementtype tmp= p->element;
  //printf("S\n");
  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tell,tmp.email);
}

void enqueue( elementtype X)
{
  InsertAtHead(X);
}
node *dequeue()
{
  return DisplayTail();
}
