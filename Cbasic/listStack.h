#include <stdlib.h>
#include <stdio.h>
struct list_el
{
  int number;
  struct list_el *next;
};
typedef struct list_el node
;
node *root,*cur,*prev;//3 bien toan cuc
node *makeNewNode(int a)
{
  node*new = (node*)malloc(sizeof(node));
  new->number=a;
  new->next =NULL;
  return new;
}
int empty()
{
  return (root==NULL); 
}
void push(int a)
{
 node *new = makeNewNode(a);
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
int pop()
{
int a;
  if(empty())
    printf("stack underflow");
  else
    {
 node* p = root;
 a = p->number;
 root = p->next;
 free(p);
cur =root;
   }
  return a;
}

