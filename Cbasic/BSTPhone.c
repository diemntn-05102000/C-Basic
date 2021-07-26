#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleListQueue.h"
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
TreeType Search(char x[11],TreeType Root)
{
  if(Root == NULL)return NULL;
  else if (strcmp((Root->key).tel, x)==0)
    return Root;
  else if(strcmp((Root->key).tel, x)<0)
    return Search(x, Root->right);
  else
    {
      return Search(x, Root->left);
    }
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
TreeType InsertNode2(phoneaddress x, TreeType Root)
{
 if(Root==NULL)
    {
      Root=(NodeType*)malloc(sizeof(NodeType));
      Root->key =x;
      Root->left=NULL;
      Root->right=NULL;
    }
  else if (strcmp((Root->key).tel, x.tel)>0)return InsertNode2(x,Root->left);
  else if (strcmp((Root->key).tel, x.tel)<0)return InsertNode2(x,Root->right);
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
  QueueType queue=root;
  if(node!=NULL)
    {
      enqueue(node->key,queue);
      while(!isEmpty(queue))
	{
	  node=dequeue(queue);
	  phoneaddress tmp=node->key;
	  printf("%-20s\t%-15s\t%-30s\n",tmp.name,tmp.tell,tmp.email);
	  if(node->left != NULL)
	    enqueue(node->left->key,queue);
	  if(node->right != NULL)
	    enqueue(node->right->key,queue);
	}
    }
}
phoneaddress DeleteMin(TreeType *Root)
{
  phoneaddress k;
  if((*Root)->left == NULL)
    {
      k=(*Root)->key;
      (*Root) = (*Root)->right;
      return k;
    }
  else return DeleteMin(&(*Root)->left);
}
void DeleteNode(char x[11],TreeType *Root)
{
  if(*Root!=NULL)
    {
    if(strcmp(((*Root)->key).tel, x)>0) DeleteNode(x,&(*Root)->left);
    else if(strcmp(((*Root)->key).tel, x)<0) DeleteNode(x,&(*Root)->right);
    else if((*Root)->left==NULL&&(*Root)->left==NULL) *Root=NULL;
    else if((*Root)->left==NULL)
    *Root=(*Root)->right;
    else if((*Root)->right==NULL)
    *Root=(*Root)->left;
    else (*Root)->key = DeleteMin(&(*Root)->right);
  
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
int main()
{
  phoneaddress p[30],them;
  int i=0;
  char phone[11],xoa[11];
  TreeType root=NULL;
  FILE *f;
  f=fopen("phone.txt","r");
  if(f==NULL)
    {
    printf("Cannot open file\n");
    return 0;
    }
  while(!feof(f))
    {
      fscanf(f,"%s %s %s\n",p[i].name,p[i].tel,p[i].email);
      InsertNode1(p[i], &root);
      i++;
    }
  InOrderPrint(root);
  /* printf("Nhap SDT can tim:");
  gets(phone);
  if(Search(phone,root)!=NULL )
    printf("Tim thay!!!\n");
  printf("Nhap SDT muon xoa:");
 gets(xoa);
 DeleteNode(xoa,&root);
  DeleteNode(xoa,&root);
  InOrderPrint(root);
  printf("Nhap them :\n");
  printf("Nhap ten:");
 gets(them.name);
 printf("Nhap SDT:");
 gets(them.tel);
 printf("Nhap email:");
 gets(them.email);
 InsertNode1(them, &root);
 InOrderPrint(root);*/
  breadth_first(root);
 fclose(f);
 FreeTree(root);
  printf("Free success\n");
  return 0;
}
