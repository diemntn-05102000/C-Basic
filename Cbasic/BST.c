#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct Node
{
  KeyType key;
  struct Node* left,*right;
  
}NodeType;
typedef NodeType* TreeType;
TreeType Search(KeyType x,TreeType Root)
{
  if(Root == NULL)return NULL;
  else if (Root->key == x)
    return Root;
  else if(Root->key < x)
    return Search(x, Root->right);
  else
    {
      return Search(x, Root->left);
    }
}
void InsertNode1(KeyType x, TreeType *Root)
{
  if(*Root==NULL)
    {
      *Root=(NodeType*)malloc(sizeof(NodeType));
      (*Root)->key =x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if (x < (*Root)->key)return InsertNode1(x,& (*Root)->left);
  else if (x > (*Root)->key)return InsertNode1(x,& (*Root)->right);
}
TreeType InsertNode2(KeyType x, TreeType Root)
{
 if(Root==NULL)
    {
      Root=(NodeType*)malloc(sizeof(NodeType));
      Root->key =x;
      Root->left=NULL;
      Root->right=NULL;
    }
  else if (x < Root->key)return InsertNode2(x,Root->left);
  else if (x > Root->key)return InsertNode2(x,Root->right);
}
void InOrderPrint(TreeType root)
{
if(root!=NULL)
    {
      InOrderPrint(root->left);
      printf("%d\n",root->key);
      InOrderPrint(root->right);
    }
}
KeyType DeleteMin(TreeType *Root)
{
  KeyType k;
  if((*Root)->left == NULL)
    {
      k=(*Root)->key;
      (*Root) = (*Root)->right;
      return k;
    }
  else return DeleteMin(&(*Root)->left);
}
void DeleteNode(KeyType x,TreeType *Root)
{
  if(*Root!=NULL)
    {
    if(x < (*Root)->key) DeleteNode(x,&(*Root)->left);
    else if(x > (*Root)->key) DeleteNode(x,&(*Root)->right);
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
  int a[10]={4,9,5,100,26,18,13,77,1,34};
  int i,s,x;
  TreeType root=NULL;
  for(i=0;i<10;i++)
    {
      InsertNode1(a[i], &root);
    }
  InOrderPrint(root);
  printf("Nhap phan tu can tim:");
  scanf("%d",&s);
  if( Search(s,root)->key==s)
    printf("Tim thay phan tu!!!\n");
  printf("Nhap phan tu muon xoa:");
  scanf("%d",&x);
  DeleteNode(x,&root);
  InOrderPrint(root);
  FreeTree(root)
  return 0;
}
