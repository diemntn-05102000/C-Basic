#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,S=0;
  int *A;
  FILE *f;
  f = fopen("out.txt","w");
   if(f == NULL)
    {
      printf("cannot open!\n");
      return 1;
    }
  printf("Nhap vao so phan tu: ");
  scanf("%d",&n);
  //f = (FILE*)malloc(n*sizeof(int));
  if(f == NULL)
    {
      printf("memory failed!\n");
      return 1;
    }
  printf("Nhap day so:");
  for(int i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
      fprintf(f,"%d ",A[i]);
      S += A[i];
    }
  fprintf(f,"%d",S);
  printf("success\n");
  free(f);
  fclose(f);
  return 0;
}
