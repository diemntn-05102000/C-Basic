#include "arrayQueue.h"
#include <stdio.h>
int main()
{
  int a[10]={3,5,2,7,9,4,5,1,2,9};
  int i;
  Queue s;
  MakeNull_Queue(&s);
  
  for( i=0;i<10;i++)
    {
      EnQueue(a[i],&s);
      
    }
  printf("Pop all element in stack!\n");
    while(!Empty_Queue(s))
      printf("%4d\n",DeQueue(&s));
  return 0;
}
