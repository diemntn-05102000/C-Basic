#include <stdio.h>
enum {SUCCESS,FAIL};
int main()
{
  FILE *lab,*lab1w;
 
  int reval = SUCCESS;
  if((lab = fopen("lab.txt","r"))==NULL)
    {
      printf("canot open %s.\n","lab.txt");
      reval = FAIL;
    }
  else if((lab1w = fopen("lab1w.txt","w"))==NULL)
    {
      printf("canot open %s.\n","lab1w.txt");
      reval = FAIL;
    }else{
    int c;
    while ((c=fgetc(lab)) != EOF)
      {
	fputc(c, lab1w);


	if(c == '\n')
        fputc('\n', lab1w);

	putchar(c);
	
	
      }
    fclose(lab);
    fclose(lab1w);
  }
  return reval;
}
