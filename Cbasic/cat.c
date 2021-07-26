#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum {success,fail};
int main(int argc, char* argv[])
{
  FILE *f;
  int reval=success;
  while(argc!=2)
    {
      printf("wrong!\n");
      printf("correct:<file>\n");
      return 1;
    }
  f=fopen(argv[1],"rt");
  if(f==NULL)
    {
      printf("cannot open\n");
      reval=fail;
    }
  else
    {
      char c[81];
      while(fgets(c,81,f)!=NULL)
	{
	  fscanf(f,"%[^\n]",c);
	  for (int i=0;i<strlen(c);i++)
	    printf("%c",c[i]);
	  printf("\n");
	}
      fclose(f);
    }
  return 0;
}
