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
  address tmp= p->addr;
  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tell,tmp.email);
}
address readNode(address tmp)
{
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
  }
}
void insertBfCur(address addr)
{
  node_addr *tmp;
  tmp = root;
  while(tmp != NULL && tmp->next !=cur && cur != NULL)
    tmp = tmp->next;
  prev = tmp;
   node_addr *new = makeNewNode(addr);
   if(root == NULL)
     {
       root = new;
       cur = root;
       prev=NULL;
     }
   else{
   
    new ->next = cur;
    if(cur == root)
      {
	root = new;
      }
    else{
      prev->next =new;
    }
    cur = new;
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
void deleteFistElement()
{
 node_addr * p = root;
if(root = NULL)
  return ;
 root = p->next;
 free(p);
cur =root;
}
void deleteBfCur()
{
 node_addr *tmp;
  tmp = root;
  while(tmp != NULL && tmp->next !=cur && cur != NULL)
    tmp = tmp->next;
  prev = tmp;
  if(cur == NULL)
    {
      return;
    }
  if(cur == root)
    deleteFistElement();
  else{
  prev->next = cur->next;
  free(cur);
  cur = prev->next;
  }
}
node_addr *list_reverse(node_addr *root)
{
  node_addr *cur,*prev;
  cur = prev = NULL;
  while(root != NULL)
    {
      cur = root;
      root = root->next;
      cur->next = prev;
      prev=cur;
    }
  return prev;
}
int main()
{
  address a,b,c;
  node_addr *p;
  a=readNode(a);
  insertAtHead(a);
  displayNode(root);
  b=readNode(b);
  insertAfCur(b);
  c=readNode(c);
  insertBfCur(c);
  traversingList();
  for(p=root; p!= NULL; p=p->next)
    {

 displayNode(list_reverse(p));
    }
  /*deleteFistElement();
   traversingList();
   printf("success\n");
  deleteBfCur();
  traversingList();
  printf("success\n");*/
  freeList();
  return 0;                                                                               
}

