#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address_t
{
  char name[20];
  char tell[11];
  char email[25];
}phoneaddr;
struct list_el
{
  phoneaddr addr;
  struct list_el *next;
};
typedef struct list_el node_addr;
node_addr *root,*cur,*prev;//3 bien toan cuc
node_addr *makeNewNode()
{
  node_addr *new = (node_addr*)malloc(sizeof(node_addr));
  strcpy((new->addr).name,"Tran Van Thanh");
  strcpy((new->addr).tell,"0936573204");
  strcpy((new->addr).email,"tranthanh@gmail.com");
  new->next =NULL;
  return new;
}
int main()
{
  root = makeNewNode();
  cur = root;
  printf("%s\n",(root->addr).name);
  return 0;
}
 
