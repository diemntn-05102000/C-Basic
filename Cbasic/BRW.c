#include <stdio.h>
#include <stdlib.h>
enum {SUCCESS,FAIL,MAX_LEN = 81};
int main()
{
  FILE *lab,*lab1w;
 
  int reval = SUCCESS;
  if((lab = fopen("a1.txt","r"))==NULL)
    {
      printf("canot open %s.\n","a1.txt");
      reval = FAIL;
    }
  else if((lab1w = fopen("a2.txt","w"))==NULL)
    {
      printf("canot open %s.\n","a2.txt");
      reval = FAIL;
    }else{
    int num;
    char buff[MAX_LEN+1];
    while(!feof(lab))
      {
	num = fread(buff, sizeof(char), MAX_LEN, lab);
	buff[num*sizeof(char)]='\0';
	printf("%s",buff);
	fwrite(buff, sizeof(char), num, lab1w);
      }
    fclose(lab);
    fclose(lab1w);
  }
  return reval;
}
