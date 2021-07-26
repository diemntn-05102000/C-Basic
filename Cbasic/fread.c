#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  enum {MAX_LEN = 80,FAIL,SUCCESS};
  int num,reval=SUCCESS;
  FILE *fptr2;
  char filename2[]= "a2.txt";
  char buff[MAX_LEN+1];
  if((fptr2 = fopen(filename2,"r"))==NULL)
    {
      printf("Cannot open %s.\n",filename2);
      reval = FAIL;exit(1);
    }
  else
    {
  num = fread(buff, sizeof(char), MAX_LEN, fptr2);
  buff[num * sizeof(char)] = '\0';
  printf("%s",buff);
    }
  fclose(fptr2);
  return reval;
}
