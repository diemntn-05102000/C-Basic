#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phoneaddress_t
{
  char name[20];
  char tel[11];
  char email[25];
}phoneaddress;
typedef struct Node
{
  phoneaddress key;
  struct Node* left,*right;
  
}NodeType;
typedef NodeType* TreeType;
typedef struct phoneNode
{
  NodeType element;
  struct phoneNode *next;
  struct phoneNode *prev;
}node;
node *root, *tail,*cur;
void makeNull_List(node *root,node *tail,node *cur)
{
  root=NULL;
  tail=NULL;
  cur=NULL;
  }
int isEmpty (node *root)
{
  return (root==NULL);
}
node *MakeNewNode(NodeType *addr)
{
  node *new = (node*)malloc(sizeof(node));
  new->element = *addr;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
void InsertAtHead(NodeType *e)
{
  node *new = MakeNewNode(e);
  if(root==NULL)
    {
      root = new;
      tail = new;
     
    }
  else
    {
    
    root->prev = new;
    new->next = root;
    root=new;
    cur=root;
    }
}
node *DisplayTail()
{
if(tail==NULL)
    {
      return 0;
    }
if(tail->prev==NULL)
   {
    node*p=tail;
    tail=NULL;
    root=NULL;
    return p;
    }
 else{
 node*p=tail;
 tail=tail->prev;
 tail->next=NULL;
 return p;
 }
}

void enqueue( NodeType *X,node *root)
{
  InsertAtHead(X);
}
NodeType *dequeue(node *root)
{
  node *p= DisplayTail();
  return &(p->element);
}
void InsertNode1(phoneaddress x, TreeType *Root)
{
  if(*Root==NULL)
    {
      *Root=(NodeType*)malloc(sizeof(NodeType));
      (*Root)->key =x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if (strcmp(((*Root)->key).tel, x.tel)>0)return InsertNode1(x,& (*Root)->left);
  else if (strcmp(((*Root)->key).tel, x.tel)<0)return InsertNode1(x,& (*Root)->right);
}
void InOrderPrint(TreeType root)
{
if(root!=NULL)
    {
      InOrderPrint(root->left);
      printf("%-20s%-11s%-25s\n ",(root->key).name,(root->key).tel,(root->key).email);
      InOrderPrint(root->right);
    }
}
void breadth_first(TreeType node)
{
  if(node!=NULL)
    {
      phoneaddress tmp;
      enqueue(node,root);
      printf("Duyet cay theo chieu rong!!!\n");
      while(!isEmpty(root))
	{
	
	  node=dequeue(tail);
	  tmp=node->key;
	  
	  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tel,tmp.email);
	  if(node->left != NULL)
	    enqueue(node->left,root);
	  
	  if(node->right != NULL)
	    enqueue(node->right,root);
	}
    }
}
void FreeTree(TreeType Root)
{
  if(Root!=NULL)
    {
      FreeTree(Root->left);
      FreeTree(Root->right);
      free(Root);
      
    }
}
void freequeue(node *root)
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
  //makeNull_List(root,tail,cur);
  phoneaddress p[30],them;
  int i=0;
  char phone[11],xoa[11];
  TreeType Root=NULL;
  FILE *f;
  f=fopen("phone.dat","rb");
  if(f==NULL)
    {
    printf("Cannot open file\n");
    return 0;
    }
    fread(p,sizeof(p),5,f);
	for (int i = 0; i < 5; i++)
	  {
      InsertNode1(p[i], &Root);
     
	  }
  printf("Duyet cay theo thu tu giua!!!\n");
  InOrderPrint(Root);
  breadth_first(Root);
  fclose(f);
  freequeue(root);
 FreeTree(Root);
  printf("Free success\n");
  return 0;
}
