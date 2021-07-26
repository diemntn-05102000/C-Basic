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
typedef DT element;
void adjust(element list[],int root, int n)
{
  int child;
  element temp, rootkey;
  temp=list[root];
  rootkey = list[root];
  child=2*root;
  while(child <= n)
    {
      if((child < n) && (strcmp(list[child].model,list[child+1].model)<0))
	child++;
	 if(strcmp(rootkey.model,list[child].model)>0)break;
      else
	{
	  list[child/2] = list[child];
	  child *= 2;
	}
    }
  list[child/2] = temp;
}
void heapsort(element list[], int n)
{
  int i,j;
  element temp;
  for(i=n/2;i>0; i--)
    {
      adjust(list,i,n);
    }
  for(i=n-1;i>0; i--)
    {
      temp=list[1];
      list[1]=list[i+1];
      list[i+1]=temp;
      adjust(list,1,i);
    }
}
int main()
{
  DT p[30],them;
  int i=0;
  char phone[15],xoa[15],cn[15];
  FILE *f;
  f=fopen("PhoneDB.txt","r");
  if(f==NULL)
    {
    printf("Cannot open file\n");
    return 0;
    }
  while(!feof(f))
    {
      fscanf(f,"%s %s %s %s\n",p[i].model,p[i].ram,p[i].kichthuoc,p[i].gia);
      i++;
    }
  for(int a=1;a<i;a++)
    printf("%-20s %-5s %-10s %-10s\n",p[a].model,p[a].ram,p[a].kichthuoc,p[a].gia);
  heapsort(p,i-1);
  printf("\nAfter sort:\n\n");
   for(int a=1;a<i;a++)
    printf("%-20s %-5s %-10s %-10s\n",p[a].model,p[a].ram,p[a].kichthuoc,p[a].gia);
   fclose(f);
  return 0;
}
