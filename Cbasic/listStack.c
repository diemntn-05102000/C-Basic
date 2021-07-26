#include "listStack.h"
#include <stdio.h>
int main()
{
  int a,b,c;
  printf("nhap list:");
  scanf("%d%d%d",&a,&b,&c);
  push(a);
  push(b);
  push(c);
  printf("Pop stack:")
    while(!empty())
      printf("%d\n",pop());
  return 0;
}
