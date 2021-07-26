#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DienThoai
{
	char model[15];
	char ram[10];
	char kichthuoc[10];
	char gia[15];
}DT;
 struct node_DT
{
  DT model;
  struct node_DT *next;
 };
   typedef struct node_DT node;
#define max 81
int soluong=0;
node *root,*cur,*prev;

node *makeNewNode(DT element)
{
  node *new = (node*)malloc(sizeof(node));
  new->model=element;
  new -> next =NULL;
  return new;
}
void insertAtHead(DT element)
{
  node *new = makeNewNode(element);
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

node *importFromText(FILE *fptr1)
{
  DT member[20];
	while(!feof(fptr1))
	  {
		fscanf(fptr1,"%s %s %s %s\n",member[soluong].model,member[soluong].ram,member[soluong].kichthuoc,member[soluong].gia);
		insertAtHead(member[soluong]);
		soluong++;
	}
	printf("%d\n",soluong);
	
	printf("Thanh cong\n");
	return root;
}
void insertAfCur(DT element)
{
  node *new = makeNewNode(element);
 
  if( root == NULL)
    {
      root = new;
      cur = root;
    }else{
    new ->next = cur -> next;
    cur->next = new;
    cur = cur->next;  
  }
}
node *importFromDat(FILE *fptr2)
{
  int a=0;
  DT DT;
while(fread(&DT,sizeof(DT),1,fptr2)==1)
	  {
     insertAfCur(DT);
     ++a;
	  }
 printf("%d\n",a);
 printf("Thanh cong!!!\n");
 return root;
}
void displayNode(node *p)
{
  if(p==NULL)
    {
      printf("Loi con tro\n");
      return;
    }
  DT tmp= p->model;
  printf("%-25s%-7s%-7s%-15s\n",tmp.model,tmp.ram,tmp.kichthuoc,tmp.gia);
}
void DisplayList()
{
  node *p;
  for(p=root; p!= NULL; p=p->next)
    displayNode(p);
}
void freeList()
{
  node *to_free = root;
  while(to_free != NULL)
    {
      root = root->next;
      free(to_free);
      to_free = root;
    }
}

void searchModel(node *root)
{
	char b[max];
	printf("nhap model ban muon tim:\n");
	scanf("%[^\n]s",b);
	
  node *p;
  DT tmp;
  for(p=root; p!= NULL; p=p->next)
	{
	  tmp = p->model;
	  if (strcmp(b,tmp.model)==0)
		{
		displayNode(p);
		}
	}
}
void searchUderPrice(node *root)
{
	char a[max];
	printf("nhap gia tien ban muon tim:\n");
	scanf("%[^\n]s",a);

  node *p;
  DT tmp;
  for(p=root; p!= NULL; p=p->next)
	{
	  tmp = p->model;
	  int m=atoi(a);
	  int n=atoi(tmp.gia);
	  if (n<=m)
		{
		displayNode(p);
		}
	}
}
void exportToDat(node *root,FILE *f)
{
  DT tmp[30];
  int i=0;
 node *p;
  for(p=root; p!= NULL; p=p->next)
	{
	  tmp[i] = p->model;
	  fwrite(&tmp[i],sizeof(DT),1,f);
	  i++;
	}
  printf("%d\n",i);
  printf("Thanh cong!!!");
}
node *insert(DT model)
{
  int v;
  int n;
  printf("Chon vi tri muon nhap:");
  scanf("%d",&v);
  printf("Chon che do:\n");
  printf("1.Before\n");
  printf("2.After\n");
  scanf("%d",&n);
  switch(n)
    {
  case(1):
    {
      int a=1;
   node *tmp;
  cur=root;
 node *new = makeNewNode(model);
 if(root==NULL)
   {
     root =new;
   }
 if(v==0)
   insertAtHead( model);
 while(cur != NULL && a!=v)
   {
     cur = cur->next;
     ++a;
   }
 if(a!=v)
   printf("Khong tim thay vi tri can chen!!!\n");
 else{
   tmp=root;
while(tmp != NULL && tmp->next !=cur && cur != NULL)
    tmp = tmp->next;
  prev = tmp;
  new ->next = cur;
    if(cur == root)
      {
	root = new;
      }
    else{
     
      prev->next =new;
    }
    cur = new;
}
 printf("Thanh cong!!!");
    }
break;
 case(2):
   {
   int a=1;
  cur=root;
 node *new = makeNewNode(model);
 if(root==NULL)
   {
     root =new;
   }
 if(v==0)
   printf("Khong co vi tri nay!!!\n");
 while(cur != NULL && a!=v)
   {
     cur = cur->next;
     ++a;
   }
 if(a!=v)
   printf("Khong tim thay vi tri can chen!!!\n");
 else{
new ->next = cur -> next;
    cur->next = new;
    cur = cur->next;
   }
 printf("Thanh cong!!!");
   }
break;
    }
  return root;
}
void DeleteNode(node *p)
{
  cur=root;
  if(p==root)
    {
      root=p->next;
      free(p);
      }
  else
    {
      cur=root;
  while(cur!=NULL&&cur->next!=p)
    {
      cur=cur->next;
    }
  cur->next=p->next;
  free(p);
    }
}
void SearchToFront(node *root)
{
char b[max];
	printf("nhap model ban muon tim:\n");
	scanf("%[^\n]s",b);
	
  node *p;
  DT tmp;
  for(p=root; p!= NULL; p=p->next){
	  tmp = p->model;
	  if (strcmp(b,tmp.model)==0)	{
		displayNode(p);
		printf("Search to front\n");
		//move to front
		DeleteNode(p);
		insertAtHead(tmp);	
	}
  }
}
void SearchTranspose(node *root)
{
char b[max];
	printf("nhap model ban muon tim:\n");
	scanf("%[^\n]s",b);
	
	node *p,*prev;
  
  DT tmp,t;
  for(p=root; p!= NULL; p=p->next){
	  tmp = p->model;
	  if (strcmp(b,tmp.model)==0)	{
		displayNode(p);
		printf("Search to Transpose\n");
	
		break;
	  }
  }
	  prev=root;
	   while(prev!=NULL && prev->next!=p){
             prev=prev->next;
           }
	   t=prev->model;
	   prev->model=p->model;
	   p->model=t;
  
}
int main()
{

  FILE *fptr1,*fptr2,*f;
	fptr1=fopen("PhoneDB.txt","r");
	fptr2=fopen("PhoneDB.dat","rb");
	f=fopen("phoneDB.dat","wb");
         if (f==NULL)
	{
		printf("error\n");
		return 0;
	}
	int n,x;
	if (fptr1==NULL)
	{
		printf("error\n");
		return 0;
	}
	if (fptr2==NULL)
	{
		printf("error\n");
		return 0;
	}
	do
	{
		printf("----------MENU------------\n");
		printf("1.Import from text\n");
		printf("2.Import from Dat\n");
		printf("3.Display list\n");
		printf("4.Search phone by model\n");
		printf("5.Search phone under price\n");
		printf("6.Export to Dat\n");
		printf("7.Manual Insertion\n");
		printf("8.Search to front\n");
		printf("9.Search Transpose\n");
		printf("10.Exit\n");
		printf("your choice:\n");
		scanf("%d%*c",&n);
		switch(n)
		{
			case 1:
			  importFromText(fptr1);
			break;
			case 2:
			  importFromDat(fptr2);
			break;
		
			case 3:
			
			  DisplayList();

		          break;
			
			case 4:
			
			  searchModel(root);
				break;
			
		case 5:
		  searchUderPrice(root);
		  break;
		case 6:
		  exportToDat(root,f);
		  break;
		case 7:
		{
		  DT model;
		  printf("Nhap model muon them:\n");
		  scanf("%s",model.model);
		   scanf("%s",model.ram);
		    scanf("%s",model.kichthuoc);
		     scanf("%s",model.gia);
		  insert(model);
		  }
		break;
		case 8:
		  {
		    SearchToFront(root);
		     DisplayList();
		     break;
		  }
		case 9:
		  {
		    SearchTranspose(root) ;
		    DisplayList();
		     break;
		  } 
			case 10:
			  {
				break;
			}
	}
	} while (n!=10);
	freeList();
	fclose(fptr1);
	fclose(fptr2);
	fclose(f);
	return 0;
}
