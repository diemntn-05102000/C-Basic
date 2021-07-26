#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
 char anh[25];
  char viet[25];
}tudien;
typedef struct Node
{
  tudien key;
  struct Node* left,*right;
  
}NodeType;
typedef NodeType* TreeType;
void InsertNode(tudien x, TreeType *Root)
{
  if(*Root==NULL)
    {
      *Root=(NodeType*)malloc(sizeof(NodeType));
      (*Root)->key =x;
      (*Root)->left=NULL;
      (*Root)->right=NULL;
    }
  else if (strcmp(((*Root)->key).anh, x.anh)>0)return InsertNode(x,& (*Root)->left);
  else if (strcmp(((*Root)->key).anh, x.anh)<0)return InsertNode(x,& (*Root)->right);
}
void InOrderPrint(TreeType root)
{
if(root!=NULL)
    {
      
      InOrderPrint(root->left);
      printf("%-25s%-25s\n ",(root->key).anh,(root->key).viet);
      InOrderPrint(root->right);
    }
}
void themsua(char x[25],TreeType *Root)
{
  char nghia[25];
  tudien them;
  char c;
  if(*Root == NULL)
    {
    printf("Khong co trong tu dien, cap nhap\n");
    printf("Nhap nghia cua tu:");
    scanf("%s",nghia);
    strcpy(them.anh,x);
    strcpy(them.viet,nghia);
    InsertNode(them,Root);
    }
 else if (strcmp(((*Root)->key).anh, x)==0)
   {
     printf("Co muon nhap noi dung moi khong:\n");
     scanf("%s",&c);
     if(c=='y')
       {
	 printf("Nhap nghia moi:");
	 scanf("%s",nghia);
	 strcpy(((*Root)->key).viet, nghia);
       }
     
   }
     
 else if(strcmp(((*Root)->key).anh, x)>0) themsua(x,&(*Root)->left);
 else if(strcmp(((*Root)->key).anh, x)<0) themsua(x,&(*Root)->right);
  
}
void tachcau(char cau[50])
{
  int i[10];
  int j=0;
  int a,tmp=0;
  for(int a=0;a< strlen(cau);a++)
    {
      if(cau[a]=' ')
	{
	  i[j]==a;
	  j++;
	}
    }
  for(int b=0;b<j;b++)
    {
      for(a=tmp;a< strlen(cau);a++)
	{
	  if(a!=i[b]) printf("%s",&cau[a]);
	  else
	    {
	      printf("\n");
	      tmp=a;
	      break;
	    }
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
int main()
{
  char cau[50];
  int i=0,n;
  TreeType Root=NULL;
  tudien TD[10];
  FILE *f;
  f=fopen("dict.txt","r");
      if (f==NULL)
	{
		printf("error\n");
		return 0;
	}
  while(!feof(f))
	{
	  fscanf(f,"%s %s",TD[i].anh,TD[i].viet);
		i++;
	}
  do
	{
		printf("-------MENU--------\n");
		printf("1.Nap tu dien\n");
		printf("2.Noi dung tu dien\n");
		printf("3.Them/Sua tu\n");
		printf("4.Dich cau Anh-Viet\n");
		printf("5.Exit\n");
		printf("Lua chon cua ban la:\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
			  {
			    for(int a=0; a< i-1; a++)
			      {
				InsertNode(TD[a],&Root);
				printf("%-25s%-25s\n",TD[a].anh,TD[a].viet);
			      }
			    printf("Success!\n");
                           break;
			}
		case 2:
		  {
		    InOrderPrint(Root);
		   
		    break;
		  }
		  case 3:
		  {
		    char tmp[25];
		    printf("Nhap tu muon them:");
		    scanf("%s",tmp);
		    themsua(tmp,&Root);
		     printf("Success\n");
		    break;
		  }
		  case 4:
		  {
		    
		    printf("Nhap vao cau:");
		    gets(cau);
		    tachcau(cau);
		    break;
		  }
		case 5:
		  {
		    FreeTree(Root);
                    return 0;
		  }
			
		}

	}while (n!=5);
  fclose(f);
  return 0;
}
