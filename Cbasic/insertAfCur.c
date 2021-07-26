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
  node_addr *new = makeNewNode(addr);
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
  printf("%-15s%-11s%-30s\n",tmp.name,tmp.tell,tmp.email);
}
address readNode()

{
  address tmp;
  printf("Nhap ten:");
  scanf("%s",tmp.name);
   printf("Nhap tell:");
   scanf("%s",tmp.tell);
   printf("Nhap email:");
   scanf("%s",tmp.email);
  return tmp;
}
void insertAfCur(address addr)
{
  node_addr *new = makeNewNode(addr);
  if(cur ==NULL) return;
  if( root == NULL)
    {
      root = new;
      cur = root;
    }else{
    new ->next = cur -> next;
    cur->next = new;
    cur = cur->next;  
printf("success");
  }
}
void traversingList()
{
  node_addr *p;
  for(p=root; p!= NULL; p=p->next)
    displayNode(p);
}
void freeList()
{
  node_addr *to_free = root;
  while(to_free != NULL)
    {
      root = root->next;
      free(to_free);
      to_free = root;
    }
}
int main()
{
  address a,b;
  a=readNode();
  insertAtHead(a);
  displayNode(root);
  b=readNode();
  insertAfCur(b);
  
  traversingList();
  freeList();
  return 0;
}

