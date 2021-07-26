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
node_addr *root,*cur,*prev;//3 bien toan cuc

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
void insertAfCur(elementtype element)
{
  node_addr *new = makeNewNode(element);
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
void insertBfCur(elementtype element)
{
  node_addr *tmp;
  tmp = root;
  while(tmp != NULL && tmp->next !=cur && cur != NULL)
    tmp = tmp->next;
  prev = tmp;
   node_addr *new = makeNewNode(element);
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
void deleteCur()
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
void list_reverse(node_addr **root)
{
  node_addr *cur= *root;
  node_addr *prev=NULL;
  node_addr *next;//luu phan tu sau cur

  while(cur != NULL)
    {
      next = cur->next;
      cur->next = prev;
      prev=cur;
     cur=next;
    }
  *root=prev;
  //cur=prev;
 }
node_addr *insertAtPosition(node_addr *root,elementtype add,int n)
{
  int a=1;
  cur=root;
 node_addr *new = makeNewNode(add);
 if(root==NULL)
   {
     root =new;
   }
 if(n==0)
   insertAtHead( add);
 while(cur != NULL && a!=n)
   {
     cur = cur->next;
     ++a;
   }
 if(a!=n)
   printf("Khong tim thay vi tri can chen!!!\n");
 else{
new ->next = cur -> next;
    cur->next = new;
    cur = cur->next; 
 }
 return cur;
}
node_addr *deleteAtPosition(node_addr *root,int n)
{
  cur = root;
  int a=1;
   while(cur != NULL && a!=n)
   {
     cur = cur->next;
     ++a;
   }
  if(a!=n)
   printf("Khong tim thay vi tri can xoa!!!\n");
  
  node_addr *tmp;
  tmp = root;
  while(tmp != NULL && tmp->next !=cur && cur != NULL)
    tmp = tmp->next;
  prev = tmp;
 
 prev->next = cur->next;
  free(cur);
  cur = prev->next;
 
 return root;
}
int main()
{
  int n,m;
  elementtype a,b,c,d;
 node_addr *p;
  a=readNode(a);
  insertAtHead(a);
  displayNode(root);
  b=readNode(b);
  insertAfCur(b);
  c=readNode(c);
  insertBfCur(c);
  traversingList();
  printf("Nhap node muon chen:\n");
  d=readNode(d);
  printf("Nhap vi tri muon chen:\n");
  scanf("%d",&n);
  insertAtPosition(root,d, n);
  printf("List sau khi chen:\n");
  traversingList();
  printf("Nhap vi tri muon xoa:\n");
  scanf("%d",&m);
  deleteAtPosition(root, m);
  traversingList();
 
  /* printf("Dao nguoc list.\n");
  list_reverse(&root);
 traversingList();
  deleteFistElement();
   traversingList();
   printf("success\n");
  deleteCur();
  traversingList();
  printf("success\n");*/
  freeList();
  return 0;                                                                               
}
