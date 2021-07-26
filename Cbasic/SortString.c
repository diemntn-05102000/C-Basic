#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void quicksortstring(char a[][10],int left,int right)
{
  int i, j;
  char *pivot;
  char tmp[10];
  if(left<right)
    {
      i = left;
      j = right;
      //pivot=a[(left+right)/2];
      pivot = a[left];
      do
	{
	  while (strcmp(a[i],pivot)<0 && (i <right))
	     i++;
	  while (strcmp(a[j],pivot)>0 && (j>left))
	    j--;
	  if(i<=j)
	    {
	      strcpy(tmp,a[i]);
	      strcpy(a[i],a[j]);
	      strcpy(a[j],tmp);
	      i++;
	      j--;
	    } 
	} while(i<=j);
      if(left < j)
	quicksortstring(a, left,j);
      if(i < right)
	quicksortstring(a,i,right);
    }
}
void quicksortmain(char a[][10],int count)
{
  quicksortstring(a,0,count-1);
}
int main()
{
  char str[][10] = {"this","is","a","hat"};
  for(int i=0; i<4; i++)
    {
      printf("%s ",str[i]);
    }
  printf("\n");
  quicksortmain( str,4);
  printf("After sort:\n");
  for(int i=0; i<4; i++)
    {
      printf("%s ",str[i]);
    }
  printf("\n");
  return 0;
}
