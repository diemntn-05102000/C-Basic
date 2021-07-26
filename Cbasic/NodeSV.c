#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student_t
{
  char ID[20];
  char name[11];
  char grade[25];
  struct student_t *next
}student;


student *root,*cur,*prev;//3 bien toan cuc

node_addr *makeNewNode(elementtype element)
{
  node_addr *new = (node_addr*)malloc(sizeof(node_addr));
  new->element=element;
  new->next =NULL;
  return new;
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
student *readSV()
{
  student*p;
  printf("Nhap ten:");
  scanf("%s",p.name);
   printf("Nhap ID:");
 scanf("%s",p.ID);
   printf("Nhap email:");
 scanf("%s",p.grade);
  return p;
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
  elementtype a,b,c;
  node_addr *p;
  a=readNode(a);
  insertAtHead(a);
  displayNode(root);
  b=readNode(b);
  insertAfCur(b);
  c=readNode(c);
  insertBfCur(c);
  traversingList();
  /* for(p=root; p!= NULL; p=p->next)
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
