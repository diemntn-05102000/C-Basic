#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address_t
{
  char name[20];
  char tell[11];
  char email[25];
}address;
struct list_el
{
  address addr;
  struct list_el *next;
};
typedef struct list_el node_addr;
node_addr *root,*cur,*prev;//3 bien toan cuc

node_addr *makeNewNode(address addr)
{
  node_addr *new = (node_addr*)malloc(sizeof(node_addr));
  new->addr=addr;
  new->next =NULL;
  return new;
}
void insertAtHead(address addr)
{
  node_addr*new = makeNewNode(addr);
  new ->next = root;
  root = new;
  cur = root;
}
void displayNode(node_addr *p)
{
  if(p==NULL)
    {
      printf("Loi con tro\n");
      return;
    }
  address tmp= p->addr;
  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tell,tmp.email);
}
address readNode(address tmp)
{
  printf("Nhap ten:");
  tmp.name=getchar();
   printf("Nhap tell:");
 tmp.tell= getchar();
   printf("Nhap email:");
  tmp.email=getchar();
  return tmp;
}
int main()
{
  address a;
  readNode(a);
  insertAtHead(a);
  displayNode(root);
 
  return 0;
}

