#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleListQueue.h"
int main()
{
  elementtype X1,X2,X3;
  printf("Nhap queue:\n");
  X1=ReadNode(X1);
  enqueue(X1);
  X2=ReadNode(X2);
  enqueue(X2);
  X3=ReadNode(X3);
  enqueue(X3);
  printf("Dequeue:\n");
  node *p=dequeue();
  DisplayNode(p);
  DisplayNode(dequeue());
  return 0;
}

