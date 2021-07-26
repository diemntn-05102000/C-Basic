#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address_t
{
  char name[20];
  char tell[11];
  char email[25];
}address;
typedef address elementtype;
struct list_el
{
  elementtype element;
  struct list_el *next;
};
typedef struct list_el node_addr;
node_addr *root,*cur,*prev;
node_addr *root1,*root2;
int soluong=0;
node_addr *makeNewNode(elementtype element)
{
  node_addr *new = (node_addr*)malloc(sizeof(node_addr));
  new->element=element;
  new->next =NULL;
  return new;
}
void insertAtHead(elementtype element)
{
  node_addr *new = makeNewNode(element);
   if( root == NULL)
    {
      root = new;
      cur = root;
    }else{
  new ->next = root;
  root = new;
  cur = root;
   }
}
void displayNode(node_addr *p)
{
  if(p==NULL)
    {
      printf("Loi con tro\n");
      return;
    }
  elementtype tmp= p->element;
  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tell,tmp.email);
}
node_addr *importFromText(FILE *fptr1)
{
  elementtype member[20];
	while(!feof(fptr1))
	  {
		fscanf(fptr1,"%s %s %s\n",member[soluong].name,member[soluong].tell,member[soluong].email);
		insertAtHead(member[soluong]);
		soluong++;
	}
	printf("%d\n",soluong);
	
	printf("Thanh cong\n");
	return root;
}
void traversingList(node_addr *root)
{
  node_addr *p;
  for(p=root; p!= NULL; p=p->next)
    displayNode(p);
}
void freeList(node_addr *root)
{
  node_addr *to_free = root;
  while(to_free != NULL)
    {
      root = root->next;
      free(to_free);
      to_free = root;
    }
}
void splitList(int n1,int n2)
{
  int a=1;
   cur=root;
   
  if(n1==0)
    {
      root1=root;
      while(cur!=NULL && a!=n2)
	{

	  cur=cur->next;
	  a++;
	}
      root2=cur->next;
      cur->next=NULL;
      printf("Success!!!\n");
    }
  else
    {
      int b=0;
      int c=1;
      node_addr *q=root;
      while(cur!=NULL && b!=n1)
	{
	  cur=cur->next;
	  b++;
	}
      root1=cur;
      while(cur!=NULL && c!=n2)
	{
	  cur=cur->next;
	  c++;
	}
      if(cur==NULL)
	{
	  while(q->next!=root1)
	    q=q->next;
	  root2=root;
	  q->next=NULL;  
	}
      else
	{
	  root2=root;
          while(q->next!=root1)
	    q=q->next;
	  node_addr *f=root;
	  while(f!=cur->next)
	    f=f->next;
	  q->next=f;
	  cur->next=NULL;
	}
      printf("Success!!!\n");
    }
}
int main()
{
  FILE *f1;
  int n1,n2;
  f1=fopen("phone.txt","r");
  if(f1==NULL)
    {
      printf("Cannot file!!!");
      return 0;
    }
  root=importFromText(f1);
  traversingList(root);
   do
     {
  printf("Nhap vi tri muon split:");
  scanf("%d",&n1);
   }while(n1>=soluong && n1<0 );
  printf("Nhap so luong node:");
  scanf("%d",&n2);
  splitList(n1,n2);
  printf("Sub_list 1:\n");
  traversingList(root1);
  printf("Sub_list 2:\n");
  traversingList(root2);
  freeList(root);
  freeList(root1);
  freeList(root2);
  fclose(f1);
  return 0;
}
