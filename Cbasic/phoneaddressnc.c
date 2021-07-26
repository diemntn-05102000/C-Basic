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
int main()
{
  address a;
   strcpy(a.name,"Tran Van Thanh");
  strcpy(a.tell,"0936573204");
  strcpy(a.email,"tranthanh@gmail.com");
  root = makeNewNode(a);
  cur = root;
  printf("%s\n",(root->addr).name);
  printf("%s\n",(root->addr).tell);
  printf("%s\n",(root->addr).email);
  return 0;
}
