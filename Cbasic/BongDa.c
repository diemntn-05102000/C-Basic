#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
  char Madoibong1[10];
  char Madoibong2[10];
  int tiso1;
  int tiso2;
}BD;
typedef struct 
{
  char Madoibong[10];
  int Ketqua;
}KQ;
typedef struct Node
{
   KQ key;
  struct Node* left,*right;
  
}NodeType;
typedef NodeType* TreeType;
int d=1;
void InsertNode(char x[10], TreeType *Root,int diem)
{
      
      *Root=(NodeType*)malloc(sizeof(NodeType));
      strcpy(((*Root)->key).Madoibong ,x);
     ((*Root)->key).Ketqua+=diem;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
      printf("Nut thu %d\n",d);
      d++;
      //printf("Dia chi %s\n",&(*Root));
}
void CapNhapDiem(char x[10],TreeType *Root,int diem)
{
  
  if(*Root == NULL)
    {
      
      InsertNode(x,Root,diem);
    }
 else if (strcmp(((*Root)->key).Madoibong, x)==0)
   {
     ((*Root)->key).Ketqua+=diem;
     
   }
 else if(strcmp(((*Root)->key).Madoibong, x)>0) CapNhapDiem(x,&(*Root)->left,diem);
 else if(strcmp(((*Root)->key).Madoibong, x)<0) CapNhapDiem(x,&(*Root)->right,diem);
}
void InOrderPrint(TreeType root)
{
if(root!=NULL)
    {
      InOrderPrint(root->left);
      printf("%-25s%-5d\n ",(root->key).Madoibong,(root->key).Ketqua);
      InOrderPrint(root->right);
    }
}
TreeType Search(char x[10],TreeType Root)
{
  if(Root == NULL)return NULL ;
  else if (strcmp((Root->key).Madoibong, x)==0)
    return Root;
  else if(strcmp((Root->key).Madoibong, x)<0)
    return Search(x, Root->right);
  else
    {
      return Search(x, Root->left);
    }
}
/*KQ DeleteMin(TreeType *Root)
{
  KQ k;
  if((*Root)->left == NULL)
    {
      k=(*Root)->key;
      (*Root) = (*Root)->right;
      return k;
    }
  else return DeleteMin(&(*Root)->left);
}
void DeleteNode(char x[10],TreeType *Root)
{
  if(*Root!=NULL)
    {
    if(strcmp(((*Root)->key).Madoibong, x)>0) DeleteNode(x,&(*Root)->left);
    else if(strcmp(((*Root)->key).Madoibong, x)<0) DeleteNode(x,&(*Root)->right);
    else if((*Root)->left==NULL&&(*Root)->left==NULL) *Root=NULL;
    else if((*Root)->left==NULL)
    *Root=(*Root)->right;
    else if((*Root)->right==NULL)
    *Root=(*Root)->left;
    else (*Root)->key = DeleteMin(&(*Root)->right);
  
    }			 
    }
void XuongHang(int x, TreeType *Root,KQ XH[],int xh)
{
while(*Root!=NULL)
{
  if(((*Root)->key).Ketqua<x)
  {
    printf("S\n");
    XH[xh]=(*Root)->key;
    xh++;
    //DeleteNode(((*Root)->key).Madoibong,Root);
  }
 else
   *Root=(*Root)->left;
}
}*/
void XuatFile(FILE *f1,TreeType root)
{
if(root!=NULL)
    {
      XuatFile(f1,root->left);
      fprintf(f1,"%s %d\n ",(root->key).Madoibong,(root->key).Ketqua);
      XuatFile(f1,root->right);
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
  TreeType Root=NULL;
  BD TiSo[10],tmp;
  char ma[15];
  int i=0;
  int n;
  FILE *f;
  f=fopen("BongDa.txt","r");
      if (f==NULL)
	{
		printf("error\n");
		return 0;
	}
  while(!feof(f))
	{
	  fscanf(f,"%s %s %d %d",TiSo[i].Madoibong1,TiSo[i].Madoibong2,&(TiSo[i].tiso1),&(TiSo[i].tiso2));
		i++;
	}
  do
	{
		printf("-------MENU--------\n");
		printf("1.Tao cay\n");
		printf("2.Hien thi ket qua\n");
		printf("3.Tim kiem\n");
		printf("4.Xuong hang\n");
		printf("5.Xuat file\n");
		printf("6.Exit\n");
		printf("Lua chon cua ban la:\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
			{
  for(int a=0;a<i-1;a++)
    {
      printf("%-10s %-10s %-5d %-5d\n",TiSo[a].Madoibong1,TiSo[a].Madoibong2,TiSo[a].tiso1,TiSo[a].tiso2);
      if(TiSo[a].tiso1 > TiSo[a].tiso2)
	{
	  
	  CapNhapDiem(TiSo[a].Madoibong1,&Root,3);
	  
	  CapNhapDiem(TiSo[a].Madoibong2,&Root,0);
	}
      if(TiSo[a].tiso1 < TiSo[a].tiso2)
	{
          CapNhapDiem(TiSo[a].Madoibong2,&Root,3);
	  CapNhapDiem(TiSo[a].Madoibong1,&Root,0);
	}
      if(TiSo[a].tiso1 == TiSo[a].tiso2)
	{
          CapNhapDiem(TiSo[a].Madoibong1,&Root,1);
	  CapNhapDiem(TiSo[a].Madoibong2,&Root,1);
	}
      
     }
  break;
			}
		case 2:
		  {
		     InOrderPrint(Root);
		    break;
		  }
		  case 3:
		  {
		    TreeType r;
		    printf("Nhap ma doi bong can tim:");
		    scanf("%s",ma);
		    if(Search(ma,Root)==NULL)
		      printf("Khong tim thay!!!\n");
		    else
		      {
                      printf("Tim thay!!!\n");
                      r=Search(ma,Root);
		      printf("%-25s%-5d\n ",(r->key).Madoibong,(r->key).Ketqua);
		      }
		    break;
		  }
		  case 4:
		  {
		    /* int x,xh=0;
		    KQ XH[10];
		    printf("Nhap diem so:");
		    scanf("%d",&x);
		    XuongHang(x,&Root,XH,xh);
		    printf("Doi xuong hang:\n");
		    for(int i=0;i<=xh;i++)
		      {
                         printf("%-25s%-5d\n ",XH[i].Madoibong,XH[i].Ketqua);
		      }
		    printf("Doi khong xuong hang!!!\n");
		    InOrderPrint(Root);*/
		    break;
		  }
		case 5:
		  {
		    FILE *f1;
                    f1=fopen("KetQua.txt","w+");
                     if (f1==NULL)
	                 {
	                	printf("error\n");
		                return 0;
	                  }
		     XuatFile(f1,Root);
		     fclose(f1);
		     printf("Success\n");
		    break;
		  }
		case 6:
		  {
		    FreeTree(Root);
                    return 0;
		  }
			
		}

	}while (n!=6);
  fclose(f);
  return 0;
}
