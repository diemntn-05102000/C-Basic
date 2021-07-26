#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phone_t
{
        char model[15];
	char ram[10];
	char kichthuoc[10];
	char gia[15];
}DT;
typedef struct Node
{
  DT key;
  struct Node* left,*right;
  
}NodeType;
typedef NodeType* TreeType;
TreeType Search(char x[15],TreeType Root)
{
  if(Root == NULL)return NULL;
  else if (strcmp((Root->key).model, x)==0)
    return Root;
  else if(strcmp((Root->key).model, x)<0)
    return Search(x, Root->right);
  else
    {
      return Search(x, Root->left);
    }
}
void InsertNode(DT x, TreeType *Root)
{
  if(*Root==NULL)
    {
      *Root=(NodeType*)malloc(sizeof(NodeType));
      (*Root)->key =x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if (strcmp(((*Root)->key).model, x.model)>0)return InsertNode(x,& (*Root)->left);
  else if (strcmp(((*Root)->key).model, x.model)<0)return InsertNode(x,& (*Root)->right);
}
void InOrderPrint(TreeType root)
{
if(root!=NULL)
    {
      InOrderPrint(root->left);
      printf("%-25s%-5s%-10s%-15s\n ",(root->key).model,(root->key).ram,(root->key).kichthuoc,(root->key).gia);
      InOrderPrint(root->right);
    }
}
void CapNhapGia(char x[15],TreeType *Root)
{
  char cng[15];
  if(*Root == NULL) printf("Khong tim thay model\n");
 else if (strcmp(((*Root)->key).model, x)==0)
   {
     printf("Nhap gia tien muon cap nhap:");
     gets(cng);
     strcpy(((*Root)->key).gia,cng);
   }
 else if(strcmp(((*Root)->key).model, x)>0) CapNhapGia(x,&(*Root)->left);
 else if(strcmp(((*Root)->key).model, x)<0) CapNhapGia(x,&(*Root)->right);
}
DT DeleteMin(TreeType *Root)
{
  DT k;
  if((*Root)->left == NULL)
    {
      k=(*Root)->key;
      (*Root) = (*Root)->right;
      return k;
    }
  else return DeleteMin(&(*Root)->left);
}
void DeleteNode(char x[15],TreeType *Root)
{
  if(*Root!=NULL)
    {
    if(strcmp(((*Root)->key).model, x)>0) DeleteNode(x,&(*Root)->left);
    else if(strcmp(((*Root)->key).model, x)<0) DeleteNode(x,&(*Root)->right);
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
  DT p[30],them;
  int i=0;
  char phone[15],xoa[15],cn[15];
  TreeType root=NULL,r;
  FILE *f;
  f=fopen("PhoneDB.dat","rb");
  if(f==NULL)
    {
    printf("Cannot open file\n");
    return 0;
    }
    fread(p,sizeof(p),4,f);
	for (int i = 0; i < 4; i++)
	  {
     //printf("%-25s%-5s%-10s%-15s\n",p[i].model,p[i].ram,p[i].kichthuoc,p[i].gia);
      InsertNode(p[i], &root);
     
	  }
  InOrderPrint(root);
   printf("Nhap model can tim:");
   gets(phone);
  if(Search(phone,root)!=NULL )
    {
      printf("Tim thay!!!\n");
      r=Search(phone,root);
      printf("%-25s%-5s%-10s%-15s\n ",(r->key).model,(r->key).ram,(r->key).kichthuoc,(r->key).gia);
    }
  else printf("Khong co model nay!!!\n");
  printf("Nhap model muon xoa:");
  gets(xoa);
  DeleteNode(xoa,&root);
  InOrderPrint(root);
  printf("Nhap them :\n");
  printf("Nhap model:");
  gets(them.model);
 printf("Nhap ram:");
 gets(them.ram);
 printf("Nhap kich thuoc:");
 gets(them.kichthuoc);
 printf("Nhap gia:");
 gets(them.gia);
 InsertNode(them, &root);
 InOrderPrint(root);
 printf("Cap nhap gia!!!");
 printf("Nhap model can cap nhap:");
 gets(cn);
 CapNhapGia(cn,&root);
 InOrderPrint(root);
 fclose(f);
 FreeTree(root);
  printf("Free success\n");
  return 0;
}
