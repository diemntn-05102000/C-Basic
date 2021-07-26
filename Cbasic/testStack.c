#include "stackarr.h"
#include <stdio.h>
int main()
{
  int a[10]={3,5,2,7,9,4,5,1,2,9};
  int i;
  StackType s;
  Initialize(s);
  
  for( i=0;i<10;i++)
    {
      push(a[i],s);
      
    }
  printf("Pop all element in stack!\n");
    while(!empty(s))
      printf("%4d\n",pop(s));
  return 0;
}
