#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elementtype;
typedef struct node
{
  elementtype element;
  struct node *left;
  struct node *right;
}node_type;
typedef  node_type *treetype ;
void MakeNullTree(treetype *T)
{
  (*T)=NULL;
}
int EmptyTree(treetype T)
{
  return T==NULL;
}
treetype LeftChild(treetype n)
{
  if(n!=NULL) return n->left;
  else return NULL;
}
treetype RightChild(treetype n)
{
  if(n!=NULL) return n->right;
  else return NULL;
}
node_type *makeNewNode(elementtype addr)
{
  node_type *new = (node_type*)malloc(sizeof(node_type));
  new->element = addr;
  new->left=NULL;
  new->right=NULL;
  return new;
}
int IsLeaf(treetype T)
{
  if(T!=NULL)
    {
      return(LeftChild(T)==NULL&&RightChild(T)==NULL);
    }
  else return -1;
}
treetype createfrom2(elementtype v,treetype l, treetype r)
{
  treetype N;
  N=(node_type*)malloc(sizeof(node_type));
  N->element=v;
  N->left=l;
  N->right=r;
  return N;
}
treetype Add_Left(treetype *Tree, elementtype NewData)
{
  node_type *NewNode=makeNewNode(NewData);
  if(NewNode == NULL) return (NewNode);
  if(*Tree == NULL)
    *Tree = NewNode;
  else
    {
      node_type *Lnode = *Tree;
      while(Lnode->left != NULL)
	Lnode = Lnode -> left;
      Lnode ->left=NewNode;
    }
  return (NewNode);
}
treetype Add_Right(treetype *Tree, elementtype NewData)
{
  node_type *NewNode=makeNewNode(NewData);
  if(NewNode == NULL)return(NewNode);
  if(*Tree == NULL)
    *Tree = NewNode;
  else
    {
      node_type *Rnode = *Tree;
      while(Rnode->right != NULL)
	Rnode = Rnode -> right;
      Rnode->right=NewNode;
    }
  return (NewNode);
}
void inorderprint(treetype tree)
{
  if(tree!=NULL)
    {
      inorderprint(tree->left);
      printf("%c",tree->element);
      inorderprint(tree->right);
    }
}
void inorderprintpro(treetype tree)
{
  if(tree->left!=NULL)
    {
      printf("(");
      inorderprintpro(tree->left);
    }
   printf("%c",tree->element);
   if(tree->right!=NULL)
     {
      inorderprintpro(tree->right);
       printf(")");
    }
}
void preorderprint(treetype tree)
{
  if(tree!=NULL)
    {
      printf("%c",tree->element);
      preorderprint(tree->left);
      preorderprint(tree->right);
    }
}
void postorderprint(treetype tree)
{
  if(tree!=NULL)
    {
      postorderprint(tree->left);
      postorderprint(tree->right);
      printf("%c",tree->element);
    }
}
int HeightTree(treetype root)
{
  if(root == NULL) return 0;
  else
    {
      int lHeight = HeightTree(root-> left);
      int rHeight = HeightTree(root-> right);
      if(lHeight > rHeight)
	return(lHeight+1);
      else
	return(rHeight+1);
    }
}
int NumberLeafs(treetype root)
{
if(root == NULL) return 0;
  else
    {
      if(root->left==NULL && root->right==NULL) return 1;
      else
	return NumberLeafs(root->left)+NumberLeafs(root->right);
    }
}
int InternalNode(treetype root)
{
if(root == NULL) return 0;
  else
    {
      if(root->left!=NULL || root->right!=NULL) 
	return InternalNode(root->left) + InternalNode(root->right) + 1;
    }
}
int NumberRightChildren(treetype root)
{
if(root == NULL) return 0;
  else
    {
       return NumberRightChildren(root->right) + 1;
    }
}
int main()
{
  treetype T;
  MakeNullTree(&T);
  node_type *T1,*T2,*t11,*t12,*t21,*t22;
  T1=makeNewNode('*');
 t11= Add_Right(&T1,'4');
  t12=Add_Left(&T1,'2');
  T2=makeNewNode('*');
   t21=Add_Right(&T2,'2');
   t22=Add_Left(&T2,'3');
   T=createfrom2('+',T1, T2);
   inorderprint(T);
   printf("\n");
   inorderprintpro(T);
   printf("\n");
   preorderprint(T);
   printf("\n");
   postorderprint(T);
   printf("\n");
   printf("Chieu cao cua cay: %d\n",HeightTree(T));
   printf("So nut la tren cay: %d\n",NumberLeafs(T));
   printf("so nut trong cua cay: %d\n",InternalNode(T));
   printf("So nut con ben trai:%d\n",NumberRightChildren(T));
  return 0;
}
