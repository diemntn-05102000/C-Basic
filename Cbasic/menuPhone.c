#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char model[15];
	char ram[10];
	char kichthuoc[10];
	char gia[10];
}DT;
#define max 81
int soluong=0;
void in(DT *s)
{
	printf("%-15s%-10s%-19s%s\n",s->model,s->ram,s->kichthuoc,s->gia );
}
void chuyen(FILE *fptr1,FILE *fptr2)
{
	DT *member=(DT*)malloc(sizeof(DT));
	while(!feof(fptr1))
	{
		/*fscanf(fptr1,"%s",member->model);
		fscanf(fptr1,"%s",member->ram);
		fscanf(fptr1,"%s",member->kichthuoc);
		fscanf(fptr1,"%s",member->gia);
		*/
		fscanf(fptr1,"%s %s %s %s",member->model,member->ram,member->kichthuoc,member->gia);
		fwrite(member,sizeof(DT),1,fptr2);
		soluong++;
	}
	printf("%d\n",soluong);
	free(member);
	printf("Thanh cong\n");
}

void InAll(FILE *f)
{
  DT *s=(DT *)malloc(sizeof(DT));
  printf("-------------DANH SACH------------\n");
  printf("%-15s%-10s%-10s%-10s\n","Model","Memory","Sign","Gia");
  while(!feof(f))
  {
    int n=fread(s,sizeof(DT),1,f);
    if(n==1) in(s);
  }
  free(s);
  }

void InAllPage(FILE *f)
{
	DT *s=(DT*)malloc(sizeof(DT));
	printf("-------------DANH SACH------------\n");
 	printf("%-15s%-10s%-10s%-10s\n","Model","Memory","Sign","Gia");
 	int i=0;
 	while(!feof(f))
 	{
 		int n=fread(s,sizeof(DT),1,f);
 		if (n==1)
 		{
 			in(s);
 			i++;
 		}
 		if (i==24)	
 		{
 			printf("Press enter to next page\n");
 			getchar();
 			i=0;
 		}

 	}
 	free(s);
}
  /*void InAllPage(FILE *f)
{
  DT *s=(DT *)malloc(sizeof(DT));
  printf("-------------DANH SACH------------\n");
  printf("%-15s%-10s%-10s%-10s\n","Model","Memory","Sign","Gia");
  int i=0;
  while(!feof(f))
  {
    int n=fread(s,sizeof(DT),1,f);
    if(n==1) 
    {
      in(s);
      i++;
    }
    if(i==24) 
    {
      printf("----------> An enter de chuyen tiep sang trang khac");
      getchar();
      i=0;
    }
  }
  free(s);
}
*/
void InYc(FILE *f)
{
	DT *s=(DT*)malloc(sizeof(DT));
	int n,N;
	printf("so phan tu ban muon doc:\n");
	scanf("%d%*c",&n);
	while(n<0 || n>soluong)
	{
		printf("Nhap lai\n");
		scanf("%d%*c",&n);
	}
	printf("Moi ban chon vi tri doc: \n");
    printf("1. Doc tu dau file\n2. Doc tu cuoi file\nPhim khac : Thoat\n");
    printf("Ban chon: ");
    scanf("%d%*c",&N);
	printf("-------------DANH SACH------------\n");
    printf("%-15s%-10s%-10s%-10s\n","Model","Memory","Sign","Gia");
    if(N==1)
    {
    	rewind(f);
    	for (int i = 0; i < n; i++)
    	{
    		int n=fread(s,sizeof(DT),1,f);
    		if (n==1)
    		{
    			in(s);
    		}
    	}
    }
    else if (N==2)
    {
    	rewind(f);
    	fseek(f,sizeof(DT)*(soluong-n+1),SEEK_SET);
    	for (int i = 0; i < n; i++)
    	{
    		int n=fread(s,sizeof(DT),1,f);
    		if (n==1)
    		{
    			in(s);
    		}
    	}
    }
}
void search(FILE *f)
{
	char b[max];
	printf("nhap model ban muon tim:\n");
	gets(b);
	int a;
	DT *member=(DT*)malloc(sizeof(DT));
	while(!feof(f))
	{
		fread(member,sizeof(DT),1,f);
		if (strcmp(b,member->model)==0)
		{
			a=1;
			break;
		}
	}
	if (a==1)
	{	
		printf("-------------DANH SACH------------\n");
    	printf("%-15s%-10s%-10s%-10s\n","Model","Memory","Sign","Gia");
		in(member);
	}

}
enum{success,fail};
int main(int argc,char *argv[])
{
	if (argc!=3)
	{
		printf("sai cu phap\n");
		printf("cu phap chinh xac: hello filename1 filename2");
		return 1;
	}
	FILE *fptr1,*fptr2;
	fptr1=fopen(argv[1],"r");
	fptr2=fopen(argv[2],"wb");
	int n,x;
	int reval=success;
	if (fptr1==NULL)
	{
		printf("error\n");
		reval=fail;
	}
	if (fptr2==NULL)
	{
		printf("error\n");
		reval=fail;
	}
	do
	{
		printf("----------MENU------------\n");
		printf("1.Import DB from text\n");
		printf("2.Import from DB\n");
		printf("3.printf all database\n");
		printf("4.Find model\n");
		printf("5.Exit\n");
		printf("your choice\n");
		scanf("%d%*c",&n);
		switch(n)
		{
			case 1:
			chuyen(fptr1,fptr2);
			fclose(fptr2);
			break;
			case 2:
			fptr2=fopen(argv[2],"rb");
			if (fptr2==NULL)
			{
				printf("Cannot open file %s\n",argv[2]);
				reval=fail;
			}
			printf("Moi chon chon che do Import \n");
     		printf("1.All\n2.Theo so luong\nPhim khac : Thoat\n");
      		printf("Moi ban chon: ");
      		int b;
      		scanf("%d%*c",&b);
      		if(b==1) InAll(fptr2);
      		if(b==2) InYc(fptr2);
      break;
			break;
		
			case 3:
			{
				fptr2=fopen(argv[2],"rb");
				InAllPage(fptr2);
				printf("hello\n");
				fclose(fptr2);
				break;
			}
			case 4:
			{
				fptr2=fopen(argv[2],"rb");
				search(fptr2);
				break;
			}
			case 5:
			{
				break;
			}
	}
	} while (n!=5);
}