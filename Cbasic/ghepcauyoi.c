#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main (void)
{
  srand(time(NULL));
  char *article[] = {"the","a","one","some","any"};
  char *noun[] = {"boy","girl","dog","town","car"};
  char *verb[] = {"drove","jumped","ran","walked","skipped"};
  char *preposition[] = {"to","from","over","under","on"};
  char sentence[60]="";
  int n;
  printf("Nhap so cau: ");
  scanf("%d",&n);
  for(int i=0; i<n ; i++)
    {
      strcat(sentence,article[rand()%5]);
	strcat(sentence," ");
      sentence[0] = toupper(sentence[0]);
      strcat(sentence,noun[rand()%5]);
	strcat(sentence," ");
        strcat(sentence,verb[rand()%5]);
	strcat(sentence," ");
	strcat(sentence,preposition[rand()%5]);
	strcat(sentence," ");
	strcat(sentence,article[rand()%5]);
	strcat(sentence," ");
	strcat(sentence,noun[rand()%5]);
	strcat(sentence," ");
	   printf("%s\n",sentence);
	   sentence[0] ='\0';
    }
  return 0;
}
