#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct{
  char stt[81];
  char mssv[81];
  char hoten[81];
  char sdt[81];
  float diem;
}std;
enum{success,fail};
int main(void)
{
	int n,irc,igc,m;
	char filename1[]="bangdiem.txt";
	char filename2[]="grade.dat";
	int reval=success;
	FILE *fptr1,*fptr2;
	fptr1=fopen(filename1,"rb");
	float diemsua;
	char c;
	int k=1;
	int i=0;
	char kiemtra[81];
	if (fptr1==NULL)
	{
		printf("Cannot open file %s\n",filename1);
		reval=fail;
	}
	c=fgetc(fptr1);
	while(!feof(fptr1))
    {	if (c=='\n')
		{
			k++;
		}
		c=fgetc(fptr1);
	}
	printf("%d\n",k);
	rewind(fptr1);

	std *sv;
	sv=(std *)malloc(k*sizeof(std));
		do
	{
		printf("-------MENU--------\n");
		printf("1.Text2DAt\n");
		printf("2. Display Dat file\n");
		printf("3.Search and update\n");
		printf("4.Exit\n");
		printf("Lua chon cua ban la:\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
			{

    		while(!feof(fptr1))
    		{
    	fscanf(fptr1,"%5s%11s%30s%13s%f\n",(sv + i)->stt, (sv + i)->mssv, (sv + i)->hoten, (sv + i)->sdt,&((sv+i-1)->diem));
    	++i;
    		}
    		if ((fptr2=fopen("grade.dat","w+b"))==NULL)
    		{
    			printf("cannot open file %s\n",filename2);
    			reval=fail;
    		}
 			irc=fwrite(sv,sizeof(std),k,fptr2);
 			printf("%d\n",irc);

 			
			break;
			}
			case 2:
			{
				
				igc=fread(sv,sizeof(std),k,fptr2);
				
				for (int i = 0; i < k; i++)
				{
				        printf("%s-",(sv+i)->stt);
					printf("%s-",(sv+i)->hoten);
				
					printf("%s-",(sv+i)->mssv);
					printf("%s-",(sv+i)->sdt);
					printf("%0.3f\n",(sv+i)->diem);

				}
				break;
			}
			case 3:
			{
				 printf("MSSV ban muon xem xet:\n");
				 scanf("%s[^\n]",kiemtra);
				 for (int i = 0; i < k; i++)
				 {
				 	if (strcmp(kiemtra,(sv+i)->mssv)==0)
				 	{
				 	igc=fread(sv+i,sizeof(std),k,fptr2);
					printf("%s-",(sv+i)->hoten);
					printf("%s-",(sv+i)->stt);
					printf("%s-",(sv+i)->mssv);
					printf("%s-",(sv+i)->sdt);
					printf("%0.3f\n",(sv+i)->diem);
				 	
				 
				 do
				 {
				 	printf("Sua diem cua sinh vien nay khong :p \n");
				 	printf("1.Sua\n");
				 	printf("2.Exit\n");
				 	printf("you want:\n");
				 	scanf("%d",&m);
				 	switch (m)
				 	{
				 	case 1:
				 	{
				 		printf("Diem so ban muon sua thanh la:\n");
				 		scanf("%f",&diemsua);
				 		(sv+i)->diem=diemsua;
				 		irc=fwrite(sv+i,sizeof(std),1,fptr2);
				 		break;

				 	}
				 	case 2:
				 	break;
				 	}
				
				 } while (m!=2);
				}
			}
			break;
		}
			case 4:
			{
				break;
			}
			free(sv);
		}

	}while (n!=4);
	fclose(fptr1);
	fclose(fptr2);
	return reval;
}
