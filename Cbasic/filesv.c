#include <stdio.h>
#include<ctype.h>

enum{success,fail};

#define bibi 30
#define max 81

typedef struct {
	int stt;
	unsigned long int mssv;
	char name[bibi];
	char  sdt[bibi];
	int diem;
}pepe;

pepe id[bibi];

int main(int argc, char* argv[])
{
	FILE *fptr1,*fptr2;
	int reval=success;
	int i =0;

	if (argc!=3)
	{
		printf("you entered wrong form\n");
		printf("the right form is: hello file1 file2\n");
		return 1;
	}

	fptr1=fopen(argv[1],"r+");
	fptr2=fopen(argv[2],"w+");
	
	if(fptr1==NULL)
	{
		printf("Cannot open file %s\n",argv[1]);
		reval=fail;
	}
	if (fptr2==NULL)
	{
		printf("Cannot open file %s\n",argv[2]);
		reval=fail;
	}
	else
	{		
		while(!feof(fptr1))
		{
			fscanf(fptr1,"%d %lu %s %s\n",&id[i].stt,&id[i].mssv,id[i].name,id[i].sdt);
			printf("%d %lu %s %s\n",id[i].stt,id[i].mssv,id[i].name,id[i].sdt);
			printf("Enter the student's point: ");
			scanf("%d",&id[i].diem);
			
			fprintf(fptr2,"%d %lu %s %s %d\n",id[i].stt,id[i].mssv,id[i].name,id[i].sdt,id[i].diem);

			printf("Success\n");
			i++;
		}
	}
	fclose(fptr1);
	fclose(fptr2);
	return reval;
}
