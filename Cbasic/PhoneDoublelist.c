#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phone_address
{
  char name[20];
  char tell[11];
  char email[25];
}address;
typedef address elementtype;
typedef struct node
{
  elementtype element;
  struct node *next;
  struct node *prev;
}node;
node *root, *tail,*cur;
void MakeNull_List(node *root,node *tail,node *cur)
{
  root=NULL;
  tail=NULL;
  cur=NULL;
}
int isEmpty (node *root)
{
  return (root==NULL);
}
node *makeNewNode(elementtype addr)
{
  node *new = (node*)malloc(sizeof(node));
  new->element = addr;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
void insertAtHead(elementtype e)
{
  node *new = makeNewNode(e);
  if(root==NULL)
    {
      root = new;
      tail = new;
      return;
    }
  root->prev = new;
  new->next=root;
  root=new;
  cur=root;
}
void insertAtTail(elementtype e)
{
node *new = makeNewNode(e);
  if(root==NULL)
    {
      root = new;
      tail = new;
      return;
    }
  tail->next = new;
  new->prev=tail;
  tail=new;
}
void insertAtPosition(elementtype add,int n)
{
   int a=0;
   int b=0;
  cur=root;
  node *p=tail;
  node *new = makeNewNode(add);
  if(root==NULL)
    {
      root = new;
      tail = new;
      return;
    }
 while(cur != NULL )
   {
     cur = cur->next;
     ++a;
   }
 cur=root;
 if(n<0||n>=a)
   printf("Khong tim thay vi tri can chen!!!\n");
 if(n==(a-1))
   insertAtTail(add);
 else
   {
 if((n*2)<=a)
   {
     while(cur!=NULL&& b!=n)
       {
	 cur=cur->next;
	 b++;
       }
     new->next=cur->next;
     new->prev=cur;
     cur->next->prev=new;
     cur->next=new;
   }
 b=0;
 if((n*2)>a)
   {
     while(tail!=NULL&& b!=(a-n-1) )
       {
	 p=p->prev;
	 b++;
       }
     new->next=p->next;
     new->prev=p;
     p->next->prev=new;
     p->next=new; 
   }
   }
}
void deleteAtHead()
{
 if(root==NULL)
    {
      return;
    }
 node*p=root;
 root=root->next;
 root->prev=NULL;
 free(p);
}
void deleteCur()
{
   node *p=cur;
  if(cur==NULL)
    return;
  if(cur==root)
    deleteAtHead();
  if(cur==tail)
    {
      tail=tail->prev;
      cur=tail;
      tail->next=NULL;
      free(p);
    }
  p->prev->next=p->next;
  p->next->prev=p->prev;
  free(p);
}
void deleteTail()
{
if(tail==NULL)
    {
      return;
    }
 node*p=tail;
 tail=tail->prev;
 tail->next=NULL;
 free(p);
}
void deleteAtPosition(int n)
{
  int a=0,b=0;
  node *p=tail;
  cur=root;
  while(cur != NULL )
   {
     cur = cur->next;
     ++a;
   }
 cur=root;
 if(n<0||n>=a)
   printf("Khong tim thay vi tri can xoa!!!\n"); 
 if(n==a-1)
   {
     deleteTail();
   }
 else
   {
     if((n*2)<=a)
   {
     while(cur!=NULL && b!=n)
       {
	 cur=cur->next;
	 b++;
       }
     deleteCur();
   }
 cur=root;
 if((n*2)>a)
   {
     while(tail!=NULL&& b!=(a-n-1) )
       {
	 p=p->prev;
	 b++;
       }
     cur=p;
     deleteCur();
   }
   }
}
elementtype readNode(elementtype element)
{
  printf("Nhap ten:");
  scanf("%s",element.name);
   printf("Nhap tell:");
 scanf("%s",element.tell);
   printf("Nhap email:");
 scanf("%s",element.email);
  return element;
}

void displayNode(node *p)
{
  if(p==NULL)
    {
      printf("Loi con tro\n");
      return;
    }
  elementtype tmp= p->element;
  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tell,tmp.email);
}
void traversingList()
{
  node *p;
  for(p=root; p!= NULL; p=p->next)
    displayNode(p);
}
void freelist()
{
  node *p=root;
  while(p!=NULL)
    {
      root=root->next;
      free(p);
      p=root;
    }
}
int main()
{
  int d,i;
  elementtype a,b,c,add;
  a=readNode(a);
  insertAtHead(a);
  displayNode(root);
  b=readNode(b);
  insertAtTail(b);
  c=readNode(c);
  insertAtHead(c);
  //deleteCur();
  traversingList();
  printf("Nhap vi tri muon xoa:");
  scanf("%d",&d);
  deleteAtPosition(d);
  traversingList();
  printf("Nhap vi tri muon chen:");
  scanf("%d",&i);
  printf("Nhap node muon chen:\n");
  add=readNode(add);
  insertAtPosition(add,i);
  traversingList();
  freelist();
  return 0;
}

