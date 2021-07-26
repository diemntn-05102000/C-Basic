#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char STT[2];
	char tenmon[15];
	char soluong[3];
	char gia[10];
}thucdon;

int main()
{
  thucdon Menu[10],tmp;
  int i;
  FILE *f;
  f=fopen("thucdontheongay.txt","r");
      if (f==NULL)
	{
		printf("error\n");
		return 0;
	}
  while(!feof(f))
	{
	  fscanf(f,"%s %s %s %s",Menu[i].STT,Menu[i].tenmon,Menu[i].soluong,Menu[i].gia);
		i++;
	}
  for(int a=0;a<i-1;a++)
    {
      printf("%s %-15s %-5s %-10s\n",Menu[a].STT,Menu[a].tenmon,Menu[a].soluong,Menu[a].gia);
    }
  for(int a =1; a<i-1;a++)
    for(int b =0; b<i-1-a;b++)
      {
	if(strcmp(Menu[b].tenmon,Menu[b+1].tenmon)>0)
	  {
	    tmp=Menu[b];
	    Menu[b]=Menu[b+1];
            Menu[b+1]=tmp;
	  }
      }
  printf("sau khi sx theo ten mon an:\n");
  for(int b=0;b<i-1;b++)
    {
      printf("%s %-15s %-5s %-10s\n",Menu[b].STT,Menu[b].tenmon,Menu[b].soluong,Menu[b].gia);
      }
  fclose(f);
  return 0;
}
