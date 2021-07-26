#include <stdio.h>
void insertion_sort(int list[], int n)
{
  int i,j;
  int next;
  for(i=1;i<n; i++)
    {
      next=list[i];
      for(j=i-1;j>=0 && next< list[j];j--)
	list[j+1]=list[j];
      list[j+1]=next;
    }
}
void selection(int a[],int n)
{
  int i,j,min,tmp;
  for(i=0;i<n-1;i++)
    {
      min=i;
      for(j=i+1;j<=n-1;j++)
	{

	  if(a[j]<a[min]) min=j;
	  
	}
      tmp=a[i];
      a[i]=a[min];
      a[min]=tmp;
    }
}
void quicksort(int list[],int left,int right)
{
  int pivot, i, j;
  int temp;
  if(left<right)
    {
      i = left;
      j = right+1;
      pivot = list[left];
      do
	{
	  do i++; while (list[i]<pivot);
	  do j--; while (list[j]>pivot);
	  if(i<j)
	    {
	      temp=list[i];
	      list[i]=list[j];
	      list[j]=temp;
	    } 
	} while(i<j);
        temp=list[left];
        list[left]=list[j];
        list[j]=temp;
	quicksort(list, left,j-1);
	quicksort(list,j+1,right);
    }
}
void mergesort(int U[],int V[],int E[],int n, int m)
{
  int i,j,k;
  i=0;j=0;k=0;
  while(i<n && j<m)
    {
      if(U[i]<V[j])
	{
	  E[k]=U[i];
	  i++;
	}
      else
	{
	  E[k]=V[j];
	  j++;
	}
      k++;
    }
  
  if(i<n)
    {
    while(i<n)
      {
          E[k]=U[i];
	  i++;
	  k++;
      }
    }
  else
    if(j<m)
      {
        while(j<m)
         {
          E[k]=V[j];
	  j++;
	  k++;
         }
      }
} 
int main()
{
  int list1[10]={23,34,12,36,3,69,56,45,65,99};
  int list2[5]={30,13,47,67,87};
  int E[15];
  int n=10,a,m=5;
  printf("Truoc khi sx:\n");
  for(int i=0;i<n;i++)
    printf("%d ",list1[i]);
  printf("\n");
  for(int i=0;i<m;i++)
    printf("%d ",list2[i]);
  printf("\n");
  printf("Sau khi sx bang insertion sort:\n");
  insertion_sort(list1,n);
  for(a=0;a<n;a++)
    printf("%d ",list1[a]);
  printf("\n");
  insertion_sort(list2,m);
  for(a=0;a<m;a++)
    printf("%d ",list2[a]);
  printf("\n");
  /*printf("Sau khi sx bang selection:\n");
  selection(list,n);
  for(a=0;a<n;a++)
    printf("%d ",list[a]);
    printf("\n");
  int left=0,right=n-1;
  quicksort(list,left,right);
  printf("Sau khi sx bang quick sort:\n");
  for(int i=0;i<n;i++)
    printf("%d ",list[i]);
    printf("\n");*/
  printf("Sau khi sd merge sort:\n");
  mergesort(list1,list2,E,n, m);
    for(a=0;a<n+m;a++)
    printf("%d ",E[a]);
    printf("\n");
  return 0;
}
